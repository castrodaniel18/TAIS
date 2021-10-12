
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct tarea {
    int c, f, n;
};

struct comp_tarea {
    bool operator()(tarea const& a, tarea const &b) {
        return a.c > b.c;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(priority_queue<tarea, vector<tarea>, comp_tarea> q, int T) {
    int i = q.top().c;
    tarea a, b;
    while (i < T && !q.empty()) {
        a = q.top();
        q.pop();
        if (!q.empty()) {
            b = q.top();
            if (a.f > b.c && b.c < T) return true;
            i = b.c;
            if (a.n > 0) q.push({ a.c + a.n, a.f + a.n, a.n });
        }
    }
    return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, M, T, n1, n2, t;

    priority_queue<tarea, vector<tarea>, comp_tarea> q;

    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        cin >> n1 >> n2;
        q.push({ n1, n2, 0 });
    }
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2 >> t;
        q.push({ n1, n2, t });
    }
   
   if (!std::cin)  // fin de la entrada
      return false;


   
   bool sol = resolver(q, T);
   
   // escribir sol
   if (sol) cout << "SI\n";
   else cout << "NO\n";
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
