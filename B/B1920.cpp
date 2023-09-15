#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(int key, vector<int> &target) {
    int low = 0;
    int high = target.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(key < target[mid]) {
            high = mid - 1;
        } else if(key > target[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
     * 입력
     */
    int N,M;
    vector<int> target, keys, answer;

    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int temp;
        cin >> temp;
        target.push_back(temp);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        keys.push_back(temp);
    }
    /*
     * 연산
     */
    sort(target.begin(), target.end());

    for(int key : keys) {
        (search(key, target) >= 0) ? answer.push_back(1) : answer.push_back(0);
    }

    /*
     * 출력
     */
    for(int value : answer) {
        cout << value << '\n';
    }
}