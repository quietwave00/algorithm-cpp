#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 1000 + 1;
const int INF = 987654321;

vector<pair<int, int>> graph[MAX];
int s, e; //start, end
int result;

void dijkstra(int source, int vertex) {
    /* 초기화 */
    vector<int> dist(vertex, INF);
    dist[source] = 0;

    /* 우선순위 큐 생성 */
    priority_queue<pii, vector<pii>, greater<pii>> pq; // distance, vertex
    pq.push(make_pair(dist[source], source));

    while(!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(dist[v] < d) continue;

        if(v == e) {
            result = dist[v];
            break;
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
}

int main() {
    int N, M; //정점, 간선
    cin >> N >> M;

    int u, v, w; // u -> v : w
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w)); // 시작점별로 갈 수 있는 곳 가중치랑 저장
    }

    cin >> s >> e;

    dijkstra(s, N + 1);
    cout << result << endl;

    return 0;
}