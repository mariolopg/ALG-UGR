#include <vector>

using namespace std;

class Solucion { 
    private:
    vector<int> x; // Almacena la solución => valores (2, 1, 0, -1) Siendo 2--> NULO y -1 --> END
    int sumaCuadrados; //Valor de la suma de cuadrados de la solucion representada en el vector x

    pair< int, vector<int> > mejorSol;
    
    public:
    // Constructor --> reserva memoria para almacenar el vector X y lo inicializa con la decisión NULA
    Solucion(const int N); 

    // Devuelve el tamaño del vector solución
    int size() const;

    //Asigna valor nulo a X[k], p.e. X[k]= NULO
    void iniciaComp(int k);

    // Siguiente valor válido del dominio
    void sigValComp(int k); 

    // Testea si quedan valores de Sk por generar, (return X[k]==END)
    bool todosGenerados(int k); 

    // Obtener valor componente k, return X[k]
    int decision(int k) const;

    /* Representa el proceso que se realiza cuando se alcanza una solución.
       Permite quedarnos con la mejor solución */
    void procesaSolucion();

    /*Devuelve true si la solución actual, almacenada en (x1,x2, ..., xk) cumple
    las restricciones y false en caso contrario*/
    bool factible(int k);

    /*Muestra el vector de mejor solucion*/
    void mostrarMejorSol();

    ~Solucion() = default;
};