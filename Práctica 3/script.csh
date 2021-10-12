#!/bin/csh
@ inicio = 1000
@ fin = 100000
@ incremento = 1000
@ i = $inicio

rm tiempos_greedy_1.dat
rm tiempos_greedy_2.dat

g++ generarPesos.cpp -o generarPesos
g++ recipientes_greedy1.cpp -o recipientes_greedy1
g++ recipientes_greedy2.cpp -o recipientes_greedy2

while ( $i <= $fin )
    ./generarPesos $i > pesos.txt

    ./recipientes_greedy1 pesos.txt >> tiempos_greedy_1.dat

    ./recipientes_greedy2 pesos.txt >> tiempos_greedy_2.dat
    @ i += $incremento
end

rm generarPesos
rm recipientes_greedy1
rm recipientes_greedy2r
