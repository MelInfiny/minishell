#!/bin/bash

#COULEURS
vert="\033[32m"
rouge="\033[31m"
reset="\033[0m"

#BACKGROUND
blanc="\033[47m"

#DECORATION
stars="="
tiret="-----"

#FILES
FILE="data/*_test"

MS_OUT="trace/ms_res"
BASH_OUT="trace/bash_res"
RES="trace/res_"
LEAKS="trace/leaks_"
compteur=1

function repeat() {
	for i in {1..50}; do echo -n "$1"; done
	echo
}

function check_result() {
	../minishell > out 2>&1
	$1
	sed '/^[\$]>/d;1,3d;' out > $MS_OUT
	
	exec 1>bash > bout 2>&1
	$1
	sed 's/bash: line [0-9][0-9]*[:] //g' bout > $BASH_OUT
	echo "exit" >> $BASH_OUT
	
	local out=$(diff $BASH_OUT $MS_OUT | wc -l)
	rm -f $LEAKS$compteur
	repeat $stars
	if [[ $out -eq 0 ]]; then
		echo -en "${vert}${tiret}${tiret}RESULT OK : ${reset}"
	else
		echo -en "${rouge}${tiret}${tiret}RESULT FAIL : ${reset}"
		echo $1 "\n" > $LEAKS$compteur
		echo $out >> $LEAKS$compteur
		repeat $stars >> $LEAKS$compteur
	fi
#	rm -f out bout
}

function check_leaks() {
	valgrind --leak-check=full  --show-leak-kinds=all --track-fds=yes ../minishell > leaks 2>&1
	echo $1
	echo "exit"
	sed -r -n '/^(={2})([0-9]{4,})\1[ ]\LEAK SUMMARY:/,+3p' out | grep -E '[^0] bytes' >> $LEAKS$compteur
	if [[ -s $LEAKS$compteur ]]; then
		echo -e "${rouge}leaks found.${reset}"
	else
		echo -e "${vert}no leaks.${reset}"
		rm -f $LEAKS$compteur
	fi
	rm -f leaks
}

clear

echo "set enable-bracketed-paste off" > .inputrc
export INPUTRC=$PWD/.inputrc

while IFS= read -r line
do
	check_result $line
#	check_leaks $line
	((compteur+=1))
done < $FILE
