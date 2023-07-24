#!/bin/bash

while true
do
	# Display the prompt and read user input
	printf "simple_shell> "
	read command

	# Execute the command
	$command
done
