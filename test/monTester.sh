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
FILE="data/echo_test"

MS_OUT="trace/ms_res"
BASH_OUT="trace/bash_res"
DIFF="trace/diff"
LEAKS="trace/leaks"
RES="trace/res"
EXIT="exit"
compteur=1

function repeat() {
	for i in {1..50}; do echo -n "$1"; done
	echo -e "\n"
}

function lunch_shell() {
	echo -e $@ | ../minishell > out 2>&1
	sed '/^[\$]>/d;1,3d;' out > $MS_OUT	
}

function lunch_bash() {
	echo -e $@ | bash > bout 2>&1
	sed 's/bash: line [0-9][0-9]*[:] //g' bout > $BASH_OUT
}

function check_result() {
	repeat $stars
	echo -e "$@"
	local out=$(diff $BASH_OUT $MS_OUT | wc -l)
	if [[ $out -eq 0 ]]; then
		echo -en "${vert}${tiret}${tiret}RESULT OK : ${reset}"
	else
		echo -en "${rouge}${tiret}${tiret}RESULT FAIL : ${reset}"
		echo -e "$1\n" >> $DIFF
		echo -en ${rouge}$compteur:${reset} >> $DIFF
		diff $BASH_OUT $MS_OUT >> $DIFF
		repeat $stars >> $DIFF
	fi
	echo $@ >> $RES && cat $MS_OUT >> $RES && repeat $stars >> $RES
}

function check_leaks() {
	echo -e "$@" | valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=../readline_leaks ../minishell > leaks 2>&1
	sed -r -n '/^(={2})([0-9]{4,})\1[ ]\LEAK SUMMARY:/,+3p' leaks | grep -E '[^0] bytes' >> $LEAKS
	if [[ -s $LEAKS ]]; then
		echo -e "${rouge}leaks found.${reset}"
	else
		echo -e "${vert}no leaks.${reset}"
		rm -f $LEAKS
	fi
	rm -f leaks
}

clear
rm -f $LEAKS $DIFF $BASH_OUT $MS_OUT $RES
make -C ../ >/dev/null

echo "set enable-bracketed-paste off" > .inputrc
export INPUTRC=$PWD/.inputrc

while read -r line; do
	lunch_shell $line
	lunch_bash $line
	check_result $line
	check_leaks $line
	((compteur+=1))
#	rm -f out bout
done < $FILE

#cd .. && make fclean
