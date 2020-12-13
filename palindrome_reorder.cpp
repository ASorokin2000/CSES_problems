#include"iostream"
#include<string.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int len = s.length(), ar[26], num_odd = 0, middle_pos = -1;
	for (int i = 0; i < 26; i++)
		ar[i] = 0;
	for (int i = 0; i < len; i++)
		ar[(int)(s[i]-'A')]++;
	for (int i = 0; i < 26; i++)
		if (ar[i] % 2)
			num_odd++;
	if (num_odd > 1)
		cout << "NO SOLUTION";
	else
	{    
		for (int i = 0; i < 26; i++)
		{
			if (ar[i] % 2)
				middle_pos = i;
			int j = (ar[i] + 1) / 2;
			while (ar[i] > j)
			{
				ar[i]--;
				cout << (char)('A'+i);
			}
		}
		if (middle_pos != -1)
		{
			cout << (char) ('A'+middle_pos);
			ar[middle_pos]--;
		}
		for (int i = 25; i >= 0; i--)
			while (ar[i] > 0)
			{
				ar[i]--;
				cout << (char) ('A'+i);
			}
			
		
	}
	return(0);
}
