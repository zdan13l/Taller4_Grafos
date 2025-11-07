#include "Robot.h"

Robot::Robot(int capacidad, const Grafo& grafo)
    : capacidadMaxima(capacidad), grafo(grafo), visitado(grafo.getCantidadVertices(), false) {}



// Recorrido basado en matriz de adyacencia y capacidad
void Robot::recorrer() {
    recorrido.clear();
    int verticesTotales = grafo.getCantidadVertices();
    int actual = 0; // empieza en el origen
    int carga = 0;

    recorrido.push_back(actual); // origen
    // origen no se marca como visitado porque se visita varias veces

    while (true) {
        // Buscar el vértice más cercano no visitado
        int siguiente = -1;
        double minDist = -1;

        const vector<vector<double>>& matriz = grafo.getMatrizAdyacencia();

        for (int i = 1; i < verticesTotales; ++i) { // ignoramos el origen (0)
            if (!visitado[i]) {
                double d = matriz[actual][i];
                if (siguiente == -1 || d < minDist) {
                    minDist = d;
                    siguiente = i;
                }
            }
        }

        if (siguiente == -1) break; // todos visitados

        // Visitar siguiente
        recorrido.push_back(siguiente);
        visitado[siguiente] = true;
        carga++;
        actual = siguiente;

        // Si se llena la capacidad, volver al origen
        if (carga == capacidadMaxima) {
            recorrido.push_back(0);
            actual = 0;
            carga = 0;
        }
    }

    // Finalmente regresar al origen si no estamos en él
    if (actual != 0) {
        recorrido.push_back(0);
    }
}

// Getter del recorrido
const vector<int>& Robot::getRecorrido() const {
    return recorrido;
}

int Robot::getCapacidad() const {
    return capacidadMaxima;
}