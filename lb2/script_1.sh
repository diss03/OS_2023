#! /bin/sh
exaple=`ls -lRa / | grep -v "^/" | grep -v "^t"| sort -k1 | uniq -w1`
echo "Existing file types: $exaple"
