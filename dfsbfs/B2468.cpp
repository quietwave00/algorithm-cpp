/**
 * B2468_안전 영역
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int max_height = 0;
vector<vector<int>> graph;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(vector<vector<int>>& temp_graph, int x, int y, int target) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    temp_graph[x][y] = 0;

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
            if(temp_graph[next_x][next_y] > target) {
                temp_graph[next_x][next_y] = 0;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            max_height = max(max_height, graph[i][j]);
        }
    }

    int answer = 0;
    for(int i = 0; i < max_height; i++) {
        vector<vector<int>> temp_graph = graph;
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(temp_graph[j][k] > i) {
                    BFS(temp_graph, j, k, i);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }

    cout << answer << endl;

    return 0;
}
