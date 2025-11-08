#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

// Clase que representa un vértice en el grafo.
class Vertice {
    private:
        // Atributos del vértice.
        int id;
        double x;
        double y;

    public:
        // Constructor
        Vertice(int id = 0, double x = 0.0, double y = 0.0);

        // Getters.
        int getId();
        double getX();
        double getY();

        // Setters.
        void setId(int id);
        void setX(double x);
        void setY(double y);

};

#endif
