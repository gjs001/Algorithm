#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> P;
int n, m, k, A, B;
int reception[1001];
int repair[1001];

typedef struct rec
{
	int customer_number;
	int finish_time;
	int reception_number;
	rec() {};
	rec(int a, int b, int c) { customer_number = a, finish_time = b, reception_number = c; }
}rec;

typedef struct rep
{
	int customer_number;
	int finish_time;
	int reception_number;
	int repair_number;
	rep() {};
	rep(int a, int b, int c,int d) { customer_number = a, finish_time = b, reception_number = c, repair_number = d; }
}rep;

bool operator < (rec a,rec b)
{
	if (a.finish_time != b.finish_time) return a.finish_time > b.finish_time;
	return a.reception_number > b.reception_number;
}
bool operator < (rep a, rep b)
{
	return a.finish_time > b.finish_time;
}

queue<int> people;
priority_queue<rec > rec_que;
priority_queue<rep > rep_que;
queue<rec > wait_que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m >> k >> A >> B;
		
		for (int i = 1; i <= n; i++) cin >> reception[i];
		for (int i = 1; i <= m; i++) cin >> repair[i];
		for (int i = 1; i <= k; i++)
		{
			int tmp;
			cin >> tmp;
			people.push(tmp);
		}

		int answer = 0;
		int finished = 0;
		int sec = -1;
		int reception_idle = (1 << n) - 1;
		int repair_idle = (1 << m) - 1;
		int people_num = 1;
		while (finished < k)
		{
			sec++;
			while (!rep_que.empty() && rep_que.top().finish_time <= sec)
			{
				rep now_people = rep_que.top();
				rep_que.pop();
				repair_idle |= 1 << (now_people.repair_number - 1);
				finished++;
				if (now_people.reception_number == A && now_people.repair_number == B)
				{
					answer += now_people.customer_number;
				}
			}
			while (!rec_que.empty() && rec_que.top().finish_time <= sec)
			{
				rec now_people = rec_que.top();
				rec_que.pop();
				reception_idle |= 1 << (now_people.reception_number - 1);
				wait_que.push(now_people);
			}
			while (!wait_que.empty() && wait_que.front().finish_time <= sec && repair_idle)
			{
				int now_repair = 0;
				int tmp = (repair_idle & -repair_idle);
				while (tmp)
				{
					now_repair++;
					tmp >>= 1;
				}
				repair_idle &= (repair_idle - 1);
				rec now_people = wait_que.front();
				wait_que.pop();
				rep_que.push(rep(now_people.customer_number, sec + repair[now_repair], now_people.reception_number, now_repair));
			}
			while (!people.empty() && people.front() <= sec && reception_idle )
			{
				int now_reception = 0;
				int tmp = reception_idle & -reception_idle;
				while (tmp)
				{
					now_reception++;
					tmp >>= 1;
				}
				reception_idle &= (reception_idle - 1);
				rec_que.push(rec(people_num, sec + reception[now_reception], now_reception));
				people_num++;
				people.pop();
			}

		}
		if (!answer) answer = -1;
		cout << "#" << tc << " " << answer << "\n";
	}
}