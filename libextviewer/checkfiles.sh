#!/bin/sh
for file in *.cpp *.h
do echo ------ $file ------ >> log.txt
grep -n printf $file >> log.txt
echo ------------------- >> log.txt
done
