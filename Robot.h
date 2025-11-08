#ifndef ROBOT_H
#define ROBOT_H

#include "Grafo.h"
#include <vector>
using namespace std;

// Clase Robot que realiza el recorrido en el grafo.
class Robot {
    private:
        // Atributos del robot.
        Grafo* grafo;
        vector<int> recorrido;
        vector<bool> visitado;
        int capacidadMaxima;

    public:
        // Constructor, recibe la capacidad y un puntero al grafo.
        Robot(int capacidad, Grafo* grafo);

        // Métodos
        void recorrer();
        vector<int>& getRecorrido();
        int getCapacidad();
        
};

#endif
