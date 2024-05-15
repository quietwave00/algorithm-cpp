/**
 * B17298_오큰수
*/
#include <iostream>
#include <stack>
using namespace std;

int n, input;
stack<int> input_st;
stack<int> temp_st;
stack<int> result_st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> input;
		input_st.push(input);
	}

	while (!input_st.empty()) {
		int result = -1;
		int input_top = input_st.top();
		input_st.pop();

		while (!temp_st.empty()) {
			int temp_top = temp_st.top();
			if (temp_top > input_top) {
				result = temp_top;
				temp_st.push(input_top);
				break;
			}
			else {
				temp_st.pop();
			}
		}
		if (result == -1) {
			temp_st.push(input_top);
		}
		result_st.push(result);
	}

	while (!result_st.empty()) {
		int result_top = result_st.top();
		result_st.pop();
		cout << result_top << " ";
	}

	return 0;
}
