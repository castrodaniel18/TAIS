#include <limits>
#include <queue>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig), destino(dest), dist(g.V(), {INF, INF}), pq(g.V()) {
        dist[origen].first = 0;
        dist[origen].second = 0;
        pq.push(origen, 0);
        dist_bfs = bfs(g);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
            relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v].first != INF; }

    Valor distancia(int v) const { return dist[v].first; }

    int min_aristas_bfs() { return dist_bfs; }

    int min_aristas_dijkstra() { return dist[destino].second; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int destino;
    std::vector<std::pair<Valor, Valor>> dist;
    IndexPQ<Valor> pq;
    int dist_bfs;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w].first > dist[v].first + a.valor()) {
            dist[w].first = dist[v].first + a.valor();
            pq.update(w, dist[w].first);
            dist[w].second = dist[v].second + 1;
        }
        else if (dist[w].first == dist[v].first + a.valor())
            if (dist[w].second > dist[v].second + 1)
                dist[w].second = dist[v].second + 1;
    }

    int bfs(DigrafoValorado<Valor> const& g){
        std::vector<int> visit(g.V());
        std::vector<int> dist_bfs(g.V());
        std::queue<int> cola;
        cola.push(origen);
        dist_bfs[origen] = 0;
        visit[origen] = true;
        while(!cola.empty()){
            int v = cola.front(); cola.pop();
            for(auto a: g.ady(v)){
                int w = a.hasta();
                if(!visit[w]){
                    visit[w] = true;
                    dist_bfs[w] = dist_bfs[v] + 1;
                    cola.push(w);
                }
            }
        }
        return dist_bfs[destino];
    }
};