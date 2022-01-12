
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> Foto;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Ovejas{
public:
    Ovejas(Foto const& foto) : F(foto.size()), C(foto[0].size()), visit(F, vector<bool>(C, false)), num(0) {
    for(int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!visit[i][j] && foto[i][j] == '.') { // se recorre una nueva mancha
                ++num;
                dfs(foto, i, j);
                }
            }
        }
    }

    int numero() const { return num - 1; }

private:

    int F, C; // tamaño del mapa
    vector<vector<bool>> visit; // visit[i][j] = se ha visitado el píxel <i,j>?
    int num; // número de manchas

    bool correcta(int i, int j) const { return 0 <= i && i < F && 0 <= j && j < C; }

    const vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(Foto const& foto, int i, int j) {
        visit[i][j] = true;
        for (auto d : dirs) {
            int ni = i + d.first, nj = j + d.second;
            if (correcta(ni,nj) && foto[ni][nj] == '.' && !visit[ni][nj]) {
                dfs(foto, ni, nj);
            }
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
      int F, C;
   // leer los datos de la entrada
   cin >> C >> F; // número de filas y columnas
   if (!std::cin)  // fin de la entrada
      return false;
    Foto foto(F);
    // leemos la imagen
    for (string & linea : foto) cin >> linea;
    // la analizamos
    Ovejas ovejas(foto);
   
   // escribir sol
   cout << ovejas.numero() << "\n"; 

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
