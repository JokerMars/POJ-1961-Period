#include<iostream>
#include<string>

using namespace std;

const int MAX_LEN = 1000005;
int suffix[MAX_LEN];

void GetSuffix(string s)
{
	suffix[0] = -1;
	suffix[1] = 0;

	int k = 0;
	for (int i = 2; i <= s.length(); i++)
	{
		while (k >= 0 && s[k] != s[i - 1])
			k = suffix[k];
		suffix[i] = ++k;
	}

}

int main()
{
	int len;
	string str;
	int cnt = 1;
	while (cin >> len >> str)
	{
		if (len == 0)
			break;
		cout << "Test case #" << cnt++ << endl;
		memset(suffix, 0, MAX_LEN);
		GetSuffix(str);

		int i, k;
		for (i = 2; i <= len; i++)
		{
			if (suffix[i] == 0)continue;
			if (i % (i - suffix[i]) == 0)
			{
				cout << i << " " << i / (i - suffix[i]) << endl;
			}
		}
		cout << endl;
	}
	return 0;
}