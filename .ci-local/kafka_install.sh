#!/bin/bash 

# This script installs zookeeper and kafka services
#
# check if user has right permissions
if [ "$(id -u)" != "0" ]; then
    echo "Sorry, you are not root. Please try again using sudo."
    exit 1
fi

# terminate script after first line that fails
set -e

# Kafka broker install
# https://tecadmin.net/how-to-install-apache-kafka-on-ubuntu-22-04/
if [ ! -f /etc/systemd/system/zookeeper.service ]; then
    apt-get install -y default-jdk

    wget --tries=3 --timeout=10 https://dlcdn.apache.org/kafka/3.2.0/kafka_2.13-3.2.0.tgz
    tar xzf kafka_2.13-3.2.0.tgz 
    mv kafka_2.13-3.2.0 /usr/local/kafka

    echo [Unit] > /etc/systemd/system/zookeeper.service
    echo Description=Apache Zookeeper server >> /etc/systemd/system/zookeeper.service
    echo Documentation=http://zookeeper.apache.org >> /etc/systemd/system/zookeeper.service
    echo Requires=network.target remote-fs.target >> /etc/systemd/system/zookeeper.service
    echo After=network.target remote-fs.target >> /etc/systemd/system/zookeeper.service
    echo  >> /etc/systemd/system/zookeeper.service
    echo [Service] >> /etc/systemd/system/zookeeper.service
    echo Type=simple >> /etc/systemd/system/zookeeper.service
    echo ExecStart=/usr/local/kafka/bin/zookeeper-server-start.sh /usr/local/kafka/config/zookeeper.properties >> /etc/systemd/system/zookeeper.service
    echo ExecStop=/usr/local/kafka/bin/zookeeper-server-stop.sh >> /etc/systemd/system/zookeeper.service
    echo Restart=on-abnormal >> /etc/systemd/system/zookeeper.service
    echo  >> /etc/systemd/system/zookeeper.service
    echo [Install] >> /etc/systemd/system/zookeeper.service
    echo WantedBy=multi-user.target >> /etc/systemd/system/zookeeper.service
fi

if [ ! -f /etc/systemd/system/kafka.service ]; then
    echo [Unit] > /etc/systemd/system/kafka.service
    echo Description=Apache Kafka Server >> /etc/systemd/system/kafka.service
    echo Documentation=http://kafka.apache.org/documentation.html >> /etc/systemd/system/kafka.service
    echo Requires=zookeeper.service >> /etc/systemd/system/kafka.service
    echo >> /etc/systemd/system/kafka.service
    echo [Service] >> /etc/systemd/system/kafka.service
    echo Type=simple >> /etc/systemd/system/kafka.service
    echo Environment="JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64" >> /etc/systemd/system/kafka.service
    echo ExecStart=/usr/local/kafka/bin/kafka-server-start.sh /usr/local/kafka/config/server.properties  >> /etc/systemd/system/kafka.service
    echo ExecStop=/usr/local/kafka/bin/kafka-server-stop.sh >> /etc/systemd/system/kafka.service
    echo  >> /etc/systemd/system/kafka.service
    echo [Install] >> /etc/systemd/system/kafka.service
    echo WantedBy=multi-user.target >> /etc/systemd/system/kafka.service
    systemctl daemon-reload
    systemctl start zookeeper
    systemctl start kafka
    pushd /usr/local/kafka
    bin/kafka-topics.sh --create --bootstrap-server localhost:9092 --replication-factor 1 --partitions 1 --topic url_data_topic
    popd
    rm kafka_2.13-3.2.0.tgz
    
fi
