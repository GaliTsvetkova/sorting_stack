#!/bin/zsh

from=$1
to=$2
all=$3
RED='\e[035m';
SALAT='\e[032m';
GRAY='\e[037m';
ENDC='\e[0m';

if [ "$#" -lt 3 ] || [ "$#" -gt 4 ]
then
	echo "to check pushswap please enter 3 arguments: from, to, number"
	exit
fi

count=0
let "count2 = $all - 1"
let "to2 = $to + 1"
until [ $count -gt $count2 ]
do
(( count++ ))
echo "${RED}Test №$count${ENDC}"
echo "${GRAY}Аргументы:${ENDC}"
ARG=`ruby -e "puts ($from ... $to2).to_a.shuffle.join(' ')"`
echo $ARG
echo "${GRAY}./push_swap :${ENDC}"
IT=$(./push_swap $ARG | wc -l)
TEMP=$(./push_swap -o $ARG)
echo $TEMP | grep "!"
echo "RES =${SALAT}$IT${ENDC}"
echo "${GRAY}./push_swap | ./checker :${ENDC}"
OK=$(./push_swap $ARG | ./checker $ARG)
if [[ ${OK} == "OK" ]]; then
    echo ${SALAT}${OK}${ENDC};
  else
    echo ${RED}${OK}${ENDC};
fi
done

