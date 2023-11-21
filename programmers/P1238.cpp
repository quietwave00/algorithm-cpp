#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 1000 + 1;
const int INF = 987654321;

vector<pii> graph[MAX]; // v, d

void dijkstra(int source, vector<int>& dist) {
    /* 초기화 */
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source)); // d, v

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] < d) continue;

        for (int i = 0; i < graph[v].size(); i++) {
            int adj_v = graph[v][i].first;
            int adj_d = graph[v][i].second + d;

            if (adj_d < dist[adj_v]) {
                dist[adj_v] = adj_d;
                pq.push(make_pair(adj_d, adj_v));
        }
    }
    }
}

int main() {
    int N, M, X; // 정점, 간선, 시작점
    scanf("%d %d %d", &N, &M, &X);

    int S, E, T;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &S, &E, &T);
        graph[S].push_back(make_pair(E, T)); // S가 갈 수 있는 정점(=E)과 가중치 저장
    }

    int sum = 0;
    vector<int> dist_from(N + 1, INF);
    vector<int> dist_to(N + 1, INF);
    for (int i = 1; i <= N; i++) {
        dijkstra(i, dist_from); // i에서 다른 정점으로 가는 최단거리
        dijkstra(X, dist_to); // X에서 i로 돌아오는 최단거리

        int result1 = dist_from[X];
        int result2 = dist_to[i];

        int total_distance = result1 + result2;
        if (sum < total_distance) sum = total_distance;
    }
    cout << sum << endl;

    return 0;
}