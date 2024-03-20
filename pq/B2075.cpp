/**
 * B2075_N번째 큰 수
 * 우선순위 큐 활용
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> q;
    int num;
    for(int i = 0; i < N * N; i++) {
        cin >> num;
        q.push(num);
        if(q.size() > N) {
            q.pop();
        }
    }
    cout << q.top();
    return 0;
}