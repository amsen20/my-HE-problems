#!/bin/bash

problem_name=CALOC
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
