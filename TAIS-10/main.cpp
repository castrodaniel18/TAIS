/*@ <answer>
 *
 * Nombre y Apellidos: 
 *
 *@ </answer> */

#include <fstream>
#include "Grafo.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class Arboles_libres {
public:
    Arboles_libres(Grafo const& grafito) : visitado(vector<bool>(grafito.V(), false)), aciclico(true), conexo(true) {
        
        Adys lista_ady = grafito.ady(0);
        dfs(grafito, lista_ady, 0, 0);
        if (aciclico) {
            for (int i = 0; i < grafito.V(); ++i) {
                if (visitado[i] == false) conexo = false;
            }
        }
    }

    bool aci() const { return aciclico; }
    bool con() const { return conexo; }
private:
    vector<bool> visitado;
    bool aciclico;
    bool conexo;
         
    void dfs(Grafo const& grafito, Adys lista_ady, int vertice, int anterior) {
        visitado[vertice] = true;
        for (int i = 0; i < lista_ady.size(); i++){
            if (aciclico) {
                int nuevo = lista_ady.at(i);
                if (nuevo != anterior){
                   if(visitado[lista_ady.at(i)]) 
                       aciclico = false;
                   else 
                       dfs(grafito, grafito.ady(nuevo), nuevo, vertice);
                }
            }
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
    // leer los datos de la entrada

    Grafo grafito(cin);

    if (!std::cin)  // fin de la entrada
        return false;
    Arboles_libres arboles(grafito);
    if (arboles.aci() && arboles.con()) cout << "SI \n";
    else cout << "NO \n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
