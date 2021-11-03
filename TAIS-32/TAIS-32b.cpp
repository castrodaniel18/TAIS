
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct proyecto{
    int ini;
    int fin;
};

struct comp{
    bool operator()(proyecto const &a, proyecto const &b){
        if(a.ini == b.ini) return a.fin < b.fin;
        return a.ini > b.ini;
    }
};

bool en_rango(int ini, int fin, int C, int F){
    return fin >= C || ini <= F; 
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<proyecto, vector<proyecto>, comp> proyectos, int C, int F) {
    int aux, aux1 = 0, sol = 0;
    bool fin = false;
    if(!proyectos.empty()){
        if(proyectos.top().ini != C) return -1;
        aux = proyectos.top().fin;
        proyectos.pop();
        while(!proyectos.empty() && !fin){
            if(aux >= F) fin = true;
            sol++;
            while(!proyectos.empty() && proyectos.top().ini <= aux && !fin){
                if(proyectos.top().fin > aux1) aux1 = proyectos.top().fin;
                proyectos.pop();
            }
            aux = aux1;
        }
    }
    if(aux < F - 1) return -1;
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int C, F, N, c, f;
    bool hay_solucion = true;
    // leer los datos de la entrada
    cin >> C >> F >> N;
    if (C== 0 && F == 0 && N == 0)
        return false;

    priority_queue<proyecto, vector<proyecto>, comp> proyectos;
    for(int i = 0; i < N; i++){
        cin >> c >> f;
        if(en_rango(c, f, C, F)){
            if(c < C && f > C) {
                c = C;
            }
            proyectos.push({c, f});
        }
    }
    // escribir sol
    if(hay_solucion)
        cout << resolver(proyectos, C, F) << "\n";
    else cout << "Imposible\n";

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
