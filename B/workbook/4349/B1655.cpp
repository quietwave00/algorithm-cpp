/**
 * B1655_가운데를 말해요
 * 최대힙과 최소힙
*/

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

priority_queue<int, vector<int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    priority_queue<int, vector<int>, greater<int>> min_q;
    priority_queue<int, vector<int>> max_q;
    for(int i = 0; i < N; i++) {
        if(max_q.size() > min_q.size()) {
            min_q.push(vec[i]);
        } else {
            max_q.push(vec[i]);
        }

        if(!max_q.empty() && !min_q.empty()) {
            if(max_q.top() > min_q.top()) {
                int num1 = max_q.top();
                max_q.pop();

                int num2 = min_q.top();
                min_q.pop();

                max_q.push(num2); // 최소힙의 값
                min_q.push(num1);
            }
        }
        cout << max_q.top() << "\n";
    }

    return 0;
}