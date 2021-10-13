
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

 // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */



int resolver(int N, int K, vector<int> saltos, int destino) {
    queue<int> cola;
    vector<int> distancias(destino + 1, -1);

    distancias[1] = 0;
    cola.push(1);
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        for (int i = 1; i <= K && actual + 1 <= destino; i++) {
            int nuevo= saltos[actual + i];
            if (distancias[nuevo] == -1) {
                distancias[nuevo] = distancias[actual] + 1;
                if (nuevo == destino) {
                    return distancias[destino];
                }
                cola.push(nuevo);
            }
        }
    }
}
 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int N, K, S, E;
    int aux1, aux2;
    // leer los datos de la entrada
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0)
        return false;

    vector<int> saltos(N * N + 1);//le sumas uno para que sea del 0 al 100 y no del 0 al 99
    for (int i = 1; i < saltos.size(); i++) {//empezamos en el 1(nos saltamos el 0)
        saltos[i] = i;
    }

    for (int i = 1; i <= S + E; i++) {
        cin >> aux1 >> aux2;
        saltos[aux1] = aux2;
    }
    
    int sol = resolver(N, K, saltos, N*N);//llegamos hasta la posicion 100 (N*N)
    cout << sol << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}