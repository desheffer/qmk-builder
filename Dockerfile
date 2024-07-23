FROM ubuntu:22.04

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

RUN pip install qmk

ARG QMK_KEYBOARD=planck/rev6_drop
ARG QMK_KEYMAP=desheffer
ARG QMK_TAG=0.25.17

RUN qmk setup -b ${QMK_TAG} -y && \
    qmk config user.keyboard=${QMK_KEYBOARD} && \
    qmk config user.keymap=${QMK_KEYMAP}

WORKDIR /root/qmk_firmware
