#!/bin/bash 

# This script installs NDS and NDS-epics
#
# check if user has right permissions
if [ "$(id -u)" != "0" ]; then
    echo "Sorry, you are not root. Please try again using sudo."
    exit 1
fi

# terminate script after first line that fails
set -e

#install required libraries
apt-get install -y libreadline6-dev libncurses5-dev perl clang g++-mingw-w64-i686 g++-mingw-w64-x86-64 qemu-system-x86 re2c tar
apt-get install -y build-essential git python3 python-is-python3 curl p7zip-full wget libxml2-dev libx11-dev libxext-dev libntirpc-dev librdkafka-dev libssl-dev flatbuffers-compiler

#system required environment variables
echo export PATH=$PATH:/builds/DATAnet/ad-kafka-interface/.cache/base-R7.0.6.1/bin/linux-x86_64 >> /etc/bash.bashrc
echo export EPICS_CA_MAX_ARRAY_BYTES=20000000 >> /etc/bash.bashrc
echo export PATH=$PATH:/builds/DATAnet/ad-kafka-interface/.cache/base/R7-0.6.1/bin/linux-x86_64 >> /etc/bash.bashrc

#install ImageJ and ADViewers for visualtion.
.ci-local/adviewers_install.sh > /tmp/adviewers_install.log 2>&1

# Install kafka broker.
.ci-local/kafka_install.sh > /tmp/kafka_install.log 2>&1

export GITLAB_CI=1
export SETUP_PATH=".ci-local:.ci"
export BASE_RECURSIVE="YES"
export CMP="gcc"
export BGFC="default"
export SET="stable"
export CLEAN_DEPS="NO"
# export WINE=64
export VV=1
export CLEAN_DEPS="NO"

python .ci/cue.py prepare > /tmp/adkafkainterface_install.log 2>&1
python .ci/cue.py build >> /tmp/adkafkainterface_install.log 2>&1
