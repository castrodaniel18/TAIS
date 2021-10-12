// Nombre y Apellidos Daniel Castro L�pez

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct Persona{
    string nombre;
    int gravedad;
    int pos;
};

struct comp_persona {
    bool operator () (Persona const& a, Persona const& b) {
        return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && a.pos < b.pos);
    }
};


class ColaUrgencias {
public:
    ColaUrgencias(){
        i = 20000;
    };

    void ingresarPaciente(std::string nombre, int gravedad){
        pq.push({nombre, gravedad, i});
        i--;
    }

    std::string nombrePrimero() const{
        return pq.top().nombre;
    }
    void atenderPaciente(){
        pq.pop();
    }

private:
    priority_queue<Persona, vector<Persona>, comp_persona> pq;
    int i;
};





// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(ColaUrgencias& c) {
    string sol = c.nombrePrimero();
    c.atenderPaciente();
    cout << sol << "\n";
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int e, gravedad;
    string nombre, accion;
    ColaUrgencias datos;
    cin >> e;
    if (e == 0)
        return false;
    for (int i = 0; i < e; i++) {
        cin >> accion;
        if (accion == "A") resolver(datos);
        else {
            cin >> nombre;
            cin >> gravedad;
            datos.ingresarPaciente(nombre, gravedad);
        }
    }
    cout << "---\n";
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