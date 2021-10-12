#include <TDA_solucion.hpp>
#include <assert.h>
#include <iostream>
#include <limits.h>

using namespace std;

// Constructor --> reserva memoria para almacenar el vector X y lo inicializa con la decisión NULA
Solucion::Solucion( const int N){
    vector<int> aux (N, 2);
    x = aux;
    sumaCuadrados=0;
    mejorSol.first = INT_MAX;
    mejorSol.second = aux;

}

// Devuelve el tamaño del vector solución
int Solucion::size() const{
    return x.size(); 
}

//Asigna valor nulo a X[k], p.e. X[k]= NULO
void Solucion::iniciaComp(int k){
    assert(k >= 0 && k < x.size());
    x[k] = 2;
}

// Siguiente valor válido del dominio
void Solucion::sigValComp(int k){
    assert(k >= 0 && k < x.size());
    x[k]--;
    sumaCuadrados = 0;
}

// Testea si quedan valores de Sk por generar, ()
bool Solucion::todosGenerados(int k){
    assert(k >= 0 && k < x.size());
    return x[k] == -1;
}

// Obtener valor componente k, return X[k]
int Solucion::decision(int k) const{
    assert(k >= 0 && k < x.size());
    return x[k];
}

/* Representa el proceso que se realiza cuando se alcanza una solución.
    Permite quedarnos con la mejor solución */
void Solucion::procesaSolucion(){
    if(sumaCuadrados < mejorSol.first){
        mejorSol.first = sumaCuadrados;
        mejorSol.second = x;
    }    
}

/*Devuelve true si la solución actual, almacenada en (x1,x2, ..., xk) cumple
las restricciones y false en caso contrario*/
bool Solucion::factible(int k){
    assert(k >= 0 && k < x.size());
    int suma = 0, sumaRestantes = 0;
    
    for (int i = 0; i <= k; i++){
        suma += x[i] * (i+1);
        sumaCuadrados += (x[i] * (i+1)) * (x[i] * (i+1));
    }
            
    for (int i = k+1; i < x.size(); i++)
        sumaRestantes -= i+1;

    return ( ( (suma + sumaRestantes >= x.size()) && (suma + k + 2) <= x.size() ) || suma == x.size() );
    
}

void Solucion::mostrarMejorSol(){
    cout << " Vector --> ( ";
    for (int i = 0; i <  mejorSol.second.size(); i++)
        if(mejorSol.second[i] == 1)
            cout << i + 1 << " " ;
    cout << ") " << endl;
    cout << "Suma = " << mejorSol.first << endl;
}