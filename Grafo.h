#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Vertice.h"

using namespace std;


class Grafo {
private:
    vector<Vertice> vertices;
    vector<vector<double>> matrizAdyacencia;

    double calcularDistancia(const Vertice& a, const Vertice& b) const;

public:
    Grafo();

    void agregarVertice(int x, int y);
    void agregarOrigen(); // Agrega el vértice origen (0,0) al inicio
    int getCantidadVertices() const;
    const Vertice& getVertice(int indice) const;
    const vector<vector<double>>& getMatrizAdyacencia() const;

    void imprimirMatriz() const;
};

#endif
