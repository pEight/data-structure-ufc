#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
PURPLE='\033[0;35m'
DEFAULT_COLOR='\033[0m'

if [ -e $1 ] && [ -n $2 ] 
then
  g++ $1 -Wall -Wextra -pedantic -o $2
  ./$2
  RET=$?
else
  echo -e "\n${RED}You forgot some script argument! :(${DEFAULT_COLOR}\n"
  echo -e "${GREEN}Correct Usage:${DEFAULT_COLOR}"
  echo -e "\n$ ./compile.sh ${PURPLE}<file-to-compile>.cpp ${CYAN}<compiled-file-name>.out\n"
fi

exit $RET
