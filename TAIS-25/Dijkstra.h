#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()), minimo_aristas(g.V(), pair(INF, INF)) {
        dist[origen] = 0;
        pq.push(origen, 0);
        minimo_aristas[origen] = {0, 0};
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
            relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    Valor distancia(int v) const { return dist[v]; }

    bool camino_menor_aristas(int v){
        if(minimo_aristas[v].second == dist[v]) return true;
        return false;
    }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    IndexPQ<Valor> pq;
    vector<pair<Valor, Valor>> minimo_aristas;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }

        if(minimo_aristas[v].first + 1 < minimo_aristas[w].first){
            minimo_aristas[w] = {minimo_aristas[v].first + 1, dist[v] + a.valor()};
        }
        else if (minimo_aristas[v].first + 1 == minimo_aristas[w].first){
             if (minimo_aristas[w].second > minimo_aristas[v].second + a.valor()) 
                minimo_aristas[w] = {minimo_aristas[v].first + 1, dist[v] + a.valor()};
        }
    }
};