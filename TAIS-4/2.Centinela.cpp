//
//// Nombre y Apellidos Daniel Castro López
//
//// Comentario general sobre la solución,
//// explicando cómo se resuelve el problema
//
//#include <iostream>
//#include <fstream>
//#include "PriorityQueue.h"
//
//using namespace std;
//
//
////struct para representar la informacion de los usuarios
//struct registro {
//	int momento; // cuándo le toca
//	int id; // identificador (se utiliza en caso de empate)
//	int periodo; // tiempo entre consultas
//};
//
////sobrecarga del operador <
//bool operator<(registro const& a, registro const& b) {
//	return a.momento < b.momento ||
//		(a.momento == b.momento && a.id < b.id);
//}
//
//// resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//	int N; // número de usuarios registrados
//	cin >> N;
//	if (N == 0) return false; // no hay más casos
//	PriorityQueue<registro> cola;
//	// leemos los registros
//	for (int i = 0; i < N; ++i) {
//		int id_usu, periodo;
//		cin >> id_usu >> periodo;
//		cola.push({ periodo, id_usu, periodo });
//	}
//	int envios; // número de envíos a mostrar
//	cin >> envios;
//	while (envios--) {
//		auto e = cola.top(); cola.pop();
//		cout << e.id << '\n';
//		e.momento += e.periodo;
//		cola.push(e);
//	}
//	cout << "---\n";
//	return true;
//}
//
//int main() {
//   // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//   std::ifstream in("casos.txt");
//   auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//   
//   while (resuelveCaso());
//   
//   // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//   std::cin.rdbuf(cinbuf);
//   system("PAUSE");
//#endif
//   return 0;
//}







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
    string name;
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
    string nombre;//el nombre es un string bb
    cin >> num;

    if (num == 0) return false;

    priority_queue<registro, vector<registro>, comparador> cola;

    cin >> caso; //tienes que inicializar caso antes del switch ^^
    for (int i = 0; i < num; i++) {
        switch (caso) {
        case 'I':
        {
            cin >> nombre >> gravedad;
            registro r;
            r.name = nombre;
            r.grav = gravedad;
            cola.push(r);//tienes que hacer un push de un registro , no puedes usar llaves ♥
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
