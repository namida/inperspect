#!/bin/bash
LD_PRELOAD="/usr/local/lib/fakenect/libfreenect.so" FAKENECT_PATH="../planes" ./prog $1
