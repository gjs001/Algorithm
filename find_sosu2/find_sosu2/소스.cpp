#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
#define MAX 1048576
int M, N;
int fArr[1000001];
int ans[1000001];
#define nise_mono true
 queue<int> A;

int main() {
	cin >> M >> N;
	int size = 0;
	
	for (int i = 2; i <= N; i++) { //자기말곤 칭구가 없는 혼모노들을 찾자
		if (fArr[i] == 1) continue;
		if (i >= M) printf("%d\n", i);
		int cNum = i;
		int cnt = 1;
		for(int j=i*2;j<=N;j +=i){ // 어차피 i 본인은 다시 고려안되니까 i*2부터 시작해서 i씩 더해줘서 i의 배수 값들을 모두 니세모노로 만들어주자
			fArr[j] = nise_mono;
		}
	}

}