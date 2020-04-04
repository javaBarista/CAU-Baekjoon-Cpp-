#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<int> stk;
	string n;
	getline(cin, n);

	if (n.size() == 1) {
		putchar('0');
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '(' && n[i + 1] == ')') {
			stk.push(2);
			i++;
		}
		else if (n[i] == '[' && n[i + 1] == ']') {
			stk.push(3);
			i++;
		}
		else if (n[i] == ')') {
			int tmp = 0;
			while (!stk.empty() && stk.top() != -1) {
				tmp += stk.top();
				stk.pop();
			}

			if (stk.empty()) {
				ans = 0;
				break;
			}

			stk.pop();
			stk.push(tmp * 2);
		}
		else if (n[i] == ']') {
			int tmp = 0;
			while (!stk.empty() && stk.top() != -2) {
				tmp += stk.top();
				stk.pop();
			}

			if (stk.empty()) {
				ans = 0;
				break;
			}

			stk.pop();
			stk.push(tmp * 3);
		}
		else if (n[i] == '(') stk.push(-1);
		else stk.push(-2);
	}

	while (!stk.empty()) {
		if (stk.top() < 0) {
			ans = 0;
			break;
		}

		ans += stk.top();
		stk.pop();
	}

	printf("%d", ans);
	return 0;
}