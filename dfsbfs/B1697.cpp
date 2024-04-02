/**
 * B1697_숨바꼭질
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, K; // 수빈이, 동생
int cnt = 0;
vector<bool> visited(MAX);
queue<pair<int, int>> q;

void BFS(int x) {
    visited[N] = true;
    q.push(make_pair(x, cnt));

    while(!q.empty()) {
        int cur_x = q.front().first;
        cnt = q.front().second;
        q.pop();

        cout << "cur_x: " << cur_x << endl;
        if(cur_x == K) {
            cout << cnt << "\n";
            break;
        }

        if(cur_x < MAX && cur_x > 0) {
            int next_x = cur_x + 1;
            cout << "next_x: " << next_x << endl;

            if(visited[next_x] == false) {
                visited[next_x] = true;
                q.push(make_pair(next_x, cnt++));
            }

            int prev_x = cur_x - 1;
            cout << "prev_x: " << prev_x << endl;
            if(visited[prev_x] == false) {
                visited[prev_x] = true;
                q.push(make_pair(prev_x, cnt++));
            }

            int double_x = cur_x * 2; 
            cout << "double_x: " << double_x << endl;
            if(visited[double_x] == false) {
                visited[double_x] = true;
                q.push(make_pair(double_x, cnt++));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    BFS(N);
    return 0;
}