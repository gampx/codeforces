#!/bin/bash
if [ $# -eq 0 ]
then
  echo -e "Small scpript to visualize graphs.\nGraph should be given in the form:
1 2\n2 3\n1 4\n\
Usage: $0 input_file [number of lines to skip from beginning]"
  exit 0
fi
SED_COMMAND="sed -e '1 i\graph G {' -e '$ a\}'"
for ((i = 1 ; i < $2 + 1 ; i++)); do 
  SED_COMMAND=$SED_COMMAND" -e '$i d'"
done

BUILD_COMMAND="cat $1 | awk {'print \$1 \" -- \" \$2 \";\"'} | $SED_COMMAND  > tmp.gr"
echo $BUILD_COMMAND
eval $BUILD_COMMAND
VISUALIZE_COMMAND="dot -Tpng tmp.gr -o /tmp/tmp.png; eog /tmp/tmp.png"
echo $VISUALIZE_COMMAND
eval $VISUALIZE_COMMAND
