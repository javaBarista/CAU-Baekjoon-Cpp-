#include <iostream>
#include <string>
#include <stack>

#pragma warning (disable : 4996)
using namespace std;

bool isPossible(string &s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (s[i] == ')') i++;
			else stk.push('(');
		}
		else {
			if (!stk.empty() && stk.top() == '(') stk.pop();
			else return false;
		}
	}
	return stk.empty() ? true : false;
}

int main() {
	int n;
	scanf(" %d", &n);

	while (n--) {
		string s, ans;
		cin >> s;
		if (s.size() % 2) ans = "NO";
		else ans = isPossible(s) ? "YES" : "NO";		
		cout << ans << endl;
	}
}