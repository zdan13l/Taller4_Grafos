#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Clase Grafo que maneja vértices y matriz de adyacencia.
class Grafo {
    private:
        // Atributos del grafo y su matriz de adyacencia.
        vector<Vertice> vertices;
        vector<vector<double>> matrizAdyacencia;
        double calcularDistancia(Vertice& a, Vertice& b);

    public:
        // Métodos del grafo.
        Grafo();
        void agregarOrigen();
        void agregarVertice(int x, int y);
        void imprimirMatriz();
        
        // Obtener matriz de adyacencia y vértice por índice.
        vector<vector<double>>& getMatrizAdyacencia();
        Vertice& getVertice(int indice);
        int getCantidadVertices();
        
};

#endif
