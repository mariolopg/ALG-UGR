#!/bin/csh
@ inicio = 2
@ fin = 100
@ incremento = 1
@ i = $inicio

rm tiempos_BT.dat
rm tiempos_BT_Cotas.dat

while ( $i <= $fin )
    ./BackTracking/BackTracking $i >> tiempos_BT.dat
    ./BackTrackingCotas/BackTrackingCotas $i >> tiempos_BT_Cotas.dat
    @ i += $incremento
end