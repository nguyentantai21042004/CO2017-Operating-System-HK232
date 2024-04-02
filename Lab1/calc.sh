#! /usr/bin/bash

# Initialize variables
history=()

# Function to display history
display_history() {
	for entry in "${history[@]}"; do
		echo "$entry"
	done
}

while true; do
	echo -n ">> "
	read input

	if [ "$input" = "EXIT" ]; then
		exit
	fi

	if [ "$input" = "HIS" ]; then
		display_history
		continue
	fi

	if [ "$input" = "ANS" ]; then
		echo $(<ANS.txt)
		continue
	fi

	operand1=$(echo "$input" | awk '{print $1}')
	operator=$(echo "$input" | awk '{print $2}')
	operand2=$(echo "$input" | awk '{print $3}')

	# Check for ANS for give to operand
	if [ "$operand1" = "ANS" ]; then
		operand1=$(<ANS.txt)
	elif [ "$operand2" = "ANS" ]; then
		operand2=$(<ANS.txt)
	fi

	case $operator in
		+) res=$(echo "$operand1 + $operand2" | bc)
		;;
		-) res=$(echo "$operand1 - $operand2" | bc)
		;;
		x) res=$(echo "$operand1 * $operand2" | bc)
		;;
		/)
			# Devision operation
			if [ "$operand2" -eq 0 ]; then
				res="MATH ERROR"
			else
				res=$(echo "scale =2;$operand1 / $operand2" | bc)
			fi
		;;
		%) res=$(echo "$operand1 % $operand2" | bc)
		;;
		*) res="SYNTAX ERROR"
		;;
	esac
	if [ "$res" != "SYNTAX ERROR" ] && [ "$res" != "MATH ERROR" ] && [ "$input" != "HIS" ]; then
		echo "$res" > ANS.txt
		history+=("$input = $res")
		if [ ${#history[@]} -gt 5 ]; then
			history=("${history[@]: -5}")
		fi
	fi

	echo "$res"
	read -n1 -s -r
	#clear
done
