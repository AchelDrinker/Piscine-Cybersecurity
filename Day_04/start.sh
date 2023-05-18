#!/bin/bash
PORT=30001

case $1 in
	"up")
		HOST_FLAG=""
		if [[ $(uname) == "Linux" ]]; then
			HOST_FLAG="--add-host=host.docker.internal:host-gateway"
		fi

		docker build . -t stockholm:latest
		docker run \
			-v $(pwd)/Stockholm:/tmp/Stockholm \
			--name stockholm \
			--rm \
			$HOST_FLAG \
			stockholm &	
	;;
	"down")
		docker stop stockholm
		docker rm stockholm
	"exec")
		docker exec -it stockholm /bin/bash
	;;
	"listen")
		nc -lk $PORT >> .key_log &
		tail -f .key_log
	;;
	*)
		echo "usage: ./start.sh up | down | exec | listen"
	;;
esac
