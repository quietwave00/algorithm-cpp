/**
 * B2004_조합 0의 개수
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

long long cal_two(int num) {
    int count = 0;
    while(num >= 2) {
        count += num / 2;
        num /= 2;
    }
    return count;
}

long long cal_five(int num) {
    int count = 0;
    while(num >= 5) {
        count += num / 5;
        num /= 5;
    }
    return count;
}

int main() {    
    cin >> N >> M;

    long long count_2 = cal_two(N) - cal_two(N-M) - cal_two(M);
    long long count_5 = cal_five(N) - cal_five(N-M) - cal_five(M);

    cout << min(count_2, count_5) << '\n';

    return 0;
}