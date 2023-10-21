#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int m, int n, vector<string> board) {
    vector<vector<string>> blocks(m, vector<string>(n));

    //판 만들기
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            blocks[i][j] = board[i].substr(j, 1);
        }
    }

    int count = 0;
    while (true) {
        bool flag = false;
        vector<vector<bool>> flagBlocks(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j != 0) {
                    string target = blocks[i][j]; //대상
                    if (target.length() > 0 && target == blocks[i - 1][j - 1] && target == blocks[i - 1][j] && target == blocks[i][j - 1]) { 
                        flag = true;
                        flagBlocks[i][j] = true;
                        flagBlocks[i - 1][j - 1] = true;
                        flagBlocks[i - 1][j] = true;
                        flagBlocks[i][j - 1] = true;
                    }
                }
            }
        }
        if (!flag) break;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flagBlocks[i][j]) {
                    count++;
                    for (int k = i; k > 0; k--) {
                        blocks[k][j] = blocks[k - 1][j];
                        blocks[k - 1][j] = "";
                    }
                }
            }
        }
    }
    return count;
}

int main(void) {
    int m = 4;
    int n = 5;
    vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    cout << solution(m, n, board) << endl;
}
