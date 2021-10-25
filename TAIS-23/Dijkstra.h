#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, std::vector<int> tiempos, int orig) : origen(orig), dist(g.V(), INF), ult(g.V()), pq(g.V()), tiempos_carga(tiempos){
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
            relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ult;
    std::vector<int> tiempos_carga;
    IndexPQ<Valor> pq;
    
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + tiempos_carga[w]) {
            dist[w] = dist[v] + a.valor() + tiempos_carga[w]; ult[w] = a;
            pq.update(w, dist[w]);
        }
    }
};