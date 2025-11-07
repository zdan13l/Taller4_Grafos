#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

// Clase que representa un vértice en el grafo.
class Vertice {
    private:
        int id;
        double x;
        double y;
        bool visitado;

    public:
        // Constructor
        Vertice(int id = 0, double x = 0.0, double y = 0.0, bool visitado = false);

        // Getters.
        int getId() const;
        double getX() const;
        double getY() const;
        bool getVisitado() const;

        // Setters.
        void setId(int id);
        void setX(double x);
        void setY(double y);
        void setVisitado(bool estado);

        // Mostrar información del vértice.
        void mostrar();
};

#endif
