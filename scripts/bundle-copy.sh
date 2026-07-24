#!/usr/bin/env bash

oj-bundle -I ~/algo/cpp-library "$1" | iconv -f UTF-8 -t CP932 | clip.exe
