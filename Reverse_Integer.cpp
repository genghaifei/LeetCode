#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		if (x == 0)
		{
			return 0;
		}
		int bar = 10;
		int t = x;
		int r;
		int ret = 0;
		int i = 10;
		while (t != 0)
		{
			r = t % bar;
			if (x == t)
			{
				ret = ret + r;
			}
			else
			{
				if (ret >= 214748365 || ret <= -214748365)//越界问题
				{
					return 0;
				}
				if (ret == 241748364 || ret == -241748364)
				{
					if (r > 8)
					{
						return 0;
					}
				}
				ret = ret*i + r;
			}
			
			t = t / bar;
		}
		return ret;
	}
};

int main(int argc, char ** argv)
{
	int x;
	Solution so;
	cin >> x;
	cout << so.reverse(x);

	return 0;
}