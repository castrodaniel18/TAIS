// Nombre y Apellidos Daniel Castro López

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct caja {
    int num;
    int seg;
};

struct comp_caja {
    bool operator ()(caja const &a, caja const& b){
        return a.seg > b.seg || (a.seg == b.seg && a.num > b.num);
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<caja, vector<caja>, comp_caja>& cola, queue<int>& clientes) {
    while(!clientes.empty()){
        caja a = cola.top();
        cola.pop();
        cola.push({ a.num, clientes.front() + a.seg});
        clientes.pop();
    }
    return cola.top().num;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int cajas, p, seg, sol, aux;
    priority_queue<caja, vector<caja>, comp_caja> cola;
    cin >> cajas;
    if (cajas == 0)
        return false;
    cin >> p;
    queue<int> clientes;
    for (int i = 1; i <= cajas; i++) {
        cola.push({ i, 0 });
    }
    for (int i = 0; i < p; i++) {
        cin >> aux;
        clientes.push(aux);
    }
    sol = resolver(cola, clientes);
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