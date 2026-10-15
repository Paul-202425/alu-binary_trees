#!/bin/bash
# Run from the repo folder. Usage: ./run_tasks.sh [first] [last]
first=${1:-0}
last=${2:-18}

for n in $(seq "$first" "$last"); do
	sol=$(ls $n-binary_tree_*.c 2>/dev/null | head -1)
	main="$n-main.c"
	if [ -z "$sol" ] || [ ! -f "$main" ]; then
		echo "== Task $n: missing solution or main file, skipping"
		continue
	fi

	files="binary_tree_print.c $main $sol"
	[ "$n" -ne 0 ] && files="$files 0-binary_tree_node.c"
	case $n in
		3|9|10|11|12|13|15|16) files="$files 2-binary_tree_insert_right.c" ;;
		14) files="$files 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c" ;;
	esac

	echo "=============== Task $n ==============="
	if gcc -Wall -Wextra -Werror -pedantic -std=gnu89 $files -o "/tmp/bt_$n"; then
		"/tmp/bt_$n"
	else
		echo "!! Task $n failed to compile"
	fi
	read -r -p "Press Enter for the next task (Ctrl+C to stop) " _
done
