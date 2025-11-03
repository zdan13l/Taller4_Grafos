#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Clase Grafo
 * Representa un grafo dirigido o no dirigido mediante una matriz de adyacencia.
 * Soporta recorridos BFS y DFS.
 */
class Grafo {
private:
    int numVertices;                      // Número de vértices
    bool esDirigido;                      // True = dirigido, False = no dirigido
    vector<vector<int>> matrizAdyacencia; // Matriz NxN
    void DFSRecursivo(int v, vector<bool>& visitado); // Auxiliar para DFS

public:
    // Constructor
    Grafo(int numVertices, bool esDirigido = false);

    // Métodos básicos
    void agregarArista(int origen, int destino);
    void eliminarArista(int origen, int destino);
    void mostrarMatriz() const;

    // Recorridos
    void BFS(int verticeInicio) const;
    void DFS(int verticeInicio) const;
};

#endif
