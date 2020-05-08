#!/bin/bash

N=100
DIGEST=sha512sum

MASTER_PASS_PHRASE=$1
MODIFIER=$2
SUM="$MASTER_PASS_PHRASE$MODIFIER"

for ((i=0; i < $N; i++)); do
  SUM=$(echo -n $SUM|$DIGEST|cut -f1 -d' ')
done

echo -n "$N times: "
echo $SUM|./hex2str|sed 's/^[0-9]*//'|awk '{print substr($1,1,16);}'

