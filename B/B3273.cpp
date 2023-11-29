#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /* 입력 */
    int n; //크기
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    int x; //찾는값
    cin >> x;

    /* 연산 */
    sort(vec.begin(), vec.end()); //정렬

    int sum = 0;
    int count = 0;
    int left = 0;
    int right = n - 1;
    for(int i = 0; i < vec.size(); i++) {
        if(left >= right) break; //스타트가 커지면 안됨

        sum = vec[left] + vec[right];
        if(sum == x) {
            count++;
            left++;
            right--;
        } else if(sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << endl;

    return 0;
}