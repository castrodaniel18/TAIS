
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct comp_pila {
    bool operator()(int const &a, int const& b) {
        return a < b;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(priority_queue<int>& A, priority_queue<int>& B, int n, int sol[], int& i) {
    int drones = n, t = 0, a, b;
    while (!A.empty() && !B.empty()) {
        if (drones > 0) {
            a = A.top();
            b = B.top();
            A.pop();
            B.pop();
            if (a >= b) {
                if (a - b > 0) A.push(a - b);
                t += b;
            }
            else {
                if (b - a > 0) B.push(b - a);
                t += a;
            }
            drones--;
        }
        else {
            sol[i] = t;
            i++;
            drones = n;
            t = 0;
        }
    }
    if (A.empty() || B.empty()) {
        sol[i] = t;
        i++;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b, aux, i = 0;
    priority_queue<int> A;
    priority_queue<int> B;
    int sol[200000];
    cin >> n;
    cin >> a;
    cin >> b;

    for (int i = 0; i < a; i++) {
        cin >> aux;
        A.push(aux);
    }

    for (int i = 0; i < b; i++) {
        cin >> aux;
        B.push(aux);
    }

    if (!std::cin)  // fin de la entrada
        return false;

    resolver(A, B, n, sol, i);

    // escribir sol
    if (i == 1) cout << sol[0];
    else if(i > 1) cout << sol[0];
    for (int j = 1; j < i; j++) {
        cout << " " << sol[j];
    }
    cout << "\n";

    return true;
}

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
