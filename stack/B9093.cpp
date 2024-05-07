/*
* B9093_단어 뒤집기
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    for(int i = 0; i < t; i++) {
        string str;
        getline(cin, str);
        str += ' ';

        stack<char> stack;
        for(int j = 0; j < str.size(); j++) { // 한 문장 사이즈 기준
            cout << "char: " << str[j] << endl;
            if(str[j] == ' ') { // 공백(=단어) 만나면
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << str[j]; // 띄어쓰기가 되겠지...
            } else { // 공백(=단어) 아니면
                stack.push(str[j]);
            }
        }
    }
    return 0;
}