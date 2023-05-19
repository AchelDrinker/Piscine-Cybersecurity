FROM debian:bullseye-slim

COPY ./config/docker-entrypoint.sh /tmp/

RUN apt-get update  \
    && apt-get install -y \
       lftp \
       net-tools \
    && rm -rf /var/lib/apt/lists/* \
    && chmod +x /tmp/docker-entrypoint.sh

WORKDIR /tmp/

CMD ./docker-entrypoint.sh
