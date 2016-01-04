#include <iostream>
using namespace std;

class solution
{
public:
	bool isPalindrome(int x)
	{
		if (x > 0 && x < 10)
		{
			return true;
		}
		if (x < 0 )
		{
			return false;
		}
		int p = reverse(x);
		if (p == x)
		{
			return true;
		}
		
		return false;
	}
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
				if (ret >= 214748365)//越界问题
				{
					return 0;
				}
				if (ret == 241748364)
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

int main()
{
	solution so;
	if (so.isPalindrome(100001))
	{
		cout << "yes its a palindrome" << endl;
		return 0;
	}
	else
	{
		cout << "no its not a palindrome" << endl;
		return 0;
	}
	cout << "have no idea" << endl;
	return 0;
}