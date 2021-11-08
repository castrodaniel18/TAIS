
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct pelicula{
    int ini;
    int fin;
};

bool operator <(pelicula const &a, pelicula const &b){
    return a.fin < b.fin;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, h;
    string peli, hora, min, duracion;
    // leer los datos de la entrada
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<pelicula> peliculas;

    for(int i = 0; i < N; i++){
        cin >> peli >> duracion;
        hora = peli.substr(0, 2);
        min = peli.substr(3, 2);
        h = stoi(hora) * 60 + stoi(min);
        peliculas.push_back({h, h + stoi(duracion)});
    }

    sort(peliculas.begin(), peliculas.end());

    int i = 0, sol = 0, fin = 0;
    while(i < peliculas.size()){
        if(peliculas[i].ini >= fin){
            fin = peliculas[i].fin + 10;
            sol++;
        }
        i++;
    }

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
