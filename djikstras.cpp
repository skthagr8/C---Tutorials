#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii; // Pair to store (distance, vertex)

void dijkstra(int source, const vector<vector<pii>>& graph, int V) {
    // Distance vector, initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Priority queue (min-heap) to store vertices and their distances
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});  // Push the source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the node with the smallest distance
        pq.pop();

        // Explore all neighbors of u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push the neighbor with the updated distance
            }
        }
    }

    // Output the shortest distances from the source
    for (int i = 0; i < V; ++i) {
        cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<pii>> graph(V);

    // Add edges to the graph (u, v, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({0, 10});
    graph[1].push_back({3, 2});
    graph[2].push_back({0, 5});
    graph[2].push_back({3, 1});
    graph[3].push_back({1, 2});
    graph[3].push_back({2, 1});

    int source = 0;
    dijkstra(source, graph, V);

    return 0;
}
