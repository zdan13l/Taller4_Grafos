#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Grafo.h"
#include "Robot.h"

using namespace std;

class Sistema {
private:
    vector<Grafo> escenarios;
    vector<Robot> robots;
    vector<vector<int>> recorridos;

public:
    Sistema();

    void cargarArchivo(const string& nombreArchivo); // Leer, procesar y guardar
    void imprimirRecorridos() const;
    void mostrarTablero(int escenarioIndex) const;


    // Getters necesarios si quieres usarlos
    const vector<Grafo>& getEscenarios() const { return escenarios; }
    const vector<Robot>& getRobots() const { return robots; }
    const vector<vector<int>>& getRecorridos() const { return recorridos; }
};

#endif
