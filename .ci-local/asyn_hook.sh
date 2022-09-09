#!/bin/bash 

# This script configures asyn R4-41
#
# check if user has right permissions
if [ "$(id -u)" != "0" ]; then
    echo "Sorry, you are not root. Please try again using sudo."
    exit 1
fi

# terminate script after first line that fails
set -e

if [ -z "$EPICS_HOST_ARCH" ]
then
    EPICS_HOST_ARCH=linux-x86_64
fi


ASYN=$PWD
# See https://epics.anl.gov/tech-talk/2021/msg01046.php
echo TIRPC=YES >> $ASYN/configure/CONFIG_SITE.linux-x86_64.Common
