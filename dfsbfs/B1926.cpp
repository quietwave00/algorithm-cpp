/**
 * B1926_그림
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int height, width;
vector<vector<int>> graph;
queue<pair<int, int>> q;
vector<int> area_vec;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void BFS(int x, int y) {
    graph[x][y] = 0;
    q.push(make_pair(x, y));

    int area = 1;
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(next_x >= 0 && next_x < height && next_y >= 0 && next_y < width && graph[next_x][next_y] == 1) {
                area++; // 한 정점에 대해 방문할 수 있는 경우에 접근한 거니까 여기서 area++
                graph[next_x][next_y] = 0;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    area_vec.push_back(area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    graph.resize(height, vector<int>(width, 0));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(graph[i][j] == 1) {
                BFS(i, j);
                count++;
            }
        }
    }

    if (!area_vec.empty()) {
        auto max = max_element(area_vec.begin(), area_vec.end());
        printf("%d\n%d", count, *max);
    } else {
        printf("%d\n%d", count, 0);
    }

    return 0;
}