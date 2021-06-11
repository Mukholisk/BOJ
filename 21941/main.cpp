#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
// �����Լ� ����
bool cmp(pair<string, int> a, pair<string, int> b);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair<string, int> input[100];
	string S;
	int M, i, score = 0;
	
	// �Է�
	cin >> S;
	cin >> M;
	for (i = 0; i < M; ++i)
		cin >> input[i].first >> input[i].second;
	sort(input, input + M, cmp);
	
	// �˰���
	for (i = 0; i < M; ++i) {
		if (input[i].second <= input[i].first.length())
			continue;
		while (true) {
			if (S.find(input[i].first) != -1) {
				S.erase(S.find(input[i].first), input[i].first.length());
				score += input[i].second;
			}
			else
				break;
		}
	}
	score += S.length();

	// ���
	cout << score << '\n';
	return 0;
}
// �����Լ� ����
bool cmp(pair<string, int> a, pair<string, int> b) {
	double as = a.second / a.first.length();
	double bs = b.second / b.first.length();
	if (as > bs)
		return true;
	else if (as == bs) {
		if (a.second >= b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}