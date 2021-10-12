#!/bin/csh
@ inicio = 1000
@ fin = 50000
@ incremento = 1000
@ i = $inicio

while ( $i <= $fin )
  echo Tam = $i
  echo `./burbuja_o3 $i` >> tiempos_burbuja_o3.dat
  @ i += $incremento
end
@ i = $inicio
while ( $i <= $fin )
  echo Tam = $i
  echo `./insercion_o3 $i` >> tiempos_insercion_o3.dat
  @ i += $incremento
end