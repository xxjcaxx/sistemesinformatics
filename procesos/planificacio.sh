#!/bin/bash

echo -e "-----------------------Planifiacio FIFO----------------"
clock=$(date +"%s")
/usr/bin/time -f "1 Total: %E" chrt -f 50 ./procesoCPU 1 $1 &
sleep 1
/usr/bin/time -f "2 Total: %E" chrt -f 50 ./procesoCPU 2 $2 &
sleep 1
/usr/bin/time -f "3 Total: %E" chrt -f 50 ./procesoCPU 3 $3 &
wait
echo "Segons que han tardat entre tots: "$(($(date +"%s")-$clock))

echo -e "\n\n---------------------Planificacio BATCH--------------"
clock=$(date +"%s")
/usr/bin/time -f "1 Total: %E" chrt -b 0 ./procesoCPU 1 $1 &
sleep 1
/usr/bin/time -f "2 Total: %E" chrt -b 0 ./procesoCPU 2 $2 &
sleep 1
/usr/bin/time -f "3 Total: %E" chrt -b 0 ./procesoCPU 3 $3 &
wait
echo "Segons que han tardat entre tots: "$(($(date +"%s")-$clock))

echo -e "\n\n---------------------Planificacio RR-----------------"
clock=$(date +"%s")
/usr/bin/time -f "1 Total: %E" chrt -r 50  ./procesoCPU 1 $1 &
sleep 1
/usr/bin/time -f "2 Total: %E" chrt -r 50  ./procesoCPU 2 $2 &
sleep 1
/usr/bin/time -f "3 Total: %E" chrt -r 50  ./procesoCPU 3 $3 &
wait
echo "Segons que han tardat entre tots: "$(($(date +"%s")-$clock))

echo -e "\n\n------------------------Per defecte----------------------"
clock=$(date +"%s")
/usr/bin/time -f "1 Total: %E" ./procesoCPU 1 $1 &
sleep 1
/usr/bin/time -f "2 Total: %E" ./procesoCPU 2 $2 &
sleep 1
/usr/bin/time -f "3 Total: %E" ./procesoCPU 3 $3 &
wait
echo "Segons que han tardat entre tots: "$(($(date +"%s")-$clock))


