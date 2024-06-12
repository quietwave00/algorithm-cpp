#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr; //그림2
vector<int> dx = {0, 1, 0, -1}; //y축 방향
vector<int> dy = {1, 0, -1, 0}; //x축 방향
int totalCount = 0;
int cnt = 0;
vector<int> countList;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = 0; //받은 값은 방문

    while (!q.empty()) {
        cnt++;
        pair<int, int> point = q.front();
        q.pop();
        x = point.first;
        y = point.second;

        for (int i = 0; i < 4; i++) { //동남서북
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (arr[nx][ny] != 0) { //옮긴 좌표가 0이 아니면
                arr[nx][ny] = 0; //방문 처리 해주고
                q.push({nx, ny}); //큐에 넣어줌
            }
        }
    }
}

int main() {
    /**
     * Input
     */
    cin >> N;
    arr.resize(N + 2, vector<int>(N + 2, 0)); //상하, 좌우 0으로 채울거

    for (int i = 1; i <= N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            arr[i][j + 1] = row[j] - '0';
        }
    }

    /**
     * Sol
     */
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt = 0;
            if (arr[i][j] == 1) {
                bfs(i, j);
                countList.push_back(cnt);
                totalCount++;
            }
        }
    }

    /**
     * Output
     */
    sort(countList.begin(), countList.end());
    cout << totalCount << endl;
    for (int count : countList) {
        cout << count << endl;
    }

    return 0;
}