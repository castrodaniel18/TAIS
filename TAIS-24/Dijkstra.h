#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), ult(g.V()), pq(g.V()), num_caminos(g.V(), 0){
        dist[origen] = 0;
        pq.push(origen, 0);
        num_caminos[origen] = 1;
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
            relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    Valor distancia(int v) const { return dist[v]; }

    int numCaminos(int v) const { return num_caminos[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ult;
    IndexPQ<Valor> pq;
    std::vector<int> num_caminos;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ult[w] = a;
            pq.update(w, dist[w]);
            num_caminos[w] = num_caminos[v];
        }
        else if (dist[w] == dist[v] + a.valor()){
            num_caminos[w] += num_caminos[v];
        }
    }
};