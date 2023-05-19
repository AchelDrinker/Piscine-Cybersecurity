FROM debian:bullseye-slim

COPY ./config/docker-entrypoint.sh /tmp/

RUN apt-get update \
    && apt-get install -y \
       vsftpd \
    && rm -rf /var/lib/apt/lists/* \
    && chmod +x /tmp/docker-entrypoint.sh

COPY ./config/vsftpd.conf /etc/vsftpd.conf

WORKDIR /tmp/

CMD ./docker-entrypoint.sh
