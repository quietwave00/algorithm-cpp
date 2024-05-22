/**
 * B2309_일곱난쟁이
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nine(9);
    int nine_sum = 0;
    for(int i = 0; i < 9; i++) {
        cin >> nine[i];
        nine_sum += nine[i];
    }

    int L = 0;
    int R = 8;
    sort(nine.begin(),nine.end());

    while(L < R) {
        if(nine_sum - (nine[L] + nine[R]) == 100) {
            break;
        } else if(nine_sum - (nine[L] + nine[R]) > 100) {
            L++;
        } else {
            R--;
        }
    }

    // cout << "L: " << L << endl;
    // cout << "R: " << R << endl;
    // cout << "===" << endl;

    for(int i = 0; i < 9; i++) {
        if(i == L || i == R) continue;
        cout << nine[i] << '\n';
    }

    return 0;
}