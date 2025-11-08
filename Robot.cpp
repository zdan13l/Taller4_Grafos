#include "Robot.h"
#include <iostream>
using namespace std;

// Constructor del robot.
Robot::Robot(int capacidad, Grafo* grafo)
    : capacidadMaxima(capacidad),
      grafo(grafo),
      visitado(grafo->getCantidadVertices(), false) {
}

// Recorrido basado en matriz de adyacencia y capacidad.
void Robot::recorrer() {
    // Reiniciar estado.
    recorrido.clear();
    int verticesTotales = grafo->getCantidadVertices();
    int actual = 0, carga = 0;
    recorrido.push_back(actual);

    // Recorrer hasta visitar todos los vértices.
    while (true) {
        int siguiente = -1;
        double minDistancia = -1;

        vector<vector<double>>& matriz = grafo->getMatrizAdyacencia();

        // Buscar el siguiente vértice no visitado más cercano.
        for (int i = 1; i < verticesTotales; i++) {
            if (!visitado[i]) {
                double distancia = matriz[actual][i];
                if (siguiente == -1 || distancia < minDistancia) {
                    minDistancia = distancia;
                    siguiente = i;
                }
            }
        }

        // Si no hay más vértices por visitar, terminar.
        if (siguiente == -1) {
            break;
        }

        // Mover al siguiente vértice.
        recorrido.push_back(siguiente);
        visitado[siguiente] = true;
        actual = siguiente;
        carga++;

        // Si se alcanza la capacidad máxima, regresar al origen.
        if (carga == capacidadMaxima) {
            recorrido.push_back(0);
            actual = 0;
            carga = 0;
        }
    }

    // Regresar al origen si no se está allí.
    if (actual != 0) {
        recorrido.push_back(0);
    }

    // Imprimir recorrido.
    for (int j = 0; j < recorrido.size(); j++) {
        cout << recorrido[j];
        if (j != recorrido.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

// Getter del recorrido.
vector<int>& Robot::getRecorrido() { 
    return recorrido; 
}

// Getter de la capacidad.
int Robot::getCapacidad() { 
    return capacidadMaxima; 
}
