#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector<int> cal;
vector<int> oper;
int res = 0;
int ans = 0;

void trace(int a, int b) {
	if (b == N - 1) {
		ans = max(res, ans);
		return;
	}
	for (int i = a; i < N - 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (oper[j] == 0) continue;
			else {
				if (j == 0) {
					res += (cal[i] + cal[i + 1]);
				}
				else if (j == 1) {
					res -= (cal[i] + cal[i + 1]);
				}
				else if (j == 2) {
					res *= (cal[i] + cal[i + 1]);
				}
				else {
					res /= (cal[i] + cal[i + 1]);
				}
			}
		}
		trace(a + 1, b + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cal.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a;
		oper.push_back(a);
	}
	
}