/**
 * B2178_미로탐색
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


int height, width;
vector<vector<int>> graph;
queue<pair<int, int>> q;
int dx[] = { -1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1};



void BFS(int x, int y) {
    // 방문 순서 알기 위해 방문값으로 할당하지 않는다
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= 0 && next_x < height && next_y >= 0 && next_y < width && graph[next_x][next_y] == 1) {
                graph[next_x][next_y] = graph[cur_x][cur_y] + 1; // 방문값 0으로 바꿔주는 게 아닌 방문 순서
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    graph.resize(height, vector<int>(width, 0));

    for(int i = 0; i < height; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < width; j++) {
            graph[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            BFS(i, j);
        }
    }

    cout << graph[height - 1][width - 1] << "\n";
    return 0;
}