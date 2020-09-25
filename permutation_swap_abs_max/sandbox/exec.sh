#!/bin/bash

problem_name=PASM
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
