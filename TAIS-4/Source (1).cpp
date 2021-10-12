
/*@ <answer>
 *
 * Nombre y Apellidos: Sonia Marcos de Benito
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include <queue>  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct registro {
    int grav;
    int name;
};

struct comparador {
    bool operator()(registro const& a, registro const& b) {
        return a.grav > b.grav;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int num, gravedad;
    char caso;
    string nombre;
    cin >> num;

    if (num == 0) return false;

    priority_queue<registro, vector<registro>, comparador> cola;
    

    for (int i = 0; i < num; i++) {
        switch (caso) {
        case 'I':
        {
            cin >> nombre >> gravedad;
            cola.push({ nombre, nombre, gravedad });
        }
        break;
        case 'A':
        {
            auto e = cola.top();
            cola.pop();
            cout << e.name << "\n";
        }
        break;
        }
    }   
    cout << "---\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
