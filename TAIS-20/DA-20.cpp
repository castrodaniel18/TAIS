
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Petroleo{
public:
    Petroleo(vector<string>const &mapa, int f, int c):F(f), C(c), max(0), conjunto(F*C){
        for(int i = 0; i < F; i++) {
            for(int j = 0; j < C; j++){
                if(mapa[i][j] == '#'){
                    une_manchas(mapa, i, j);
                    if (conjunto.cardinal(i * C + j) > max) max = conjunto.cardinal(i * C + j);
                }
            }
        }
    }

    void une_manchas(vector<string> const &mapa, int i, int j){
        for(int k = i - 1; k < i + 2; k++){
            for(int l = j - 1; l < j + 2; l++){
                if(dentro(k, l) && mapa[k][l] == '#' && !conjunto.unidos(k * C + l, i * C + j))
                    conjunto.unir(k * C + l, i * C + j);
            }
        }
    }

    void anadir_mancha(vector<string> const &mapa, int i, int j){
        une_manchas(mapa, i, j);
        if (conjunto.cardinal(i * C + j) > max) max = conjunto.cardinal(i * C + j);
    }

    int solucion(vector<string> const& mapa) { return max; }

private:
    int C, F, max;
    ConjuntosDisjuntos conjunto;

    bool dentro(int i, int j){
        return 0 <= i && i < F && 0 <= j && j < C;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int F, C, manchas;
    cin >> F >> C;

    if (!cin) return false;

    vector<string> mapa(F);

    cin.ignore();
    for (string& linea : mapa)
        getline(cin, linea);

    Petroleo petroleo(mapa, F, C);
    cout << petroleo.solucion(mapa) << " ";
    cin >> manchas;
    for (int i = 0; i < manchas; i++){
        cin >> F >> C;
        F--;
        C--;
        mapa[F][C] = '#';
        petroleo.anadir_mancha(mapa, F, C);
        cout << petroleo.solucion(mapa) << " ";
    }
    cout << "\n";

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
