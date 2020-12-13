#include"iostream"
#include<string.h>

#define M 1000000007

long long fact[1000000];

long long power (long long a, long long b)
{
	long long ret = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			ret = (ret * a) % M;
		}
		a = (a*a) % M;
		b >>= 1;
	}
	return(ret);	
}

using namespace std;

int main()
{
	string st;
	cin >> st;
	long long ans ;
	long long n = st.length(), rep[26];
	for(int i = 0; i < 26; i++)
		rep[i] = 0;
	for (int i = 0; i < n; i++)
		rep[st[i]-'a']++;
	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		fact[i] = i * fact[i-1] % M;
	ans = fact[n];
	for (int i = 0; i < 26; i++)
			ans = (ans * power(fact[rep[i]], M-2)) % M;
	cout << ans;
	return(0);
}
