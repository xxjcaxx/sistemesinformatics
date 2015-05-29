#!/bin/bash

generar_pantalla ()
 {
   ancho=$1
   for ((i=0;i<$((ancho*ancho));i++))
   do
   pantalla[$i]=$(echo $((RANDOM%2)))
   done
 }

ancho=$1
generar_pantalla $ancho
#echo "${pantalla[@]}" | tr -d ' ' |sed -r "s/.{$ancho}/&\n/g" | tr '01' ' '
clear
while [ 1 ]
do

  for((i=0;i<$ancho;i++))
  do
    for((j=0;j<$ancho;j++))
    do
      vivas=0
      [[ $i -gt 0 && $j -gt 0 ]] && vivas=$(($vivas+${pantalla[$(((i-1)*ancho+(j-1)))]}))
      [[ $i -gt 0 ]] && vivas=$(($vivas+${pantalla[$(((i-1)*ancho+j))]}))
      [[ $i -gt 0 && $j -lt $((ancho-1)) ]] && vivas=$(($vivas+${pantalla[$(((i-1)*ancho+(j+1)))]}))
      [[ $j -lt $((ancho-1)) ]] && vivas=$(($vivas+${pantalla[$((i*ancho+(j+1)))]}))
      [[ $i -lt $((ancho-1)) && $j -lt $((ancho-1)) ]] && vivas=$(($vivas+${pantalla[$(((i+1)*ancho+(j+1)))]}))
      [[ $i -lt $((ancho-1)) ]] && vivas=$(($vivas+${pantalla[$(((i+1)*ancho+j))]}))
      [[ $i -lt $((ancho-1)) && $j -gt 0 ]] && vivas=$(($vivas+${pantalla[$(((i+1)*ancho+(j-1)))]}))
      [[ $j -gt 0 ]] && vivas=$(($vivas+${pantalla[$((i*ancho+(j-1)))]}))

      case $vivas in
        2) temp[$((i*ancho+j))]=${pantalla[$((i*ancho+j))]} ;;
        3) temp[$((i*ancho+j))]=1 ;;
        *) temp[$((i*ancho+j))]=0 ;;
      esac

    done
  done

  pantalla=(${temp[@]})


  sleep 0.1
  echo -en "\e[s\e[0;0H$(echo ${pantalla[@]} | tr -d ' ' | sed -r "s/.{$ancho}/&\n/g" | sed -e 's/0/  /g' -e 's/1/\\e[38;5;2m😃 \\e[0m/g')"
done
