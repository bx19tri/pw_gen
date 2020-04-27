#!/bin/bash

STR=$(echo -n "kame")
N=200
for ((i=0; i < $N; i++)); do
  STR=$(echo -n $STR|sha256sum|cut -f1 -d' ')
done

echo $STR

