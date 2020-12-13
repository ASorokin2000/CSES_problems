#include"iostream"
#include<string.h>

using namespace std;

int ans = 0;

bool visited[7][7]={0};

string s;

int av (int x, int y)
{
	return x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y];
}

void solve (int x, int y, int path = 0)
{
	if (x == 0 && y == 6)
	{
		if(path == 48)
			ans++;
		return;
	}
	visited[x][y] = 1;
	if ((s[path] == 'D' || s[path] == '?') && av(x,y+1) && (av(x, y+2) || !av(x+1, y+1) || !av(x-1, y+1)))
		solve(x, y+1, path+1);
	if ((s[path] == 'U' || s[path] == '?') && av(x,y-1) && (av(x, y-2) || !av(x+1, y-1) || !av(x-1, y-1)))
	solve(x, y-1, path+1);
	if ((s[path] == 'R' || s[path] == '?') && av(x+1,y) && (av(x+2, y) || !av(x+1, y+1) || !av(x+1, y-1)))
		solve(x+1, y, path+1);
	if ((s[path] == 'L' || s[path] == '?') && av(x-1,y) && (av(x-2, y) || !av(x-1, y-1) || !av(x-1, y+1)))
	solve(x-1, y, path+1);
	visited[x][y] = 0;
}

int main()
{
	cin >> s;
	solve(0,0);
	cout << ans;
	return(0);
}
