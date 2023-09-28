#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N, answer;
vector<int> lengths;

int search(vector<int> lengths, int number) {
    unsigned int low, mid = 0;
    unsigned int high = lengths.back() + 1;
    while(low < high) {
        mid = (low + high) / 2;
        unsigned int count = 0;
        for(int i = 0; i < lengths.size(); i++) {
            count += (lengths[i] / mid);
        }

        if(count < N) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low - 1;
}

int main(void) {
    /*
     * 입력
     */
    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        lengths.push_back(temp);
    }
    sort(lengths.begin(), lengths.end());

    /*
     * 연산, 출력
     */
    cout << search(lengths, N);
}