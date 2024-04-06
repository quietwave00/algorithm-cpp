/**
 * B5014_스타트링크
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int cur_x, cnt;
vector<bool> graph(1000000);
queue<pair<int, int>> q;

void BFS(int x) {
    q.push(make_pair(x, 0));

    while(!q.empty()) {
        cur_x = q.front().first;
        cnt = q.front().second;
        q.pop();

        // cout << "cur_x = " << cur_x << endl;
        if(cur_x == G) {
            cout << cnt << "\n";
            break;
        }

        int up_x = cur_x + U;
        // cout << "up_x = " << up_x << endl;
        if(up_x <= F && graph[up_x] == false) {
            graph[up_x] = true;
            q.push(make_pair(up_x, cnt + 1));
        }

        int down_x = cur_x - D;
        // cout << "down_x: " << down_x << endl;
        if(down_x >= 1 && graph[down_x] == false) {
            graph[down_x] = true;
            q.push(make_pair(down_x, cnt + 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;
    BFS(S);

    if(graph[G] == false) {
        cout << "use the stairs" << "\n";
    }

    return 0;
}