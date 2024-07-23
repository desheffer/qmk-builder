#!/bin/bash

set -euo pipefail

docker compose build
docker compose up -d

docker compose exec builder qmk compile
docker compose exec builder qmk flash
