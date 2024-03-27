/**
 * B2644_촌수계산
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100];
vector<bool> visited(100);
int answer = 0;

void DFS(int cur_v, int end_v, int cnt) {
    // cout << "cur_v: " << cur_v << endl;
    visited[cur_v] = true;
    
    if(cur_v == end_v) {
        answer = cnt;
    }
    for(int i = 0; i < graph[cur_v].size(); i++) {
        int next_v = graph[cur_v][i];
        // cout << "next_v: " << next_v << endl;
        if(!visited[next_v]) {
            DFS(next_v, end_v, cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int v, v1, v2, e;
    cin >> v >> v1 >> v2 >> e;

    for(int i = 0; i < e; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
    DFS(v1, v2, 0);

    answer = answer == 0 ? -1 : answer;
    cout << answer << "\n";

    return 0;
}