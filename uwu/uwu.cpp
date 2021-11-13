// Sonia Marcos de Benito
// F33

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// función que resuelve el problema

bool parc_ordenado(const vector<int>& datos, int& ini, int& fin, int& min, int& max) {
    int mitad;
    if(fin = ini){
        return true;
    }
    if (fin-ini == 2) {
        if (datos[ini] > datos[fin]  datos[ini]> max  datos[fin] < min) return false;
        else {
            min = datos[ini];
            max = datos[fin];
        }
    }
    else {
        mitad = fin-ini / 2;
        bool izq = parc_ordenado(datos, ini, mitad, min, max);
        bool der = parc_ordenado(datos, mitad, fin, min, max);
    }

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, min =INT_MIN, max= INT_MAX;
    cin >> n;
    if (n == 0)return false;
    vector<int> datos;
    while (n != 0) {
        datos.push_back(n);
        cin >> n;
    }
    int ini = 0, fin = datos.size()-1;
    bool sol = parc_ordenado(datos, ini, fin, min, max);

    if (sol) cout << "SI \n";
    else cout << "NO \n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}