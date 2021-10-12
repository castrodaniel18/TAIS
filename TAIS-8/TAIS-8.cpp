
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   int N, aux;
   priority_queue<int, vector<int>> menor;
   priority_queue<int, vector<int>, greater<int>> mayor;

   cin >> N;

   if (!std::cin)  // fin de la entrada
       return false;

   // leer los datos de la entrada
   for (int i = 0; i < N; i++) {
       cin >> aux;
       if (aux == 0) {
           if (menor.empty() && mayor.empty()) cout << "ECSA\n";
           else {
               cout << menor.top() << "\n";
               menor.pop();
           }
       }
       else {
           if (menor.empty() || aux < menor.top()) menor.push(aux);
           else if (menor.top() < aux) mayor.push(aux);
       }
       if (menor.size() > mayor.size() + 1) {
           mayor.push(menor.top());
           menor.pop();
       }
       else if (mayor.size() > menor.size()) {
           menor.push(mayor.top());
           mayor.pop();
       }
   }
   // escribir sol

   return true;
}

int main() {
    //ajustes para que cin extraiga directamente de un fichero
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