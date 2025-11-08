#include "Vertice.h"

#include <iostream>

using namespace std;

// Constructor.
Vertice::Vertice(int id, double x, double y) {
    this->id = id;
    this->x = x;
    this->y = y;
}


// Getters.
int Vertice::getId() { return id; }
double Vertice::getX() { return x; }
double Vertice::getY() { return y; }

// Setters.
void Vertice::setId(int id) { this->id = id; }
void Vertice::setX(double x) { this->x = x; }
void Vertice::setY(double y) { this->y = y; }
