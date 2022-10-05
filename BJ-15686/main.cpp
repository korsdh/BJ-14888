#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int N;
vector<int> cal;
vector<int> oper;
bool check[12] = {};
int res = 0;
int ans_Max = INT_MIN;
int ans_Min = INT_MAX;

void trace(int result, int cnt) {
	if (cnt == N) {
		ans_Max = max(result, ans_Max);
		ans_Min = min(result, ans_Min);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] == 0) continue;
		else {
			oper[i]--;
			if (i == 0) {
				trace(result + cal[cnt], cnt + 1);
			}
			else if (i == 1) {
				trace(result - cal[cnt], cnt + 1);
			}
			else if (i == 2) {
				trace(result * cal[cnt], cnt + 1);
			}
			else {
				trace(result / cal[cnt], cnt + 1);
			}
			oper[i]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cal.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		oper.push_back(a);
	}
	trace(cal[0], 1);
	cout << ans_Max << endl;
	cout << ans_Min << endl;
	return 0;
}