#include <iostream>
#include <stack>
#pragma warning (disable : 4996)
using namespace std;

struct frame {
	int index;
	int value;
};
stack<frame> stk;

int main() {
	int n;
	scanf(" %d", &n);

	for (int i = 1; i <= n; i++) {
		int num;
		scanf(" %d", &num);

		while (!stk.empty()) {
			if (stk.top().value > num) {
				printf("%d ", stk.top().index);
				break;
			}
			stk.pop();
		}

		if (stk.empty()) printf("0 ");
		
		frame tmp = { i, num };
		stk.push(tmp);
	}
	
}