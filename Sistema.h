#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
using namespace std;

class Sistema {
private:
    Grafo* grafo;           // puntero para crear el grafo dinámicamente
    int capacidad;          // k
    int cantidadProductos;  // m
    int escenarios;         // n

public:
    Sistema();   // constructor
    ~Sistema();  // destructor

    bool cargarArchivo(const string& nombreArchivo);
    void mostrarResumen() const;
};

#endif
