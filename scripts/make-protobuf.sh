#!/bin/bash

cd ./SourceSdk/Interfaces/Protobuf/protobuf-3.7.1
autogenfile=./autogen.sh
if [ ! -e "$autogenfile" ]; then
	cd ..
	echo "Downloading protobuf 3.7.1"
	wget https://github.com/google/protobuf/archive/v3.7.1.tar.gz
	tar xzvf v3.7.1.tar.gz
	rm v3.7.1.tar.gz
	cd protobuf-3.7.1
	echo "Downloading gtest 1.8.1"
	wget https://github.com/google/googletest/archive/release-1.8.1.tar.gz
	tar xzvf release-1.8.1.tar.gz
	rm release-1.8.1.tar.gz
	mv googletest-release-1.8.1 gtest
fi
