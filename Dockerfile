FROM ubuntu:20.04

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
ARG QMK_TAG=0.15.18

RUN qmk setup -y

WORKDIR /root/qmk_firmware

RUN git checkout ${QMK_TAG} && \
    qmk config user.keyboard=${QMK_KEYBOARD} && \
    qmk config user.keymap=${QMK_KEYMAP}
