#include <iostream>
#include <deque>
#pragma warning (disable : 4996)
using namespace std;

deque<int> dq;

void rolling_left() {
	int first = dq.front();
	dq.pop_front();
	dq.push_back(first);
}

void rolling_right() {
	int last = dq.back();
	dq.pop_back();
	dq.push_front(last);
}

int iter_find(int val) {
	int i = 0;
	while (val != dq[i])	i++;
	return i;
}

int main() {
	int n, m, del;
	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= n; i++)	dq.push_back(i);

	int cnt = 0;
	while (m--) {
		int tmp = dq.front();
		scanf(" %d", &del);
		if (del == tmp) dq.pop_front();
		else if (iter_find(del) > (dq.size() >> 1)) {
			for (int i = 0; i < dq.size(); i++) {
				rolling_right();
				tmp = dq.front();
				cnt++;
				if (tmp == del) break;
			}
			dq.pop_front();
		}
		else {
			for (int i = 0; i < dq.size(); i++) {
				rolling_left();
				tmp = dq.front();
				cnt++;
				if (tmp == del) break;
			}
			dq.pop_front();
		}
	}

	printf("%d", cnt);
}