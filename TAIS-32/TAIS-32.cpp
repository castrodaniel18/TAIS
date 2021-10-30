
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
        return a.fin - a.ini > b.fin - b.ini;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<proyecto, vector<proyecto>, comp>& proyectos, vector<int> ocupado) {
    proyecto aux;
    bool necesario;
    int num_proyectos = proyectos.size();
    while(!proyectos.empty()){
        necesario = false;
        aux = proyectos.top();

        for(int i = aux.ini; i < aux.fin && !necesario; i++)
            if(ocupado[i] == 1) necesario = true;

        proyectos.pop();

        if(!necesario) {
            num_proyectos--;
            for(int i = aux.ini; i < aux.fin; i++) ocupado[i]--;
        }
    }
    return num_proyectos;
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

    F--;
    priority_queue<proyecto, vector<proyecto>, comp> proyectos;
    vector<int> ocupado(F, 0);
    for(int i = 0; i < N; i++){
        cin >> c >> f;
        if(c < C) c = C;
        if(f > F) f = F;
        proyectos.push({c, f});
        for(int j = c; j < f; j++) ocupado[j]++;
    }

    for(int i = C; i <= F; i++)
        if(ocupado[i] == 0) hay_solucion = false;

    // escribir sol
    if(hay_solucion)
        cout << resolver(proyectos, ocupado) << "\n";
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
