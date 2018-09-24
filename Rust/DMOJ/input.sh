#!/bin/bash
cargo build --color=always
target/debug/DMOJ < input.txt
