/** Copyright (C) 2017 European Spallation Source */

/** @file
 *  @brief A class for handling parameters.
 */


#include "ParameterHandler.h"
#include "Parameter.h"
#include <algorithm>
#include <map>
#include <typeinfo>

ParameterHandler::ParameterHandler(asynPortDriver *DriverPtr)
    : Driver(DriverPtr) {}

void ParameterHandler::registerParameter(ParameterBase *Param) {
  std::map<std::size_t, asynParamType> TypeMap{
      {typeid(Parameter<std::string>).hash_code(), asynParamOctet},
      {typeid(Parameter<epicsInt64>).hash_code(), asynParamInt64},
      {typeid(Parameter<epicsInt32>).hash_code(), asynParamInt32},
  };
  asynParamType ParameterType{TypeMap.at(typeid(*Param).hash_code())};
  int ParameterIndex;
  auto Result = Driver->createParam(Param->getParameterName().c_str(), ParameterType,
                      &ParameterIndex);
  KnownParameters[ParameterIndex] = Param;
  Param->registerRegistrar(this);
}

void ParameterHandler::updateDbValue(ParameterBase *ParamPtr) {
  if (Driver == nullptr) {
    return;
  }
  auto FoundParameter =
      std::find_if(KnownParameters.begin(), KnownParameters.end(),
                   [&](std::pair<int, ParameterBase *> Item) {
                     return Item.second == ParamPtr;
                   });
  if (FoundParameter == KnownParameters.end()) {
    return;
  }
  auto UsedIndex = FoundParameter->first;
  std::map<std::size_t, std::function<void()>> CallMap{
      {typeid(Parameter<std::string>).hash_code(),
       [&]() {
         Driver->setStringParam(
             UsedIndex,
             dynamic_cast<Parameter<std::string> *>(ParamPtr)->readValue());
       }},
      {typeid(Parameter<epicsInt64>).hash_code(),
       [&]() {
        Driver->setInteger64Param(
             UsedIndex,
             dynamic_cast<Parameter<epicsInt64> *>(ParamPtr)->readValue());
       }},
       {typeid(Parameter<epicsInt32>).hash_code(),
       [&]() {
         Driver->setIntegerParam(
             UsedIndex,
             dynamic_cast<Parameter<epicsInt32> *>(ParamPtr)->readValue());
       }},
  };
  CallMap.at(typeid(*ParamPtr).hash_code())();
}