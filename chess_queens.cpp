#include"iostream"

#define n 8

using namespace std;

int col[8], diag1[15], diag2[15], ans = 0, reserved[8][8];

void solve(int y)
{
	if (y == n)
	{
		ans++;
		return;
	}
	for (int x = 0; x < n; x++)
	{
		if(col[x] || diag1[x+y] || diag2[n+x-y-1] || reserved[x][y])continue;
		col[x] = diag1[x+y] = diag2[n+x-y-1] = 1;
		solve(y+1);
		col[x] = diag1[x+y] = diag2[n+x-y-1] = 0;
		
	}
}

int main()
{
	for(int i = 0; i < 8; i++)
		col[i] = 0;
	for(int i = 0; i < 15; i++)
	{
		diag1[i] = 0;
		diag2[i] = 0;
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			reserved[i][j] = 0;
	char ch;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
		{
			cin >> ch;
			if (ch == '*')
			reserved[x][y] = 1;
		}
	solve(0);
	cout << ans;
	return(0);
}
