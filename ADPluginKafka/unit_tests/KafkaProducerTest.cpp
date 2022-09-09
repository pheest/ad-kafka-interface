/** Copyright (C) 2017 European Spallation Source */

/** @file  KafkaProducerTest.cpp
 *  @brief Unit tests of the Kafka producer part of this project.
 */

#include "KafkaProducer.h"
#include <ciso646>
#include <gtest/gtest.h>
#include "NDPluginDriverStandIn.h"

namespace KafkaInterface {

/// @brief Simple stand-in class used for unit tests.
//class KafkaProducerStandIn : public KafkaProducer {
//public:
//  KafkaProducerStandIn() : KafkaProducer(){};
//  KafkaProducerStandIn(std::string addr, std::string topic)
//      : KafkaProducer(addr, topic, &Registrar){};
//  using KafkaProducer::errorState;
//  using KafkaProducer::ConStat;
//  using KafkaProducer::kafka_stats_interval;
//  using KafkaProducer::conf;
//  using KafkaProducer::tconf;
//  void SetConStatParent(KafkaProducerStandIn::ConStat stat, std::string const &msg) {
//    KafkaProducer::SetConStat(stat, msg);
//  };
//  bool MakeConnectionParent() { return KafkaProducer::MakeConnection(); };
//  MOCK_METHOD0(MakeConnection, bool(void));
//  MOCK_METHOD2(SetConStat, void(KafkaProducerStandIn::ConStat, std::string const&));
//
//private:
//  ParameterHandler Registrar(nullptr);
//};

/// @brief A testing fixture used for setting up unit tests.
class KafkaProducerEnv : public ::testing::Test {
public:
  virtual void SetUp() {
    plugin = createStandInDriverPlugin();
  };

  virtual void TearDown() {
    plugin.reset();
  };
  std::unique_ptr<NDPluginDriverStandIn> plugin;
};

using namespace testing;
using ::testing::Mock;

//TEST_F(KafkaProducerEnv, ParameterCountTest) {
//  KafkaProducerStandIn prod;
//  ASSERT_EQ(prod.paramsList.size(), KafkaProducerStandIn::PV::count);
//}

TEST_F(KafkaProducerEnv, InitTest) {
  KafkaProducer prod;
  ASSERT_TRUE(prod.SetMaxMessageSize(1000));
  ASSERT_FALSE(prod.SetMaxMessageSize(0));
  ASSERT_TRUE(prod.SetStatsTimeMS(10));
  ASSERT_FALSE(prod.SetStatsTimeMS(0));
  unsigned char tempStr[] = "some";
  ASSERT_FALSE(prod.SendKafkaPacket(tempStr, 4, time_point()));
  ASSERT_FALSE(prod.SendKafkaPacket(tempStr, 0, time_point()));
}

//TEST_F(KafkaProducerEnv, SetTopicAndConnectionTest1) {
//  KafkaProducerStandIn prod;
//  EXPECT_CALL(prod, MakeConnection()).Times(AtLeast(1));
//  ASSERT_TRUE(prod.SetTopic("any_name"));
//  ASSERT_TRUE(prod.SetBrokerAddr("any_name"));
//}

//TEST_F(KafkaProducerEnv, InitWithAddrAndTopic) {
//  KafkaProducer prod("some_addr", "some_topic");
//  ASSERT_TRUE(prod.SetMaxMessageSize(1000));
//  ASSERT_FALSE(prod.SetMaxMessageSize(0));
//  ASSERT_TRUE(prod.SetStatsTimeMS(10));
//  ASSERT_FALSE(prod.SetStatsTimeMS(0));
//  unsigned char tempStr[] = "some";
//  ASSERT_TRUE(prod.SendKafkaPacket(tempStr, 4, time_point()));
//  ASSERT_FALSE(prod.SendKafkaPacket(tempStr, 0, time_point()));
//}

//TEST_F(KafkaProducerEnv, ErrorStateTest) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  prod.errorState = true;
//  ASSERT_FALSE(prod.SetTopic(""));
//  ASSERT_FALSE(prod.SetBrokerAddr("any_name"));
//  ASSERT_FALSE(prod.SetBrokerAddr(""));
//  ASSERT_FALSE(prod.SetMaxMessageSize(1000));
//  ASSERT_FALSE(prod.SetMaxMessageSize(0));
//  ASSERT_FALSE(prod.SetStatsTimeMS(10));
//  ASSERT_FALSE(prod.SetStatsTimeMS(0));
//  unsigned char tempStr[] = "some";
//  ASSERT_FALSE(prod.SendKafkaPacket(tempStr, 4, time_point()));
//  ASSERT_FALSE(prod.SendKafkaPacket(tempStr, 0, time_point()));
//}
//
//TEST_F(KafkaProducerEnv, StartThreadSuccessMessage) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, SetConStat(Ne(KafkaProducerStandIn::ConStat::ERROR), _))
//      .Times(Exactly(1));
//  ASSERT_TRUE(prod.StartThread());
//}
//
//TEST_F(KafkaProducerEnv, StartThreadFailureMessage) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  prod.errorState = true;
//  EXPECT_CALL(prod, SetConStat(Eq(KafkaProducerStandIn::ConStat::ERROR), _))
//      .Times(Exactly(1));
//  prod.StartThread();
//}
//
//TEST_F(KafkaProducerEnv, ParamCallFailure) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  prod.errorState = true;
//  ON_CALL(prod, SetConStat(_, _))
//      .WillByDefault(Invoke(&prod, &KafkaProducerStandIn::SetConStatParent));
//  prod.RegisterParamCallbackClass(plugin.get());
//  EXPECT_CALL(*plugin, setIntegerParam(_, _)).Times(Exactly(0));
//  EXPECT_CALL(*plugin, setStringParam(_, _)).Times(Exactly(0));
//  prod.StartThread();
////  Mock::VerifyAndClear(plugin);
//}

//TEST_F(KafkaProducerEnv, ParamCallSuccess) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  prod.errorState = true;
//  std::vector<PV_param> params = prod.GetParams();
//  int ctr = 1;
//  for (auto p : params) {
//    *p.index = ctr;
//    ctr++;
//  }
//  ON_CALL(prod, SetConStat(_, _))
//      .WillByDefault(Invoke(&prod, &KafkaProducerStandIn::SetConStatParent));
//  prod.RegisterParamCallbackClass(plugin.get());
//  EXPECT_CALL(*plugin, setIntegerParam(_, _)).Times(AtLeast(1));
//  EXPECT_CALL(*plugin, setStringParam(_, _)).Times(AtLeast(1));
//  prod.StartThread();
////  Mock::VerifyAndClear(plugin);
//}

//TEST_F(KafkaProducerEnv, MaxMessagesInQueue) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  ON_CALL(prod, MakeConnection())
//      .WillByDefault(
//          Invoke(&prod, &KafkaProducerStandIn::MakeConnectionParent));
//  std::vector<PV_param> params = prod.GetParams();
//  int ctr = 1;
//  for (auto const &p : params) {
//    *p.index.get() = ctr;
//    ctr++;
//  }
//  int sendMsgs = 10;
//  int msg_queued = *params[KafkaProducerStandIn::PV::msgs_in_queue].index.get();
//  ON_CALL(prod, SetConStat(_, _))
//      .WillByDefault(Invoke(&prod, &KafkaProducerStandIn::SetConStatParent));
//  prod.RegisterParamCallbackClass(plugin.get());
//  prod.SetMessageQueueLength(sendMsgs);
//  EXPECT_CALL(*plugin, setIntegerParam(_, _)).Times(AtLeast(0));
//  EXPECT_CALL(*plugin, setIntegerParam(Eq(msg_queued), Eq(sendMsgs)))
//      .Times(AtLeast(1));
//  prod.StartThread();
//  std::string msg("Some message");
//  for (int i = 0; i < sendMsgs; i++) {
//    ASSERT_TRUE(prod.SendKafkaPacket(
//        reinterpret_cast<const unsigned char *>(msg.c_str()), msg.size(), time_point()));
//  }
//
//  std::chrono::milliseconds sleepTime(int(prod.kafka_stats_interval * 1.5));
//  std::this_thread::sleep_for(sleepTime);
////  Mock::VerifyAndClear(plugin);
//}

//TEST_F(KafkaProducerEnv, TooManyMessagesInQueue) {
//  NiceMock<KafkaProducerStandIn> prod("some_addr", "some_topic");
//  ON_CALL(prod, MakeConnection())
//      .WillByDefault(
//          Invoke(&prod, &KafkaProducerStandIn::MakeConnectionParent));
//  std::vector<PV_param> params = prod.GetParams();
//  int ctr = 1;
//  for (auto const &p : params) {
//    *p.index.get() = ctr;
//    ctr++;
//  }
//  int maxQueueSize = 11;
//  auto const msgsQueuedIndex{*params[KafkaProducerStandIn::PV::msgs_in_queue].index.get()};
//  auto const statusMsgIndex{*params[KafkaProducerStandIn::PV::con_msg].index.get()};
//  auto const conStatusIndex{*params[KafkaProducerStandIn::PV::con_status].index.get()};
//  auto const maxMsgSizeIndex{*params[KafkaProducerStandIn::PV::max_msg_size].index.get()};
//  ON_CALL(prod, SetConStat(_, _))
//      .WillByDefault(Invoke(&prod, &KafkaProducerStandIn::SetConStatParent));
//  EXPECT_CALL(*plugin, setIntegerParam(Eq(msgsQueuedIndex), maxQueueSize))
//  .Times(AtLeast(1));
//  EXPECT_CALL(*plugin, setIntegerParam(Eq(conStatusIndex), _))
//  .Times(AtLeast(1));
//  EXPECT_CALL(*plugin, setIntegerParam(Eq(maxMsgSizeIndex), _))
//  .Times(AtLeast(1));
//  EXPECT_CALL(*plugin, setStringParam(Eq(statusMsgIndex), _)).Times(AtLeast(1));
//  prod.RegisterParamCallbackClass(plugin.get());
//  prod.SetMessageQueueLength(maxQueueSize);
//  prod.StartThread();
//  std::string msg("Some message");
//  for (int i = 0; i < maxQueueSize; i++) {
//    ASSERT_TRUE(prod.SendKafkaPacket(
//        reinterpret_cast<const unsigned char *>(msg.c_str()), msg.size(), time_point()));
//  }
//  ASSERT_FALSE(prod.SendKafkaPacket(
//      reinterpret_cast<const unsigned char *>(msg.c_str()), msg.size(), time_point()));
//  std::chrono::milliseconds sleepTime(int(prod.kafka_stats_interval * 1.5));
//  std::this_thread::sleep_for(sleepTime);
//  Mock::VerifyAndClear(plugin.get());
//}

//TEST_F(KafkaProducerEnv, TopicChangeReconnect) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, MakeConnection()).Times(Exactly(0));
//  prod.SetTopic("New topic");
//}
//
//TEST_F(KafkaProducerEnv, AddressChangeReconnect) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, MakeConnection()).Times(Exactly(1));
//  prod.SetBrokerAddr("new_addr");
//}
//
//TEST_F(KafkaProducerEnv, MessageSizeChangeReconnect) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, MakeConnection()).Times(Exactly(1));
//  prod.SetMaxMessageSize(1000);
//}
//
//TEST_F(KafkaProducerEnv, MessageQueueLengthChangeReconnect) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, MakeConnection()).Times(Exactly(1));
//  prod.SetMessageQueueLength(15);
//}
//
//TEST_F(KafkaProducerEnv, SetStatsTimeReconnect) {
//  KafkaProducerStandIn prod("some_addr", "some_topic");
//  EXPECT_CALL(prod, MakeConnection()).Times(Exactly(1));
//  prod.SetStatsTimeMS(100);
//}

//TEST_F(KafkaProducerEnv, SetStatsTimeValueTest) {
//  KafkaProducer prod("addr", "tpic");
//  int usedTime = 100;
//  prod.SetStatsTimeMS(usedTime);
//  ASSERT_EQ(usedTime, prod.GetStatsTimeMS());
//}
//
//TEST_F(KafkaProducerEnv, SetQueueSizeValueTest) {
//  KafkaProducer prod("addr", "tpic");
//  int usedLength = 11;
//  prod.SetMessageQueueLength(usedLength);
//  ASSERT_EQ(usedLength, prod.GetMessageQueueLength());
//}
//
//TEST_F(KafkaProducerEnv, SetMsgSizeValueTest) {
//  KafkaProducer prod("addr", "tpic");
//  int usedSize = 1111111;
//  prod.SetMaxMessageSize(usedSize);
//  ASSERT_EQ(usedSize, prod.GetMaxMessageSize());
//}

//TEST_F(KafkaProducerEnv, TestNrOfParams) {
//  KafkaProducer prod("some_addr", "some_topic");
//  ASSERT_EQ(prod.GetParams().size(), prod.GetNumberOfPVs());
//}
//
//TEST_F(KafkaProducerEnv, SetTopicIsSetTest) {
//  KafkaProducer prod("addr", "tpic");
//  std::string usedTopic = "some_test_topic";
//  prod.SetTopic(usedTopic);
//  ASSERT_EQ(usedTopic, prod.GetTopic());
//}
//
//TEST_F(KafkaProducerEnv, SetAddressIsSetTest) {
//  KafkaProducer prod("addr", "tpic");
//  std::string usedAddr = "some_test_broker_addr";
//  prod.SetBrokerAddr(usedAddr);
//  ASSERT_EQ(usedAddr, prod.GetBrokerAddr());
//}

//TEST_F(KafkaProducerEnv, IsAddrConfSetTest) {
//  std::string testAddr = "some_weird_addr";
//  std::string testTopic = "some_weird_topic";
//  KafkaProducerStandIn prod(testAddr, testTopic);
//  ASSERT_NE(prod.conf, nullptr);
//  std::string tempStr;
//  prod.conf->get("metadata.broker.list", tempStr);
//  ASSERT_EQ(testAddr, tempStr);
//}
}
