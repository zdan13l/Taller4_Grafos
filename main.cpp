#include "Grafo.h"

int main() {
    cout << "=== GRAFO NO DIRIGIDO ===" << endl;
    Grafo g1(5, false); // No dirigido

    g1.agregarArista(0, 1);
    g1.agregarArista(0, 2);
    g1.agregarArista(1, 3);
    g1.agregarArista(2, 4);

    g1.mostrarMatriz();
    g1.BFS(0);
    g1.DFS(0);

    cout << "\n=== GRAFO DIRIGIDO ===" << endl;
    Grafo g2(5, true); // Dirigido

    g2.agregarArista(0, 1);
    g2.agregarArista(1, 2);
    g2.agregarArista(2, 3);
    g2.agregarArista(3, 4);

    g2.mostrarMatriz();
    g2.BFS(0);
    g2.DFS(0);

    return 0;
}
