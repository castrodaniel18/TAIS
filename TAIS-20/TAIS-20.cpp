
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
                    if(dentro(i - 1, j) && mapa[i - 1][j] == '#')//ARRIBA
                        conjunto.unir((i - 1) * F + j, i * F + j);
                    if(dentro(i + 1, j) && mapa[i + 1][j] == '#')//ABAJO
                        conjunto.unir((i + 1) * F + j, i * F + j);
                    if(dentro(i, j - 1) && mapa[i][j - 1] == '#')//IZQUIERDA
                        conjunto.unir(i * F + (j - 1), i * F + j);
                    if(dentro(i, j + 1) && mapa[i][j + 1] == '#')//DERECHA
                        conjunto.unir(i * F + (j + 1), i * F + j);
                    if(dentro(i - 1, j - 1) && mapa[i - 1][j - 1] == '#')//ARRIBA IZQUIERDA
                        conjunto.unir((i - 1)* F + (j - 1), i * F + j);
                    if(dentro(i - 1, j + 1) && mapa[i - 1][j + 1] == '#')//ARRIBA DERECHA
                        conjunto.unir((i - 1)* F + (j + 1), i * F + j);
                    if(dentro(i + 1, j - 1) && mapa[i + 1][j - 1] == '#')//ABAJO IZQUIERDA
                        conjunto.unir((i + 1)* F + (j - 1), i * F + j);
                    if(dentro(i + 1, j + 1) && mapa[i + 1][j + 1] == '#')//ABAJO DERECHA
                        conjunto.unir((i + 1)* F + (j + 1), i * F + j);

                    if (conjunto.cardinal(i * F + j) > max) max = conjunto.cardinal(i * F + j);
                }
            }
        }
    }

    void anadir_mancha(vector<string> const &mapa, int i, int j){
        if(dentro(i - 1, j) && mapa[i - 1][j] == '#')//ARRIBA
            conjunto.unir((i - 1) * F + j, i * F + j);
        if(dentro(i + 1, j) && mapa[i + 1][j] == '#')//ABAJO
            conjunto.unir((i + 1) * F + j, i * F + j);
        if(dentro(i, j - 1) && mapa[i][j - 1] == '#')//IZQUIERDA
            conjunto.unir(i * F + (j - 1), i * F + j);
        if(dentro(i, j + 1) && mapa[i][j + 1] == '#')//DERECHA
            conjunto.unir(i * F + (j + 1), i * F + j);
        if(dentro(i - 1, j - 1) && mapa[i - 1][j - 1] == '#')//ARRIBA IZQUIERDA
            conjunto.unir((i - 1)* F + (j - 1), i * F + j);
        if(dentro(i - 1, j + 1) && mapa[i - 1][j + 1] == '#')//ARRIBA DERECHA
            conjunto.unir((i - 1)* F + (j + 1), i * F + j);
        if(dentro(i + 1, j - 1) && mapa[i + 1][j - 1] == '#')//ABAJO IZQUIERDA
            conjunto.unir((i + 1)* F + (j - 1), i * F + j);
        if(dentro(i + 1, j + 1) && mapa[i + 1][j + 1] == '#')//ABAJO DERECHA
            conjunto.unir((i + 1)* F + (j + 1), i * F + j);

        if (conjunto.cardinal(i * F + j) > max) max = conjunto.cardinal(i * F + j);
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
