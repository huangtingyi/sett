#!/bin/sh
if [ $# != 1 ]; then
	echo "Usage $0 module"
	exit 1
fi
module=$1

export CVSROOT=:pserver:bill@192.168.0.100:/home/cvsroot;
cvs login
cvs checkout $module

exit 0

