
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Guardias{
public:
    Guardias(Grafo const& grafo): protegidos(grafo.V(), false){

    }

    bool esPosible(Grafo const& grafo){
        return true;
    }

    int const minimo() { return min; }

private: 
    vector<bool> protegidos;
    int min;

    void dfs(Grafo const& grafo, int v, int a){

    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
   Grafo grafo(cin);

   if (!std::cin)  // fin de la entrada
      return false;
   
   Guardias guardias(grafo);
   
   // escribir sol
    if(guardias.esPosible(grafo)) cout << guardias.minimo() << "\n";
    else cout << "IMPOSIBLE\n"; 
   
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
