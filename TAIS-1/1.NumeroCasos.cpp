
// Nombre y Apellidos Daniel Castro López

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
    Para resolver el problema necesitaremos una función auxiliar que devuelva 4 valores:
    - bool AVL -> indica si el árbol explorado es AVL.
    - int altura -> idica la altura del arbol explorado.
    - int min -> idica el minimo valor del arbol explorado.
    - int max -> idica el maximo valor del arbol explorado.

    Creamos el struct Sol para devolver los datos, y la función auxiliar funciona de la siguiente manera:

        En caso de encontrar un arbol vacio, sabemos que es AVL, los demas valores a devolver son arbitrarios.

        Si no es vacio:
            LLamamos a la recursion de la rama izquierda y derecha.
            Comprobamos que ambos sean AVL.
            La altura será la máxima de sus hijos + 1.
            Calculamos el minimo del arbol:
                Si el hijo izquierdo es vacio, será la misma raiz del arbol, y sino el mínimo encontrado al recorrer el arbol izquierdo.
            Calculamos el maximo del arbol:
                Si el hijo derecho es vacio, será la misma raiz del arbol, y sino el maximo encontrado al recorrer el arbol derecho.

*/


#include <iostream>
#include <fstream>
#include <tuple>
#include "bintree.h"

using namespace std;

struct Sol {
    bool AVL;
    int altura, minimo, maximo;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tuple<bool, int, int, int> resolver(bintree<int> arbol) {
    //en caso de que el arbol sea AVL
    if (arbol.empty()) return {true, 0, 0, 0};
    else {
        auto [iz_avl, iz_alt, iz_min, iz_max] = resolver(arbol.left());
        auto [der_avl, der_alt, der_min, der_max] = resolver(arbol.right());

        bool AVL = abs(iz_alt - der_alt) < 2;

        int altura = max(iz_alt, der_alt) + 1;

        if (arbol.left().empty()) iz_min = arbol.root();
        if (arbol.right().empty()) der_max = arbol.root();

        bool orden = (arbol.left().empty() || arbol.root() > iz_max) && (arbol.right().empty() || arbol.root() < der_min);
        
        return { iz_avl && der_avl && AVL && orden, altura, iz_min, der_max };
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   
   // leer los datos de la entrada
   bintree<int> arbol = leerArbol(-1);
   auto[sol, aux1, aux2, aux3] = resolver(arbol);
   // escribir solución
   if (sol) cout << "SI" << endl;
   else cout << "NO" << endl;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
