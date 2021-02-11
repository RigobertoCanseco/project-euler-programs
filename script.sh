#!/bin/bash
# Print Hello world message
echo "Run script"
curl --request GET -sL \
     --url 'https://projecteuler.net/minimal=100' \
     --output '_posts/example.md'
echo "Finish"
