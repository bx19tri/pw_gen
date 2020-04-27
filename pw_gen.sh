#!/bin/bash

DIGEST=sha512sum

PASSWD=$1
SERVICE=$2

#echo -n "$PASSWD$SERVICE" |$DIGEST|cut -f1 -d' '
echo -n "$PASSWD$SERVICE" |$DIGEST|cut -f1 -d' '|
#./hex2str;exit
./hex2str| sed 's/^[0-9]*//' |awk '{print substr($1,1,16);}'

