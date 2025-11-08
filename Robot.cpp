#include "Robot.h"
#include <iostream> // Asegúrate de incluir esto para los cout

Robot::Robot(int capacidad, const Grafo& grafo)
    : capacidadMaxima(capacidad), grafo(grafo), visitado(grafo.getCantidadVertices(), false) {
    std::cout << "[DEBUG] Robot creado con capacidad: " << capacidadMaxima
              << " y " << grafo.getCantidadVertices() << " vértices en el grafo." << std::endl;
}

// Recorrido basado en matriz de adyacencia y capacidad
void Robot::recorrer() {
    std::cout << "[DEBUG] Iniciando recorrido..." << std::endl;
    recorrido.clear();
    int verticesTotales = grafo.getCantidadVertices();
    int actual = 0; // empieza en el origen
    int carga = 0;

    recorrido.push_back(actual); // origen
    std::cout << "[DEBUG] Partiendo del origen (vértice 0)." << std::endl;

    while (true) {
        int siguiente = -1;
        double minDist = -1;

        const std::vector<std::vector<double>>& matriz = grafo.getMatrizAdyacencia();

        for (int i = 1; i < verticesTotales; ++i) {
            if (!visitado[i]) {
                double d = matriz[actual][i];
                std::cout << "[DEBUG] Distancia desde " << actual << " a " << i << ": " << d << std::endl;
                if (siguiente == -1 || d < minDist) {
                    minDist = d;
                    siguiente = i;
                }
            }
        }

        if (siguiente == -1) {
            std::cout << "[DEBUG] Todos los vértices han sido visitados." << std::endl;
            break;
        }

        std::cout << "[DEBUG] Visitando vértice " << siguiente << " desde " << actual << std::endl;
        recorrido.push_back(siguiente);
        visitado[siguiente] = true;
        carga++;
        actual = siguiente;

        if (carga == capacidadMaxima) {
            std::cout << "[DEBUG] Capacidad máxima alcanzada. Regresando al origen." << std::endl;
            recorrido.push_back(0);
            actual = 0;
            carga = 0;
        }
    }

    if (actual != 0) {
        std::cout << "[DEBUG] Recorrido finalizado fuera del origen. Regresando al origen." << std::endl;
        recorrido.push_back(0);
    }

    std::cout << "[DEBUG] Recorrido completo: ";
    for (int id : recorrido) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
}

// Getter del recorrido
const std::vector<int>& Robot::getRecorrido() const {
    return recorrido;
}

int Robot::getCapacidad() const {
    return capacidadMaxima;
}