#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


// 5 4 1 1

// 1 o 1 o
// o o o o
// o o o o
// o o o o
// o o o o


int main() {

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    // 세로로 앉을 수 있는 개수
    int h_sheet = ceil(static_cast<double>(H) / (N + 1)); // 5 / 2


    // 가로로 앉을 수 있는 개수
    int w_sheet = ceil(static_cast<double>(W) / (M + 1));

    // 앉을 수 있는 개수
    int result = h_sheet * w_sheet;

    cout << result << endl;
    
    return 0;
}