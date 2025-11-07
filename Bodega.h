#ifndef BODEGA_H
#define BODEGA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

// Clase Bodega representa la bodega con sus productos y el grafo asociado.
class Bodega {
    private:
        Grafo* grafo;
        int capacidad;
        int cantidadProductos;
        int nEscenarios;

    public:
        Bodega();
        ~Bodega();
        bool cargarArchivo(const string& nombreArchivo);
        void mostrarResumen(int escenario);
};

#endif
