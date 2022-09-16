#!/bin/bash
# https://gist.github.com/hartfordfive/5928e7bca7c6239e4e1036346d326953#file-kafka-del-topics-sh

TOPICS=$(kafka-topics --zookeeper [ZK_IP]:2181/kafka --list )

for T in $TOPICS
do
  if [ "$T" != "__consumer_offsets" ]; then
    kafka-topics --zookeeper [ZK_IP]:2181/kafka --delete --topic $T
  fi
done
