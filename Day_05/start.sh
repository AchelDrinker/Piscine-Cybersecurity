#!/bin/bash

case $1 in
    "up")
	docker-compose up --build -d
	docker exec -it attacker bash
	;;
    "down")
	docker-compose down
	;;
    "netinfo")
	SRV_IP=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' server)
	SRV_MC=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.MacAddress}}{{end}}' server)
	CLI_IP=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' client)
	CLI_MC=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.MacAddress}}{{end}}' client)
	EVL_IP=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' attacker)
	EVL_MC=$(docker inspect -f '{{range.NetworkSettings.Networks}}{{.MacAddress}}{{end}}' attacker)

	echo "source: [ ${EVL_IP} ${EVL_MC} ]"
	echo "client: [ ${CLI_IP} ${CLI_MC} ]"
	echo "server: [ ${SRV_IP} ${SRV_MC} ]"
	;;
    "client")
	docker exec -it client bash -c "lftp -d server"
	;;
    *)
	echo "usage: ./start.sh [ up | down | netinfo | client ]"
	exit 1
	;;
esac
