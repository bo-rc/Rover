#!/bin/bash

rm *.h *.cxx
fastddsgen `find src/ -type f -name "*.idl"`
