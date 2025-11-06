#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
using namespace std;

class Vertice {
private:
    int id;          // Identificador único del vértice
    double x;        // Coordenada X
    double y;        // Coordenada Y
    bool visitado;   // Marca de visita (para algoritmos de recorrido)

public:
    // Constructor
    Vertice(int id = 0, double x = 0.0, double y = 0.0, bool visitado = false);

    // Getters
    int getId() const;
    double getX() const;
    double getY() const;
    bool getVisitado() const;

    // Setters
    void setId(int id);
    void setX(double x);
    void setY(double y);
    void setVisitado(bool estado);

    // Mostrar información del vértice
    void mostrar() const;
};

#endif
