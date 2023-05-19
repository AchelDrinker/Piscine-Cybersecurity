FROM debian:bullseye-slim

RUN apt-get update \
    && apt-get -y install golang libpcap-dev ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /code

CMD tail -f /dev/null
