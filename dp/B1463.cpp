/**
 * B1463_1로 만들기
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1);
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3)) dp[i] = min(dp[i],dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    cout << dp[N] << '\n';

    return 0;
}