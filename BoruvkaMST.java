/*
Borůvka's algorithm is a greedy algorithm for finding a minimum spanning tree in a graph, or a minimum spanning forest in the case of a graph that is not connected.
*/

/*
steps:
1) Input is a connected, weighted and un-directed graph.
2) Initialize all vertices as individual components (or sets).
3) Initialize MST as empty.
4) While there are more than one components, do following
   for each component.
      a)  Find the closest weight edge that connects this 
          component to any other component.
      b)  Add this closest edge to MST if not already added.  
5) Return MST.
*/

public class BoruvkaMST {
    private Bag<Edge> mst = new Bag<Edge>();    // edges in MST
    private double weight;                      // weight of MST

    // Boruvka's algorithm
    public BoruvkaMST(EdgeWeightedGraph G) {
        UF uf = new UF(G.V());

        // repeat at most log V times or until we have V-1 edges
        for (int t = 1; t < G.V() && mst.size() < G.V() - 1; t = t + t) {

            // foreach tree in forest, find closest edge
            // if edge weights are equal, ties are broken in favor of first edge in G.edges()
            Edge[] closest = new Edge[G.V()];
            for (Edge e : G.edges()) {
                int v = e.either(), w = e.other(v);
                int i = uf.find(v), j = uf.find(w);
                if (i == j) continue;   // same tree
                if (closest[i] == null || less(e, closest[i])) closest[i] = e;
                if (closest[j] == null || less(e, closest[j])) closest[j] = e;
            }

            // add newly discovered edges to MST
            for (int i = 0; i < G.V(); i++) {
                Edge e = closest[i];
                if (e != null) {
                    int v = e.either(), w = e.other(v);
                    // don't add the same edge twice
                    if (!uf.connected(v, w)) {
                        mst.add(e);
                        weight += e.weight();
                        uf.union(v, w);
                    }
                }
            }
        }

        // check optimality conditions
        assert check(G);
    }


    // edges in minimum spanning forest, as an Iterable
    public Iterable<Edge> edges() {
        return mst;
    }

    // weight of minimum spanning forest
    public double weight() {
        return weight;
    }

    // is the weight of edge e strictly less than that of edge f?
    private static boolean less(Edge e, Edge f) {
        return e.weight() < f.weight();
    }

    // check optimality conditions (takes time proportional to E V lg* V)
    private boolean check(EdgeWeightedGraph G) {

        // check weight
        double totalWeight = 0.0;
        for (Edge e : edges()) {
            totalWeight += e.weight();
        }
        double EPSILON = 1E-12;
        if (Math.abs(totalWeight - weight()) > EPSILON) {
            System.err.printf("Weight of edges does not equal weight(): %f vs. %f\n", totalWeight, weight());
            return false;
        }

        // check that it is acyclic
        UF uf = new UF(G.V());
        for (Edge e : edges()) {
            int v = e.either(), w = e.other(v);
            if (uf.connected(v, w)) {
                System.err.println("Not a forest");
                return false;
            }
            uf.union(v, w);
        }

        // check that it is a spanning forest
        for (Edge e : edges()) {
            int v = e.either(), w = e.other(v);
            if (!uf.connected(v, w)) {
                System.err.println("Not a spanning forest");
                return false;
            }
        }

        // check that it is a minimal spanning forest (cut optimality conditions)
        for (Edge e : edges()) {
            int v = e.either(), w = e.other(v);

            // all edges in MST except e
            uf = new UF(G.V());
            for (Edge f : mst) {
                int x = f.either(), y = f.other(x);
                if (f != e) uf.union(x, y);
            }

            // check that e is min weight edge in crossing cut
            for (Edge f : G.edges()) {
                int x = f.either(), y = f.other(x);
                if (!uf.connected(x, y)) {
                    if (f.weight() < e.weight()) {
                        System.err.println("Edge " + f + " violates cut optimality conditions");
                        return false;
                    }
                }
            }

        }

        return true;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        EdgeWeightedGraph G = new EdgeWeightedGraph(in);
        BoruvkaMST mst = new BoruvkaMST(G);
        for (Edge e : mst.edges()) {
            StdOut.println(e);
        }
        StdOut.printf("%.5f\n", mst.weight());
    }

}
