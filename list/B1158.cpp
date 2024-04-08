/**
 * B1158번_요세푸스 문제
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    list<int> list;
    for (int i = 1; i <= N; i++) {
        list.push_back(i);
    }

    vector<int> vec;
    auto it = list.begin();

    while (!list.empty()) {
        for (int i = 0; i < K - 1; i++) {
            it++;
            if (it == list.end()) {
                it = list.begin();
            }
        }

        vec.push_back(*it);
        it = list.erase(it);
        if (it == list.end()) {
            it = list.begin();
        }
    }

    cout << "<";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";

    return 0;
}