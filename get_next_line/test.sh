# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/19 09:24:30 by kdezaphi          #+#    #+#              #
#    Updated: 2014/11/26 18:02:20 by jpiazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

make -C ../libft/ fclean
make -C ../libft/
gcc -Wall -Wextra -Werror -I ../libft/includes/ -I ../ -c ../get_next_line.c
gcc -Wall -Wextra -Werror -I ../libft/includes/ -I ../ -c btmain.c
gcc -Wall -Wextra -Werror -I ../libft/includes/ -I ../ -c itmain.c
gcc -Wall -Wextra -Werror -I ../libft/includes/ -I ../ -c atmain.c
gcc -Wall -Wextra -Werror -I ../libft/includes/ -I ../ -c etmain.c
gcc -o bttest_gnl get_next_line.o btmain.o -L ../libft/ -lft
gcc -o ittest_gnl get_next_line.o itmain.o -L ../libft/ -lft
gcc -o attest_gnl get_next_line.o atmain.o -L ../libft/ -lft
gcc -o ettest_gnl get_next_line.o etmain.o -L ../libft/ -lft

rm -f *.o

echo "\033[34m
				*** TEST DE GET NEXT LINE ***
\033[0m"

openssl rand -base64 $((6)) > 81.txt
openssl rand -base64 $((6)) > 82.txt
openssl rand -base64 $((6)) >> 82.txt
n=$(($RANDOM%20+5))
i=0
rm 8.txt
while [ $i -ne $n ]; do openssl rand -base64 $((6)) >> 8.txt; i=$((i+1)); done
echo "$(openssl rand -base64 $((6)))\c" > 8s.txt

openssl rand -base64 $((12)) > 161.txt
openssl rand -base64 $((12)) > 162.txt
openssl rand -base64 $((12)) >> 162.txt
n=$(($RANDOM%20+5))
i=0
rm 16.txt
while [ $i -ne $n ]; do openssl rand -base64 $((12)) >> 16.txt; i=$((i+1)); done
echo "$(openssl rand -base64 $((12)))\c" > 16s.txt

openssl rand -base64 $((3)) > 41.txt
openssl rand -base64 $((3)) > 42.txt
openssl rand -base64 $((3)) >> 42.txt
n=$(($RANDOM%20+5))
i=0
rm 4.txt
while [ $i -ne $n ]; do openssl rand -base64 $((3)) >> 4.txt; i=$((i+1)); done
echo "$(openssl rand -base64 $((3)))\c" > 4s.txt

./bttest_gnl 81.txt 82.txt 8.txt
str="$(openssl rand -base64 $((6)))"
echo "\n-----Affichage d'une ligne de 8 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
str="$(openssl rand -base64 $((6)))\n$(openssl rand -base64 $((6)))"
echo "\n-----Affichage de deux lignes de 8 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
echo "\n-----Affichage de plusieurs lignes de 8 caractere depuis l'entree standard-----"
n=$(($RANDOM%19+5))
i=0
str="$(openssl rand -base64 $((6)))"
while [ $i -ne $n ]; do str="$str\n$(openssl rand -base64 $((6)))"; i=$((i+1)); done
echo $str | ./bttest_gnl
echo $str

./ittest_gnl 161.txt 162.txt 16.txt
str="$(openssl rand -base64 $((12)))"
echo "\n-----Affichage d'une ligne de 16 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
str="$(openssl rand -base64 $((12)))\n$(openssl rand -base64 $((12)))"
echo "\n-----Affichage de deux lignes de 16 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
echo "\n-----Affichage de plusieurs lignes de 16 caractere depuis l'entree standard-----"
n=$(($RANDOM%19+5))
i=0
str="$(openssl rand -base64 $((12)))"
while [ $i -ne $n ]; do str="$str\n$(openssl rand -base64 $((12)))"; i=$((i+1)); done
echo $str | ./bttest_gnl
echo $str

./attest_gnl 41.txt 42.txt 4.txt 4s.txt 8s.txt 16s.txt
str="$(openssl rand -base64 $((3)))"
echo "\n-----Affichage d'une ligne de 4 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
str="$(openssl rand -base64 $((3)))\n$(openssl rand -base64 $((3)))"
echo "\n-----Affichage de deux lignes de 4 caractere depuis l'entree standard-----"
echo $str | ./bttest_gnl
echo $str
echo "\n-----Affichage de plusieurs lignes de 4 caractere depuis l'entree standard-----"
n=$(($RANDOM%19+5))
i=0
str="$(openssl rand -base64 $((3)))"
while [ $i -ne $n ]; do str="$str\n$(openssl rand -base64 $((3)))"; i=$((i+1)); done
echo $str | ./bttest_gnl
echo $str

./ettest_gnl
make -C ../libft/ fclean
