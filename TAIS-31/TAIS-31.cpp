
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct edificio{
    int W;
    int E;
};

struct comp{
    bool operator()(edificio const &a, edificio const &b){ 
        return a.E >= b.E;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<edificio, vector<edificio>, comp>& edificios) {
   int actual = -1, pasadizos = 0;
    while(!edificios.empty()){
        // if(actual == -1 || actual < edificios.top().W){
        //     actual = edificios.top().E;
        //     pasadizos++;
        // }
        // edificios.pop();
        actual = edificios.top().E;
        edificios.pop();
        pasadizos++;
        while(!edificios.empty() && edificios.top().W < actual){
            edificios.pop();
        }
    }
    return pasadizos;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, W, E;
    // leer los datos de la entrada
    cin >> N;
    if (N == 0)
        return false;

    priority_queue<edificio, vector<edificio>, comp> edificios;
    for(int i = 0; i < N; i++){
        cin >> W >> E;
        edificios.push({W, E});
    }

    int sol = resolver(edificios);

    // escribir sol
    cout << sol << '\n';

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
