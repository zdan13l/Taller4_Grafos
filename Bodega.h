#ifndef BODEGA_H
#define BODEGA_H

#include "Grafo.h"
#include "Robot.h"

#include <vector>
#include <string>

using namespace std;

// Clase Bodega que maneja múltiples escenarios y robots.
class Bodega {
    private:
        // Listas de escenarios, robots y recorridos.
        vector<Grafo> escenarios;
        vector<Robot> robots;
        vector<vector<int>> recorridos;

    public:
        Bodega();

        // Metodos para cargar archivo, guardar resultados, imprimir y mostrar tablero.
        void cargarArchivo(const string& nombreArchivo);
        void guardarResultados(const string& nombreArchivo);
        void imprimirRecorridos();
        void simularMovimiento(int indiceEscenario);
        
};

#endif
