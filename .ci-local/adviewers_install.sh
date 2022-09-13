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

# for data viewing only
# Install ADViewers for use by ImageJ
ADVIEWERS_VER="R1-7"
ADVIEWERS_DOWNLOAD=$ADVIEWERS_VER".zip"
ADVIEWERS_PATH=/usr/share/imagej
if [ ! -d $ADVIEWERS_PATH ]; then
    apt-get install -y imagej
    mkdir $ADVIEWERS_PATH
    wget --tries=3 --timeout=10 https://github.com/areaDetector/ADViewers/archive/refs/tags/$ADVIEWERS_DOWNLOAD
    unzip $ADVIEWERS_DOWNLOAD -d $ADVIEWERS_PATH
    rm $ADVIEWERS_DOWNLOAD
fi
