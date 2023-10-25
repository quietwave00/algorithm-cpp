#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 20000 + 1;
const int INF = 987654321;

vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int source, int vertex) {
    vector<int> dist(vertex, INF);
    dist[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // distance, vertex
    pq.push(make_pair(dist[source], source));
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (dist[v] < d) {
            continue;
        }
        
        for (int i = 0; i < graph[v].size(); i++) {
            int adj_d = d + graph[v][i].second;
            int adj_v = graph[v][i].first;
            
            if (adj_d < dist[adj_v]) {
                dist[adj_v] = adj_d;
                pq.push(make_pair(adj_d, adj_v));
            }
        }
    }
    
    return dist;
}

// Vertex, Edge
int main() {
    int V, E, K, u, v, w;
    scanf("%d%d%d", &V, &E, &K);
    
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &u, &v, &w); // u -> v : w
        graph[u].push_back(make_pair(v, w)); // 단방향
    }
    
    vector<int> result = dijkstra(K, V + 1);
    
    for (int i = 1; i <= V; i++) {
        if (result[i] == INF) cout << "INF" << endl;
        else cout << result[i] << endl;
    }
    
    return 0;
}
