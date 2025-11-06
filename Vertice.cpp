#include "Vertice.h"
#include <iostream>
using namespace std;

// Constructor
Vertice::Vertice(int id, double x, double y, bool visitado) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->visitado = visitado;
}

// Getters
int Vertice::getId() const {
    return id;
}

double Vertice::getX() const {
    return x;
}

double Vertice::getY() const {
    return y;
}

bool Vertice::getVisitado() const {
    return visitado;
}

// Setters
void Vertice::setId(int id) {
    this->id = id;
}

void Vertice::setX(double x) {
    this->x = x;
}

void Vertice::setY(double y) {
    this->y = y;
}

void Vertice::setVisitado(bool estado) {
    this->visitado = estado;
}

// Mostrar información
void Vertice::mostrar() const {
    cout << "Vértice " << id << " -> (" << x << ", " << y << ")";
    cout << " | Visitado: " << (visitado ? "Sí" : "No") << endl;
}
