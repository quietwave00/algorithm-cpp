/**
 * B2479_계단오르기
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> score(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    vector<int> stair(n + 1);
    // 초기값
    stair[1] = score[1];
    stair[2] = score[1] + score[2];
    stair[3] = max(score[1] + score[3], score[2] + score[3]);

    for(int i = 4; i <= n; i++) {
        int score_x = stair[i - 2] + score[i];
        int score_y = stair[i - 3] + score[i - 1] + score[i];
        stair[i] = max(score_x, score_y);
    }

    cout << stair[n] << '\n';

    return 0;
}