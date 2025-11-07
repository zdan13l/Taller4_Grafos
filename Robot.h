#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "Grafo.h"

using namespace std;

// Clase Robot que maneja la lógica de recorrido.
class Robot {
    private:
        Grafo grafo;
        vector<int> recorrido;
        vector<bool> visitado;
        int capacidadMaxima;

    public:
        Robot(int capacidad, const Grafo& grafo);
        const vector<int>& getRecorrido() const;
        int getCapacidad() const;
        void recorrer();

};

#endif
