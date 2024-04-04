/**
 * B1697_숨바꼭질
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, K; // 수빈이, 동생
// int cnt = 0;
vector<bool> graph(MAX);
queue<pair<int, int>> q;

void BFS(int x) {
    q.push(make_pair(x, 0));

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // cout << "cur_x: " << cur_x << endl;
        if(cur_x == K) {
            cout << cnt << "\n";
            break;
        }

        

        int prev_x = cur_x - 1;
        // cout << "prev_x: " << prev_x << endl;
        if(prev_x >= 0 && graph[prev_x] == false) {
            graph[prev_x] = true;
            q.push(make_pair(prev_x, cnt + 1));
        }
        
        int next_x = cur_x + 1;
        // cout << "next_x: " << next_x << endl;

        if(next_x <= K && graph[next_x] == false) {
            graph[next_x] = true;
            q.push(make_pair(next_x, cnt + 1));
        }

        int double_x = cur_x * 2; 
        // cout << "double_x: " << double_x << endl;
        if(double_x <= K + 1 && graph[double_x] == false) {
            graph[double_x] = true;
            q.push(make_pair(double_x, cnt + 1));
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