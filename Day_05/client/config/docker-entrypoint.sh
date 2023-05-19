#!/bin/bash

while true; do
    arp >> /var/log/arp.log
    sleep 5
done
