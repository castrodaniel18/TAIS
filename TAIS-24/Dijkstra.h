#include <limits>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), ult(g.V()), pq(g.V()), caminos(0), cole(g.V() - 1){
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

    int numCaminos(){ return caminos; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ult;
    IndexPQ<Valor> pq;
    int caminos;
    int cole;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ult[w] = a;
            pq.update(w, dist[w]);
            if(w == cole) caminos = 1;
        }
        else if (w == cole && dist[w] == dist[v] + a.valor()){
            caminos++;
        }
    }
};