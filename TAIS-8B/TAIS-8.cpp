
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

struct comic {
    int n;//numero
    int p;//pila
};

struct comp {
    bool operator()(comic const& a, comic const& b) {
        return a.n > b.n;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
 int resolver(vector<stack<int>>& pilas, int min) {
     priority_queue<comic, vector<comic>, comp> q;
     int pos = 1, aux;
     comic c;
     for (int i = 0; i < pilas.size(); i++) {
         q.push({ pilas[i].top(), i });
     }
     while (!pilas.empty()) {
         c = q.top();
         if (c.n == min) return pos;
         else {
             q.pop();
             pilas[c.p].pop();
             q.push({ pilas[c.p].top(), c.p});
         }
         pos++;
     }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, aux, sol, min = -1;
    vector<stack<int>> pilas;
    cin >> N;
    for (int i = 0; i < N; i++) {
        stack<int> a;
        pilas.push_back(a);
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> aux;
            if (min > aux || min == -1) min = aux;
            pilas[i].push(aux);
        }
    }

    if (!std::cin)  // fin de la entrada
        return false;

    sol = resolver(pilas, min);

    // escribir sol
    cout << sol << "\n";
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
