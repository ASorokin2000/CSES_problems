#include"iostream"
#include<math.h>

using namespace std;

long long ans = 1e+11;
int n;

void solve (long long w[], int current, long long sum)
{
	if (current == n)
		ans = min(ans, abs(sum));
	else
	{
		solve(w, current+1, sum+w[current]);
		solve(w, current+1, sum-w[current]);
	}
}

int main()
{
	cin >> n;
	long long w[n];
	for (int i = 0; i < n; i++)
		cin >> w[i];
	solve(w, 0, 0);
	cout << ans;
	return(0);
}
