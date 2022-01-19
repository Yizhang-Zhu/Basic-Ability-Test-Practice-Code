#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c; //weight of each good
	int m1, n1, w1, m2, n2, w2, m3, n3, w3;
	cin >> a >> b >> c;
	m1 = a + b;
	n1 = c;
	if (m1 >= n1)
	{
		w1 = m1 - n1;
	}
	else
	{
		w1 = n1 - m1;
	}

	m2 = a + c;
	n2 = b;
	if (m2 >= n2)
	{
		w2 = m2 - n2;
	}
	else
	{
		w2 = n2 - m2;
	}

	m3 = b + c;
	n3 = a;
	if (m3 >= n3)
	{
		w3 = m3 - n3;
	}
	else
	{
		w3 = n3 - m3;
	}

	if ((w1 <= w2) && (w1 <= w3))
	{
		cout << w1;
	}
	else if ((w2 <= w1) && (w2 <= w3))
	{
		cout << w2;
	}
	else if ((w3 <= w1) && (w3 <= w2))
	{
		cout << w3;
	}
}
