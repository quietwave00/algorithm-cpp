#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


const int MAX = 1000 + 1;
const int INF = 987654321;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int source, int vertex) {
    /* 초기화 */
    vector<int> dist(vertex, INF); //정점을 모두 무한으로
    dist[source] = 0; //시작점은 0으로

}

int main() {
    int N, M, X; //정점, 간선, 시작점
    scanf("%d%d%d", &N, &M, &X);
    
    int S, E, T;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &S, &E, &T);
        graph[S].push_back(make_pair(E, T)); //S가 갈 수 있는 정점(=E)과 가중치 저장
    }

    vector<int> result = dijkstra(X, N + 1); //시작점에서 시작해서 정점 개수만큼



    return 0;
}