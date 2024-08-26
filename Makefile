.PHONY: up
up:
	docker compose up --build -d

.PHONY: compile
compile: up
	docker compose exec builder qmk compile

.PHONY: flash
flash: compile
	docker compose exec builder qmk flash
