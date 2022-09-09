#!/bin/bash 

# This script configures ADSupport R1-9
#
# check if user has right permissions
if [ "$(id -u)" != "0" ]; then
    echo "Sorry, you are not root. Please try again using sudo."
    exit 1
fi

# terminate script after first line that fails
set -e

if [ -z "$EPICS_HOST_ARCH" ]; then
    EPICS_HOST_ARCH=linux-x86_64
fi
# The directory above
SUPPORT="$(dirname "${PWD}")"

# This won't have been set yet on the ADSupport pass.
ADURL=$PWD

# This file will have been written by ci-scripts cue.py
cp $SUPPORT/RELEASE.local $ADURL/configure/RELEASE.local

