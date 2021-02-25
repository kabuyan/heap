# 2.23
FROM ubuntu:16.04 
# 2.27
# FROM ubuntu:18.04
# 2.32
# FROM ubuntu:21.04

RUN apt-get update && apt-get install -y gdb

COPY . /home

WORKDIR /home