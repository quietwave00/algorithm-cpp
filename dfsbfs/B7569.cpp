/**
 * B7569_토마토
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int cnt = 0;

// 상하좌우앞뒤
vector<int> dx = { -1, 1, 0, 0, 0, 0};
vector<int> dy = { 0, 0, -1, 1, 0, 0};
vector<int> dz = { 0, 0, 0, 0, -1, 1};

vector<vector<vector<int>>> graph;
queue<tuple<int, int, int>> q;

void BFS(int N, int M, int H) {
    while(!q.empty()) {
        auto [cur_x, cur_y, cur_z] = q.front();
        q.pop();

        // cout << "cur: " << cur_x << " " << cur_y << " " << cur_z  << " " << endl;

        for(int i = 0; i < 6; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_z = cur_z + dz[i];

            // cout << "next " << next_x << " " << next_y << " " << next_z << endl;

            if(next_x < 0 || next_y < 0 || next_z < 0) continue;
            if(next_x >= N || next_y >= M || next_z >= H) continue;
            if(graph[next_x][next_y][next_z] != 0) continue;

            q.push(make_tuple(next_x, next_y, next_z));
            graph[next_x][next_y][next_z] = graph[cur_x][cur_y][cur_z] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;
    graph.resize(N, vector<vector<int>>(M, vector<int>(H)));

    for(int i = 0; i < H; i++) { // z
        for(int j = 0; j < N; j++) { // x
            for(int k = 0; k < M; k++) { // y
                cin >> graph[j][k][i];
                if(graph[j][k][i] == 1) { // 익은 토마토에서 시작
                    q.push(make_tuple(j, k, i));
                }
            }
        }
    }
    BFS(N, M, H);

    // answer
    int days = 0;
    for(int i = 0; i < H; i++) { // z
        for(int j = 0; j < N; j++) { // x
            for(int k = 0; k < M; k++) { // y
                if(graph[j][k][i] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
                days = graph[j][k][i] > days ? graph[j][k][i] : days;
            }
        }
    }
    cout << days - 1 << "\n";

    return 0;
}
