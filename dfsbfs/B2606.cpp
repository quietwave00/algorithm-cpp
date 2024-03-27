/**
 * B2606_바이러스
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100];
bool visited[100];
int cnt = 0;

void DFS(int v) {
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++) {
        int next_v = graph[v][i];
        if(!visited[next_v]) {
            cnt++;
            DFS(next_v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
    DFS(1);

    cout << cnt << "\n";

    return 0;
}