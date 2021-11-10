
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct proyecto{
    int ini;
    int fin;
};

bool operator<(proyecto const &a, proyecto const &b){
    return a.ini < b.ini;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<proyecto>const & proyectos, int C, int F) {
    int actual, fin_proyecto = C, sol = 0, i = 0;
    bool imposible = false;
    while(fin_proyecto < F && !imposible){
        actual = fin_proyecto;
        while(i < proyectos.size() && proyectos[i].ini <= fin_proyecto){
            if(proyectos[i].fin > actual){
                actual = proyectos[i].fin;
            }
            i++;
        }
        if(actual > fin_proyecto){
            sol++;
            fin_proyecto = actual;
        }
        else imposible = true;
    }

    if(imposible) return -1;
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int C, F, N, c, f, sol;
    // leer los datos de la entrada
    cin >> C >> F >> N;
    if (C== 0 && F == 0 && N == 0)
        return false;

    vector<proyecto> proyectos;
    for(int i = 0; i < N; i++){
        cin >> c >> f;
        proyectos.push_back({c, f});
    }
    sort(proyectos.begin(), proyectos.end());
    sol =  resolver(proyectos, C, F);

    // escribir sol
    if(sol != -1) cout << sol << "\n";
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
