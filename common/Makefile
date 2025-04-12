ifndef QMK_KEYBOARD
$(error QMK_KEYBOARD is not set)
endif

ifndef QMK_KEYMAP
$(error QMK_KEYMAP is not set)
endif

.PHONY: all
all: flash

.PHONY: build
build:
	docker compose build --pull

.PHONY: up
up: build
	docker compose up -d

.PHONY: sh
sh: up
	docker compose exec -it builder bash

.PHONY: clean
clean: up
	docker compose exec builder qmk clean

.PHONY: compile
compile: up
	docker compose exec builder qmk compile --keyboard $(QMK_KEYBOARD) --keymap $(QMK_KEYMAP)

.PHONY: flash
flash: compile
	docker compose exec builder qmk flash --keyboard $(QMK_KEYBOARD) --keymap $(QMK_KEYMAP)
