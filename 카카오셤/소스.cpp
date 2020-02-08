#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
unordered_map<string, string> map;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	for (auto e : record)
	{
		istringstream iss(e);
		string uid;
		string cmd;
		string nickname;
		iss >> cmd;
		if (e[0] == 'E')
		{
			iss >> uid;
			iss >> nickname;
			map[uid] = nickname;
		}
		else if (e[0] == 'C')
		{
			iss >> uid;
			iss >> nickname;
			map[uid] = nickname;
		}
	}
	for (auto e : record)
	{
		istringstream iss(e);
		string tmp;
		string uid;
		string cmd;
		string nickname;
		iss >> cmd >> uid >> nickname;
		if (e[0] == 'E')
		{
			answer.push_back(map[uid] + "님이 들어왔습니다.");
		}
		else if (e[0] == 'L')
		{
			answer.push_back(map[uid] + "님이 나갔습니다.");
		}
	}
	return answer;
}

int main()
{
	vector<string> a = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
	vector<string> answer = solution(a);
	for (auto e : answer) cout << e << "\n";
}