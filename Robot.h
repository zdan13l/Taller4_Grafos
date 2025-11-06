#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "Grafo.h"

using namespace std;

class Robot {
private:
    int capacidadMaxima;
    Grafo grafo;

    vector<int> recorrido;
    vector<bool> visitado;

public:
    Robot(int capacidad, const Grafo& g);

    void recorrer();
    const vector<int>& getRecorrido() const; // Getter para obtener el recorrido
    int getCapacidad();
};

#endif
