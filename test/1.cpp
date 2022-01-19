#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char aa[1000000], bb[1000000];
		cin >> aa;
		int flg = 0;
		int dp = 0;
		int i;
		int length = strlen(aa);
		for (i = 0; i < length; i++)
		{
			if (('a' <= aa[i] && aa[i] <= 'z') || ('A' <= aa[i] && aa[i] <= 'Z'))
			{
				flg = 1;
			}
			if (i % 2 == 0)
			{
				bb[dp] = aa[i];
				dp++;
			}
		}

		if (flg == 1)
		{
			cout << bb << endl;
		}

		else
		{
			cout << aa << endl;
		}
	}
}
