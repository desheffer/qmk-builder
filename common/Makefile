ifndef QMK_KEYBOARD
$(error QMK_KEYBOARD is not set)
endif

ifndef QMK_KEYMAP
$(error QMK_KEYMAP is not set)
endif

ifndef QMK_TAG
$(error QMK_TAG is not set)
endif

export QMK_HOME := $(CURDIR)/qmk_firmware
export QMK_USERSPACE := $(CURDIR)

.PHONY: all
all: flash

qmk_firmware:
	qmk setup -H $(QMK_HOME) -b $(QMK_TAG) -y

.PHONY: clean
clean: qmk_firmware
	qmk clean

.PHONY: compile
compile: qmk_firmware
	qmk compile --keyboard $(QMK_KEYBOARD) --keymap $(QMK_KEYMAP) --parallel 0

.PHONY: flash
flash: compile
	qmk flash --keyboard $(QMK_KEYBOARD) --keymap $(QMK_KEYMAP)
