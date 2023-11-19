#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 500 + 1;
const int INF = 987654321;
vector<pair<pii, int>> v; 
int dist[MAX]; 

void bellmanFord(int n) { 
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < v.size(); pos++) {
            int from = v[pos].first.first; // s
            int to = v[pos].first.second; // e
            int cost = v[pos].second; // w

            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost; // 시작 정점에서 끝 정점까지의 거리
            }
        }
    }

    for (int pos = 0; pos < v.size(); pos++) {
        int from = v[pos].first.first; // s
        int to = v[pos].first.second; // e
        int cost = v[pos].second; // w
        if (dist[from] + cost < dist[to]) { // 음수 사이클이 존재하는 경우
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        v.clear(); // 초기화
        int n, m, w; 
        cin >> n >> m >> w; 
        for (int i = 1; i <= n; i++) dist[i] = INF; // 모든 정점의 거리를 최대값으로 초기화

        for (int i = 0; i < m; i++) { // 간선, 방향 ᄂᄂ
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_pair(make_pair(from, to), cost)); 
            v.push_back(make_pair(make_pair(to, from), cost)); // 양방향이므로 반대 방향으로도 저장
        }
        for (int i = 0; i < w; i++) { // 웜홀, 음수
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_pair(make_pair(from, to), -cost));
        }
        bellmanFord(n);
    }
    return 0;
}