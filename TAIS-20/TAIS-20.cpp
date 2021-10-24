
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Petroleo{
public:
    Petroleo(vector<string>const &mapa):F(mapa.size()), C(mapa[0].size()), conjunto(F*C){
        for(int i = 0; i < F; i++) {
            for(int j = 0; j < C; j++){
                if(mapa[i][j] == '#'){
                    if(dentro(i - 1, j) && mapa[i - 1][j] == '#')
                        conjunto.unir((i - 1) * F + j, i * F + j);
                    else if(dentro(i + 1, j) && mapa[i + 1][j] == '#')
                        conjunto.unir((i +1 ) * F + j, i * F + j);
                    else if(dentro(i, j - 1) && mapa[i][j - 1] == '#')
                        conjunto.unir(i * F + (j - 1), i * F + j);
                    else if(dentro(i, j + 1) && mapa[i][j + 1] == '#')
                        conjunto.unir(i * F + (j + 1), i * F + j);
                }
            }
        }
    }

    void añadir_mancha(vector<string> const &mapa, int i, int j){
        if(dentro(i - 1, j) && mapa[i - 1][j] == '#')
            conjunto.unir((i - 1) * F + j, i * F + j);
        else if(dentro(i + 1, j) && mapa[i + 1][j] == '#')
            conjunto.unir((i +1 ) * F + j, i * F + j);
        else if(dentro(i, j - 1) && mapa[i][j - 1] == '#')
            conjunto.unir(i * F + (j - 1), i * F + j);
        else if(dentro(i, j + 1) && mapa[i][j + 1] == '#')
            conjunto.unir(i * F + (j + 1), i * F + j);
    }

private:
    int C, F;
    ConjuntosDisjuntos conjunto;

    bool dentro(int i, int j){
        return 0 <= i && i < F && 0 <= j && j < C;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int F, C, manchas;
    cin >> F >> C; // número de filas y columnas
    if (!cin) return false;
    vector<string> mapa(F);
    // leemos la imagen
    for (string & linea : mapa)
        cin >> linea;

    Petroleo petroleo(mapa);
    cin >> manchas;
    for (int i = 0; i < manchas; i++){
        cin >> F >> C;
        mapa[F][C] = '#';
        petroleo.añadir_mancha(mapa, F, C);
    }
    //Solucion sol = resolver(datos);
    
   // escribir sol
    
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
