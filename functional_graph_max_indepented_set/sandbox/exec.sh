#!/bin/bash

problem_name=FGIS
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
