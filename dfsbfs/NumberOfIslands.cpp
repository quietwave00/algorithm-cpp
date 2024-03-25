/**
 * leetcode 200
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void BFS(vector<vector<char>>& grid, int m, int n, int x, int y) {
        grid[x][y] = '0'; // 방문 처리
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));

        while(!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int i = 0; i  < 4; i++) { // 상하좌우
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] == '1') { // 범위 내, 방문 체크
                    grid[next_x][next_y] = '2'; // 방문 처리
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') { // 돌다가 1을 마주치면
                    BFS(grid, m, n, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int answer = Solution().numIslands(grid);
    cout << answer << endl;

    return 0;
}