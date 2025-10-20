#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
END='\033[0m'

make

testExpr() {

	result=$(./RPN "$1")

	if [ "$result" == "$2" ]; then
		echo -e "$GREEN $1, \t result: $BLUE \t$2 $END \n"
	else
		echo -e "$1 \t résultat: $result (doit être $RED $2) $END \n"
	fi
}

testExpr "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
testExpr "7 7 * 7 - " "42"
testExpr "1 2 * 2 / 2 * 2 4 - +" "0"
testExpr "(1 + 1)" "Error: mauvaise expression !"
testExpr "2 4 * 8 +" "16"
testExpr "2 4 8 + * " "24"
testExpr "3 2 * 1   1 -" "Error: éléments restants"
testExpr "2 5 * 4 + 3 2 * 1 + / " "2"
testExpr "1 2 + 3 4 + *" "21" # (1 + 2) * (3 + 4)
testExpr "1 2 3 * 4 +" "Error: éléments restants" # 1 + 2 * 3 + 4
testExpr "1 2 3 4 + * +" "15" # 1 + 2 * (3 + 4)
testExpr "1 2 + 3 * 4 +" "13" # (1 + 2) * 3 + 4
testExpr "3 4 + 2 * 1 -" "13"
testExpr "7 2 + 5 3 - *" "18"
testExpr "9 2 / 1 + 8 *" "44"
testExpr "2 3 + 5 6 - * 7 +" "2"
testExpr "8 3 / 1 4 + * 7 -" "6.33333"
testExpr "8 0 /" "Error: division par 0 est interdite"
testExpr "3 2 + " "5"
testExpr "32+" "5"
testExpr "  32+ " "5"
testExpr " 3      2     +    " "5"
