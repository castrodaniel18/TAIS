
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(queue<int> &manguera, int L) {
    int parche, num_parches = 0;
    if(!manguera.empty()){
        parche = manguera.front(); manguera.pop();
        num_parches++;
    }
    while(!manguera.empty()){
        if(manguera.front() > parche + L){
            parche = manguera.front();
            num_parches++;
        }
        manguera.pop();
    }
    return num_parches;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, L, pos;
   // leer los datos de la entrada
   cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;
   queue<int> manguera;
   for(int i = 0; i < N; i++){
       cin >> pos;
       manguera.push(pos);
   }
   int sol = resolver(manguera, L);
   
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
