#!/bin/bash

# ~~ set up ftp user ~~ #
useradd --create-home --shell /bin/bash $FTP_USR
echo "$FTP_USR:$FTP_PWD" | chpasswd

service vsftpd start
tail -f /dev/null
