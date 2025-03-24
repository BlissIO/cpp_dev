//************************************************************
// Program #7
// Rayane EL YASTI
// due 3/25/2025
// Small Label First Implimentation
//************************************************************

#include <iostream>
#include <vector>
#include <deque>
#include <limits>

using namespace std;

class Graph {
private:
    int n;                                      // number of vertices
    vector<vector<pair<int, int>>> adj;         // adjacency list: (vertex, weight)

public:
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> smallLabelFirst(int src) {
        // Init distances to infinity
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;

        // Init deque and tracking array
        deque<int> dq;
        vector<bool> inDq(n, false);
        
        dq.push_back(src);
        inDq[src] = true;

        while (!dq.empty()) {
            // Extract front vertex
            int u = dq.front();
            dq.pop_front();
            inDq[u] = false;

            // Check all neighbors
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                // Relax edge if possible
                if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;

                    // Add to deque if not already there
                    if (!inDq[v]) {
                        // Small label first if v's label smaller than front put at front
                        if (!dq.empty() && dist[v] < dist[dq.front()]) {
                            dq.push_front(v);
                        } else {
                            dq.push_back(v);
                        }
                        inDq[v] = true;
                    }
                }
            }
        }

        return dist;
    }

    void printPaths(int src) {
        vector<int> dist = smallLabelFirst(src);
        
        cout << "Shortest paths from " << src << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == numeric_limits<int>::max())
                cout << "Vertex " << i << ": Not reachable\n";
            else
                cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(6);
    
    // Add edges: (from, to, weight)
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 2);
    
    g.printPaths(0);
    
    return 0;
}