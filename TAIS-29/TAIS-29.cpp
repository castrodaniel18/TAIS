
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
---------------------------------------------------------------------------------------------------------------------
0------------------n-1
E[0] <= E[1]-------E[n-1]
                          i              l
Voraz    V[0]V[1]--------V[i]
          ||  ||          X
Óptima   O[0]O[1]--------O[i]           O[l]

Sabemos que:
    - E[i] <= E[l]
    - B[V[i]] >= B[O[i]]

    Si se ha asignado una solución el la voraz, se asignará mas adelante,
    de tal forma que habrá una posición V[i] = O[l].
    Si los intercambiamos:
    ANTES (B[O[i]] - E[i])
          (B[V[i]]- E[l])
    DESPUÉS (B[V[i]] - E[i])
            (B[O[i]] - E[l])
    
CASO 1: La voraz gana B[V[i]] >= E[i]
    CASO 1.1: La óptima también gana B[O[i]] >= E[i]

Vamos a intercambiar en O la posición I y la posición i de forma que O'1)=j y O'T]=i
para que se parezca más a V.
En la suma de éxitos los términos que se ven afectados son
(BU]-Eli]) y (B[i]-E(l) que se cambiarían por (B(i)-E[i]) y (BÜ]-EU])
CASO 1: Bli]<E[i]. En este caso BU]<=B(i]<E[1]<=E(l). La suma no cambia porque los
cuatro términos son negativos así que suman 0.
CASO 2: B(i]>=E(1] y Bü]>=E(1). En este caso Büj)>=E(1]>=E(] y BU]>= BO]>=El) y los
cuatro términos suman, pero (BU]-E(i])+ (B[]-E(0)= (BU]-E(i])+(BU]-E(1])
CASO 3: B[i]>=E(i] y Bü]«E(l). En estos casos solo suma (B(i]-E[i]) tras el intercambio,
pero veamos que es mayor que lo anterior
Veamos el caso en que suman ambos, (BÜj]-E[1]) y (B(]-E[I]), y que se cumple que al
hacer el intercambio la solución optima no empeora, es decir:
(BU]-E(]) + (B(Ü)-E(1)) <= B(i]-Eli)
Los casos en que alguno o los dos no suman son menores así que tampoco empeoran.
(B(¡l-E[i]) + (Bli)-E(IN)

---------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<int, vector<int>, greater<int>> rivales, priority_queue<int, vector<int>, less<int>> broncos) {
    int sol = 0;
    bool derrota = false;
    while(!rivales.empty() && !derrota){
        if(rivales.top() < broncos.top()){
            sol += broncos.top() - rivales.top();
            rivales.pop();
            broncos.pop();
        }
        else derrota = true;
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, dato;
    // leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;
    priority_queue<int, vector<int>, greater<int>> rivales;
    priority_queue<int, vector<int>, less<int>> broncos;

    for(int i = 0; i < n; i++){
        cin >> dato;
        rivales.push(dato);
    }
    for(int i = 0; i < n; i++){
        cin >> dato;
        broncos.push(dato);
    }
    int sol = resolver(rivales, broncos);

    // escribir sol
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
