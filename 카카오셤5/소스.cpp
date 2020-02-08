#include <iostream>


#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
int ncnt = 0;
struct node
{
	int lbound;
	int rbound;
	node* lc;
	node* rc;
	node* p;
	pii data;
	node() {};
	node(pii d) { data = d; }
}tmpnode[100000];

node* inputnode(node *parent, vector<int> val, bool flag)
{
	node *nnode = &tmpnode[ncnt++];
	nnode->data.first = val[0];
	nnode->data.second = val[1];
	nnode->lc = nullptr;
	nnode->rc = nullptr;
	nnode->p = parent;
	if (parent != nullptr)
	{
		if (flag)
		{
			parent->lc = nnode;
			nnode->lbound = parent->lbound;
			nnode->rbound = parent->data.first;
		}
		else
		{
			parent->rc = nnode;
			nnode->lbound = parent->data.first;
			nnode->rbound = parent->rbound;
		}
	}
	else
	{
		nnode->lbound = 0;
		nnode->rbound = 100001;
	}
	return nnode;
}

bool cmp(vector<int> a, vector<int> b)
{
	if (a[1] == b[1]) return a[0] < b[0];
	return a[1] > b[1];
}
unordered_map<string, int> map;

void preorder(node *now, vector<int> &ans)
{
	if (now == nullptr) return;
	string aa = to_string(now->data.first);
	aa.append(" ");
	aa.append(to_string(now->data.second));
	ans.push_back(map[aa]);
	preorder(now->lc, ans);
	preorder(now->rc, ans);
}


void postorder(node *now, vector<int> &ans)
{
	if (now == nullptr) return;
	postorder(now->lc, ans);
	postorder(now->rc, ans);
	string aa = to_string(now->data.first);
	aa.append(" ");
	aa.append(to_string(now->data.second));
	ans.push_back(map[aa]);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	int cnt = 1;
	for (auto e : nodeinfo)
	{
		string aa = to_string(e[0]);
		aa.append(" ");
		aa.append(to_string(e[1]));
		map[aa] = cnt++;
	}
	sort(nodeinfo.begin(), nodeinfo.end(), cmp);
	node *root = inputnode(nullptr, nodeinfo[0],1);
	int now = 0;
	int nowidx = 0;
	int prev = -1;
	for (int i = 1; i < nodeinfo.size(); i++)
	{
		if (now != nodeinfo[i][1])
		{
			prev = nowidx;
			now = nodeinfo[i][1];
			nowidx = i;
		}
		
		for (int j = prev; j < nowidx; j++)
		{
			if (nodeinfo[i][0] > (&tmpnode[j])->lbound && nodeinfo[i][0] < (&tmpnode[j])->data.first)
			{
				inputnode((&tmpnode[j]), nodeinfo[i],1);
				break;
			}
			else if (nodeinfo[i][0] < (&tmpnode[j])->rbound && nodeinfo[i][0] > (&tmpnode[j])->data.first)
			{
				inputnode((&tmpnode[j]), nodeinfo[i], 0);
				break;
			}
		}
	}
	vector<int> p1;
	vector<int> p2;
	preorder(root, p1);
	postorder(root, p2);
	answer.push_back(p1);
	answer.push_back(p2);
	return answer;
}


int main()
{
	vector<vector<int>> ss = { {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	ss = solution(ss);
	for (auto e : ss)
	{
		for (auto a : e)
		{
			cout << a << "\n";
		}
	}
}