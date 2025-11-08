#include "Robot.h"

#include <iostream>

using namespace std;

// Constructor del robot.
Robot::Robot(int capacidad, Grafo& grafo): capacidadMaxima(capacidad), grafo(grafo), visitado(grafo.getCantidadVertices(), false) {
    cout << "[DEBUG] Robot creado con capacidad: " << capacidadMaxima << " y " << grafo.getCantidadVertices() << " vértices en el grafo." << endl;
}

// Recorrido basado en matriz de adyacencia y capacidad.
void Robot::recorrer() {
    cout << "[DEBUG] Iniciando recorrido..." << endl;
    // Reiniciar estado.
    recorrido.clear();
    int verticesTotales = grafo.getCantidadVertices();
    int actual = 0, carga = 0;
    recorrido.push_back(actual);
    cout << "[DEBUG] Partiendo del origen (vértice 0)." << endl;

    // Recorrer hasta visitar todos los vértices.
    while (true) {
        int siguiente = -1;
        double minDistancia = -1;

        vector<vector<double>>& matriz = grafo.getMatrizAdyacencia();

        // Buscar el siguiente vértice no visitado más cercano.
        for (int i = 1; i < verticesTotales; i++) {
            if (!visitado[i]) {
                double distancia = matriz[actual][i];
                cout << "[DEBUG] Distancia desde " << actual << " a " << i << ": " << distancia << endl;
                if (siguiente == -1 || distancia < minDistancia) {
                    minDistancia = distancia;
                    siguiente = i;
                }
            }
        }

        // Si no hay más vértices por visitar, terminar.
        if (siguiente == -1) {
            cout << "[DEBUG] Todos los vértices han sido visitados." << endl;
            break;
        }

        // Mover al siguiente vértice.
        cout << "[DEBUG] Visitando vértice " << siguiente << " desde " << actual << endl;
        recorrido.push_back(siguiente);
        visitado[siguiente] = true;
        actual = siguiente;
        carga++;

        // Si se alcanza la capacidad máxima, regresar al origen.
        if (carga == capacidadMaxima) {
            cout << "[DEBUG] Capacidad máxima alcanzada. Regresando al origen." << endl;
            recorrido.push_back(0);
            actual = 0;
            carga = 0;
        }
    }

    // Regresar al origen si no se está allí.
    if (actual != 0) {
        cout << "[DEBUG] Recorrido finalizado fuera del origen. Regresando al origen." << endl;
        recorrido.push_back(0);
    }

    cout << "[DEBUG] Recorrido completo: ";
    // Imprimir recorrido.
    for (int id : recorrido) {
        cout << id << " ";
    }
    cout << endl;
}

// Getter del recorrido.
vector<int>& Robot::getRecorrido() { return recorrido; }

// Getter de la capacidad.
int Robot::getCapacidad() { return capacidadMaxima; }
