/**
 * B1927_최소 힙
 * 우선순위 큐 활용
*/

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q; 
bool check(int num) {
    if(num == 0 && q.size() == 0) {
        cout << 0 << "\n";
        return false;
    } else if(num == 0){
        cout << q.top() << "\n";
        q.pop();
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        bool pushable = check(num);
        if(pushable) {
            q.push(num);
        }
    }
    return 0;
}