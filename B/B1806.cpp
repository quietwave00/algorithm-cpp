#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    /* 입력 */
    int N, S; //길이, 타겟
    cin >> N >> S;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    /* 연산 */
    sort(vec.begin(), vec.end());

    int sum = 0;
    int left = 1;
    int right = 1;
    vector<int> length_vec;
    while(left <= right && right < N) {
        if(left == sum) length_vec.push_back(1);
        if(sum > S) {
            sum = sum - vec[left];
            left++;
        } else {
            if(sum == S) length_vec.push_back(right - left + 1);
            right++;
            sum = sum + vec[right];
        }
        // cout << "sum: " << sum << endl;
    }

    if(length_vec.size() == 0) {
        cout << 0 << endl;            
    } else {
        sort(length_vec.begin(), length_vec.end());
        cout << length_vec[0] << endl;
    }

    return 0;
}