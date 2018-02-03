#!/bin/bash
while [ 1 -eq 1 ]
do
  process_name=`ps aux | awk '{if ($11~/^.\/daemon$/) print $11}'`
  if [ -z "$process_name" ];then
     ./daemon
  fi
  sleep 10 
done
