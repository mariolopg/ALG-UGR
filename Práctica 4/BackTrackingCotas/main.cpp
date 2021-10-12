//g++ main.cpp TDA_solucion.cpp -I. -o TDA_solucion
#include <TDA_solucion.hpp>
#include <iostream>

using namespace std;
 
void back_recursivo(Solucion & Sol, int k);
void backTracking(Solucion & Sol);

int main(int argc, char *argv[]){
    int N;
    clock_t t_ini, t_fin;

    if(argc != 2){
        cerr << "Error en el numero de argumentos. Ejecucion: ./BackTrackingCotas <numero>" << endl;
        return 1;
    }

    N = atoi(argv[1]);

    Solucion sol(N); 

    t_ini = clock();
    backTracking(sol);
    t_fin = clock();
    
    sol.mostrarMejorSol();

    cout << N << " " << ((double)(t_fin - t_ini)) / CLOCKS_PER_SEC << endl;
 
}

void backTracking(Solucion & Sol){
    back_recursivo(Sol, 0);
}

void back_recursivo(Solucion &Sol, int k){
    if (k == Sol.size())
        Sol.procesaSolucion();
    
    else{
        Sol.iniciaComp(k);
        Sol.sigValComp(k);
        while (!Sol.todosGenerados(k)){            
            if (Sol.factible(k))
                back_recursivo(Sol, k + 1);
               
            Sol.sigValComp(k);  
        }
    }
}