#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> passing(N + 1), status(N + 1);
	for (int i = 0; i < stages.size(); i++)
		status[stages[i] - 1]++;
	for (int i = 0; i < status.size(); i++)
	{
		passing[i] += status[i];
		for (int j = i + 1; j < status.size(); j++)
			passing[i] += status[j];
	}

	vector<pair<int, double>> failRate(N);
	for (int i = 0; i < N; i++)
	{
		failRate[i] = make_pair(i, (double)status[i] / (double)passing[i]);
	}

	stable_sort(failRate.begin(), failRate.end(), cmp);
	for (auto f : failRate)
		answer.push_back(f.first + 1);
	return answer;
}

void main()
{
	//test
	//auto ret = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
}