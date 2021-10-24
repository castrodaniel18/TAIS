#include <limits>
#include <cassert>

#include "GrafoValorado.h"
#include "IndexPQ.h"


template <typename Valor>
class Prim {

public:

   Prim(GrafoValorado<Valor> const& g) : distTo(g.V(), std::numeric_limits<Valor>::max()),
   marked(g.V(), false), pq(g.V()), coste(0), vertices(0) {
      distTo[0] = 0;
      pq.push(0, 0);
      while (!pq.empty()) {
         int w = pq.top().elem; pq.pop();
         coste += distTo[w];
         ++vertices;
         visit(g, w);
      }
      existe = (vertices == g.V());
   }

   bool hayARM() const {
      return existe;
   }

   Valor costeARM() const {
      return coste;
   }

private:
   std::vector<Valor> distTo;
   std::vector<bool> marked;
   IndexPQ<Valor> pq;
   Valor coste;
   int vertices; // vértices en el ARM
   bool existe; // hay ARM?

   void visit(GrafoValorado<Valor> const& g, size_t v){
      marked[v] = true;
      for (auto e : g.ady(v)){
         int w = e.otro(v);
         if (!marked[w] && e.valor() < distTo[w]){
            distTo[w] = e.valor();
            pq.update(w, distTo[w]);
         }
      }
   }

};