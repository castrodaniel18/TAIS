
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

using namespace std;

struct bateria{
    int id;
    int capacidad;
    int restante;
};

struct ordena_capacidad{
    bool operator()(bateria const& a, bateria const& b){
    return a.capacidad < b.capacidad;
    }
};

struct ordena_id{
    bool operator()(bateria const& a, bateria const& b){
    return a.id < b.id;
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<bateria, ordena_capacidad>& en_funcionamiento, queue<bateria>& en_base, int Z, int T, int B) {
    int tiempo = 0, pasado;
    bool abandonar = false;
    PriorityQueue<bateria, ordena_id> gastadas;
    queue<bateria> cola_aux;
    bateria aux;
    while(tiempo < T && !abandonar){
        if(tiempo + en_funcionamiento.top().restante < T) pasado = en_funcionamiento.top().restante;
        else pasado = T - tiempo;
        tiempo += pasado;
        while(!en_funcionamiento.empty()){
            aux = en_funcionamiento.top(); en_funcionamiento.pop();
            if(aux.restante - pasado == 0)
                gastadas.push(aux);
            else {
                aux.restante -= pasado;
                cola_aux.push(aux);
            }
        }
        while(!cola_aux.empty()){
            aux = cola_aux.front(); cola_aux.pop();
            en_funcionamiento.push(aux);
        }
        if(tiempo < T){
            while(!gastadas.empty()){
                aux = gastadas.top();gastadas.pop();
                aux.capacidad -= Z;
                aux.restante = aux.capacidad;
                if (aux.capacidad > 0) en_funcionamiento.push(aux);
            }
            while(!en_base.empty() && en_funcionamiento.size() != B){
                en_funcionamiento.push(en_base.front()); en_base.pop();
            }
            if(en_funcionamiento.empty()) abandonar = true;
        }
    }
    return tiempo;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int B, b, R, Z, T, id;
    // leer los datos de la entrada
    cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<bateria, ordena_capacidad> en_funcionamiento;
    int i;
    for(i = 1; i <= B; i++){
        cin >> b;
        en_funcionamiento.push({i, b, b});
    }

    queue<bateria> en_base;
    cin >> R;
    for(int j = 0; j <  R; j++){
        cin >> b;
        en_base.push({i + j, b, b});
    }
    cin >> Z >> T;
    int sol = resolver(en_funcionamiento, en_base, Z, T, B);
    if(en_funcionamiento.empty()) cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    else if (en_funcionamiento.size() !=  B) cout << "FALLO EN EL SISTEMA\n";
    else cout << "CORRECTO\n";
    while(!en_funcionamiento.empty()){
        cout << en_funcionamiento.top().id << " "<<en_funcionamiento.top().restante + sol << "\n";
        en_funcionamiento.pop();
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
