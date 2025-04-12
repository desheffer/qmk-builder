FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y \
        avr-libc \
        avrdude \
        binutils-arm-none-eabi \
        dfu-programmer \
        dfu-util \
        gcc-arm-none-eabi \
        gcc-avr \
        git \
        make \
        python3-pip \
    && \
    rm -rf /var/lib/apt/lists/*

ARG QMK_CLI_VERSION=1.1.6
ARG QMK_TAG

RUN pip install --break-system-packages qmk==${QMK_CLI_VERSION}
RUN qmk setup -b ${QMK_TAG} -y

WORKDIR /root/qmk_firmware

RUN pip install --break-system-packages -r requirements.txt
