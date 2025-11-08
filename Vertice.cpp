#include "Vertice.h"

#include <iostream>

using namespace std;

// Constructor.
Vertice::Vertice(int id, double x, double y, bool visitado) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->visitado = visitado;
}

// Mostrar información del vértice.
void Vertice::mostrar() {
    cout << endl;
    cout << " Vértice " << id << " -> (" << x << ", " << y << ") |";
    cout << " Visitado: ";
    if (visitado) {
        cout << "Sí" << endl;
    } else {
        cout << "No" << endl;
    }
}

// Getters.
int Vertice::getId() { return id; }
double Vertice::getX() { return x; }
double Vertice::getY() { return y; }
bool Vertice::getVisitado() { return visitado; }

// Setters.
void Vertice::setId(int id) { this->id = id; }
void Vertice::setX(double x) { this->x = x; }
void Vertice::setY(double y) { this->y = y; }
void Vertice::setVisitado(bool estado) { this->visitado = estado; }
