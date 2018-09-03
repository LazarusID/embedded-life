FROM ubuntu:18.04

RUN apt update && apt install -y vim build-essential git \
    check pkg-config man arduino