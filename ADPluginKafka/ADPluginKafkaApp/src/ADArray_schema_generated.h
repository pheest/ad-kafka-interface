// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ADARRAYSCHEMA_H_
#define FLATBUFFERS_GENERATED_ADARRAYSCHEMA_H_

#include "flatbuffers/flatbuffers.h"

struct Attribute;
struct AttributeBuilder;

struct ADArray;
struct ADArrayBuilder;

enum DType {
  DType_int8 = 0,
  DType_uint8 = 1,
  DType_int16 = 2,
  DType_uint16 = 3,
  DType_int32 = 4,
  DType_uint32 = 5,
  DType_int64 = 6,
  DType_uint64 = 7,
  DType_float32 = 8,
  DType_float64 = 9,
  DType_c_string = 10,
  DType_MIN = DType_int8,
  DType_MAX = DType_c_string
};

inline const DType (&EnumValuesDType())[11] {
  static const DType values[] = {
    DType_int8,
    DType_uint8,
    DType_int16,
    DType_uint16,
    DType_int32,
    DType_uint32,
    DType_int64,
    DType_uint64,
    DType_float32,
    DType_float64,
    DType_c_string
  };
  return values;
}

inline const char * const *EnumNamesDType() {
  static const char * const names[12] = {
    "int8",
    "uint8",
    "int16",
    "uint16",
    "int32",
    "uint32",
    "int64",
    "uint64",
    "float32",
    "float64",
    "c_string",
    nullptr
  };
  return names;
}

inline const char *EnumNameDType(DType e) {
  if (flatbuffers::IsOutRange(e, DType_int8, DType_c_string)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesDType()[index];
}

struct Attribute FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AttributeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_DESCRIPTION = 6,
    VT_SOURCE = 8,
    VT_DATA_TYPE = 10,
    VT_DATA = 12
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::String *description() const {
    return GetPointer<const flatbuffers::String *>(VT_DESCRIPTION);
  }
  const flatbuffers::String *source() const {
    return GetPointer<const flatbuffers::String *>(VT_SOURCE);
  }
  DType data_type() const {
    return static_cast<DType>(GetField<int8_t>(VT_DATA_TYPE, 0));
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_DESCRIPTION) &&
           verifier.VerifyString(description()) &&
           VerifyOffset(verifier, VT_SOURCE) &&
           verifier.VerifyString(source()) &&
           VerifyField<int8_t>(verifier, VT_DATA_TYPE) &&
           VerifyOffsetRequired(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct AttributeBuilder {
  typedef Attribute Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Attribute::VT_NAME, name);
  }
  void add_description(flatbuffers::Offset<flatbuffers::String> description) {
    fbb_.AddOffset(Attribute::VT_DESCRIPTION, description);
  }
  void add_source(flatbuffers::Offset<flatbuffers::String> source) {
    fbb_.AddOffset(Attribute::VT_SOURCE, source);
  }
  void add_data_type(DType data_type) {
    fbb_.AddElement<int8_t>(Attribute::VT_DATA_TYPE, static_cast<int8_t>(data_type), 0);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(Attribute::VT_DATA, data);
  }
  explicit AttributeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Attribute> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Attribute>(end);
    fbb_.Required(o, Attribute::VT_NAME);
    fbb_.Required(o, Attribute::VT_DATA);
    return o;
  }
};

inline flatbuffers::Offset<Attribute> CreateAttribute(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::String> description = 0,
    flatbuffers::Offset<flatbuffers::String> source = 0,
    DType data_type = DType_int8,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  AttributeBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_source(source);
  builder_.add_description(description);
  builder_.add_name(name);
  builder_.add_data_type(data_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Attribute> CreateAttributeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const char *description = nullptr,
    const char *source = nullptr,
    DType data_type = DType_int8,
    const std::vector<uint8_t> *data = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto description__ = description ? _fbb.CreateString(description) : 0;
  auto source__ = source ? _fbb.CreateString(source) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return CreateAttribute(
      _fbb,
      name__,
      description__,
      source__,
      data_type,
      data__);
}

struct ADArray FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ADArrayBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SOURCE_NAME = 4,
    VT_ID = 6,
    VT_TIMESTAMP = 8,
    VT_DIMENSIONS = 10,
    VT_DATA_TYPE = 12,
    VT_DATA = 14,
    VT_ATTRIBUTES = 16
  };
  const flatbuffers::String *source_name() const {
    return GetPointer<const flatbuffers::String *>(VT_SOURCE_NAME);
  }
  int32_t id() const {
    return GetField<int32_t>(VT_ID, 0);
  }
  uint64_t timestamp() const {
    return GetField<uint64_t>(VT_TIMESTAMP, 0);
  }
  const flatbuffers::Vector<uint64_t> *dimensions() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_DIMENSIONS);
  }
  DType data_type() const {
    return static_cast<DType>(GetField<int8_t>(VT_DATA_TYPE, 0));
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Attribute>> *attributes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Attribute>> *>(VT_ATTRIBUTES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_SOURCE_NAME) &&
           verifier.VerifyString(source_name()) &&
           VerifyField<int32_t>(verifier, VT_ID) &&
           VerifyField<uint64_t>(verifier, VT_TIMESTAMP) &&
           VerifyOffsetRequired(verifier, VT_DIMENSIONS) &&
           verifier.VerifyVector(dimensions()) &&
           VerifyField<int8_t>(verifier, VT_DATA_TYPE) &&
           VerifyOffsetRequired(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           VerifyOffset(verifier, VT_ATTRIBUTES) &&
           verifier.VerifyVector(attributes()) &&
           verifier.VerifyVectorOfTables(attributes()) &&
           verifier.EndTable();
  }
};

struct ADArrayBuilder {
  typedef ADArray Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_source_name(flatbuffers::Offset<flatbuffers::String> source_name) {
    fbb_.AddOffset(ADArray::VT_SOURCE_NAME, source_name);
  }
  void add_id(int32_t id) {
    fbb_.AddElement<int32_t>(ADArray::VT_ID, id, 0);
  }
  void add_timestamp(uint64_t timestamp) {
    fbb_.AddElement<uint64_t>(ADArray::VT_TIMESTAMP, timestamp, 0);
  }
  void add_dimensions(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> dimensions) {
    fbb_.AddOffset(ADArray::VT_DIMENSIONS, dimensions);
  }
  void add_data_type(DType data_type) {
    fbb_.AddElement<int8_t>(ADArray::VT_DATA_TYPE, static_cast<int8_t>(data_type), 0);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(ADArray::VT_DATA, data);
  }
  void add_attributes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Attribute>>> attributes) {
    fbb_.AddOffset(ADArray::VT_ATTRIBUTES, attributes);
  }
  explicit ADArrayBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ADArray> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ADArray>(end);
    fbb_.Required(o, ADArray::VT_SOURCE_NAME);
    fbb_.Required(o, ADArray::VT_DIMENSIONS);
    fbb_.Required(o, ADArray::VT_DATA);
    return o;
  }
};

inline flatbuffers::Offset<ADArray> CreateADArray(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> source_name = 0,
    int32_t id = 0,
    uint64_t timestamp = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> dimensions = 0,
    DType data_type = DType_int8,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Attribute>>> attributes = 0) {
  ADArrayBuilder builder_(_fbb);
  builder_.add_timestamp(timestamp);
  builder_.add_attributes(attributes);
  builder_.add_data(data);
  builder_.add_dimensions(dimensions);
  builder_.add_id(id);
  builder_.add_source_name(source_name);
  builder_.add_data_type(data_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<ADArray> CreateADArrayDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *source_name = nullptr,
    int32_t id = 0,
    uint64_t timestamp = 0,
    const std::vector<uint64_t> *dimensions = nullptr,
    DType data_type = DType_int8,
    const std::vector<uint8_t> *data = nullptr,
    const std::vector<flatbuffers::Offset<Attribute>> *attributes = nullptr) {
  auto source_name__ = source_name ? _fbb.CreateString(source_name) : 0;
  auto dimensions__ = dimensions ? _fbb.CreateVector<uint64_t>(*dimensions) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  auto attributes__ = attributes ? _fbb.CreateVector<flatbuffers::Offset<Attribute>>(*attributes) : 0;
  return CreateADArray(
      _fbb,
      source_name__,
      id,
      timestamp,
      dimensions__,
      data_type,
      data__,
      attributes__);
}

inline const ADArray *GetADArray(const void *buf) {
  return flatbuffers::GetRoot<ADArray>(buf);
}

inline const ADArray *GetSizePrefixedADArray(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<ADArray>(buf);
}

inline const char *ADArrayIdentifier() {
  return "ADAr";
}

inline bool ADArrayBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, ADArrayIdentifier());
}

inline bool VerifyADArrayBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<ADArray>(ADArrayIdentifier());
}

inline bool VerifySizePrefixedADArrayBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<ADArray>(ADArrayIdentifier());
}

inline void FinishADArrayBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<ADArray> root) {
  fbb.Finish(root, ADArrayIdentifier());
}

inline void FinishSizePrefixedADArrayBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<ADArray> root) {
  fbb.FinishSizePrefixed(root, ADArrayIdentifier());
}

#endif  // FLATBUFFERS_GENERATED_ADARRAYSCHEMA_H_
