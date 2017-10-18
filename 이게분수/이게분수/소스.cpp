#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	float a, b, c, d = 1;
	float _max = 0;
	int ans = 0;
	scanf("%f %f\n%f %f", &a, &b, &c, &d);
	_max = (a / c) + (b / d);
	if (_max < (c / d) + (a / b)) {
		ans=1;
		_max = (c / d) + (a / b);
	}
	if (_max < (d / b) + (c / a)) {
		ans=2;
		_max = (d / b) + (c / a);
	}
	if (_max < (b / a) + (d / c)) {
		ans=3;
	}
	printf("%d", ans);
	
}