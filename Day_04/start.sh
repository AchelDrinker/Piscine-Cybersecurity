#!/bin/bash
echo "Open Docker"
open -a Docker
echo "Wait the opening"
sleep 20
echo "Install debian"
docker pull debian
echo "Erase if a docker stockholm already exist"
docker rm stockholm
echo "Install dependencies"
echo "Open Stockholmfiles/README.md"
open Stockholmfiles/README.md
echo "Launch this from another terminal : docker cp Stockholmfiles stockholm:/home"
echo "In your docker, do this : cd home/Stockholmfiles && apt update && apt install python3 -y && apt install python3-pip -y && pip3 install -r requirement.txt"
echo "Launch Docker Stockholm"
docker run -it --name stockholm debian