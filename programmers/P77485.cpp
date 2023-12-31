#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows + 1, vector<int>(columns + 1, 0));
    int cnt = 1;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            arr[i][j] = cnt;
            cnt += 1;
        }
    }

    for (const auto& t : queries) {
        int low_num = rows * columns;
        int prev_num = arr[t[0]][t[1]];
        low_num = min(low_num, prev_num);

        for (int i = t[1] + 1; i <= t[3]; ++i) {
            int temp_num = arr[t[0]][i];
            arr[t[0]][i] = prev_num;
            prev_num = temp_num;
            low_num = min(low_num, prev_num);
        }

        for (int i = t[0] + 1; i <= t[2]; ++i) {
            int temp_num = arr[i][t[3]];
            arr[i][t[3]] = prev_num;
            prev_num = temp_num;
            low_num = min(low_num, prev_num);
        }

        for (int i = t[3] - 1; i >= t[1]; --i) {
            int temp_num = arr[t[2]][i];
            arr[t[2]][i] = prev_num;
            prev_num = temp_num;
            low_num = min(low_num, prev_num);
        }

        for (int i = t[2] - 1; i >= t[0]; --i) {
            int temp_num = arr[i][t[1]];
            arr[i][t[1]] = prev_num;
            prev_num = temp_num;
            low_num = min(low_num, prev_num);
        }

        answer.push_back(low_num);
    }

    return answer;
}