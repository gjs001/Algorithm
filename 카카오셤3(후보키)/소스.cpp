#include <iostream>


#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> map;
int used[10] = { 9,9,9,9,9,9,9,9,9,9 };
vector<int> visit;
int solution(vector<vector<string>> relation) {
	int answer = 0;
	int col = relation[0].size();
	int row = relation.size();
	
	int usedcol = 0;
	for (int cc = 1; cc <= col; cc++)
	{
		for (int i = 1; i < (1 << col); i++)
		{
			string tag;
			int cnt = 0;
			bool res = true;
			vector<int> usednumber;
			for (int j = 0; j < col; j++)
			{
				if (((1 << j) & i) == 0) continue;
				tag.push_back(j + '0');
				tag.push_back(' ');
				usednumber.push_back(j);
				cnt++;
			}
			if (cnt != cc) continue;
			for (auto ss : visit)
			{
				int acnt = 0;
				int bcnt = 0;
				for (int j = 0; j < 8; j++)
				{
					if ((ss & (1 << j))) bcnt++;
				}
				for (int j = 0; j < 8; j++)
				{
					if ((ss & (1 << j)) && (i & (1 << j)))
					{
						acnt++;
					}
				}
				if (bcnt == acnt)
				{
					res = false;
					break;
				}
			}
			if (!res) continue;
			for (int k = 0; k < row; k++)
			{
				string nk = tag;
				for (int j = 0; j < col; j++)
				{
					if (((1 << j) & i) == 0)  continue;
					nk.append(relation[k][j] + "_");
				}
				if (map[nk]) {
					res = false;
					break;
				}
				map[nk] = 1;
			}
			if (res)
			{
				answer++;
				visit.push_back(i);
			}
		}
	}
	
	return answer;
}

int main()
{
	vector<vector<string>> ta = { {"100","ryan","music","100"},{"200","apeach","math","200"}, {"300", "tube", "computer", "300"}, { "400","con","computer","400" }, { "500","muzi","music","500" }, { "600","apeach","music","600" }};
	cout << solution(ta);
}