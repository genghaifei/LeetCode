#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		vector<string> t(numRows);
		int size = s.size();
		int n = numRows;
		bool stop = true;
		if (numRows <= 1 || size <= numRows )
		{
			return s;
		}
		if (numRows == 2)
		{
			int i = 0;
			while (size > i)
			{
				if (size > i)
				{
					t[0] += s[i];
					i++;
				}
				if (size > i)
				{
					t[1] += s[i];
					i++;
				}
				
			}
		}
		if (numRows > 2)
		{

			int j = 0;
			for (int i = 0; i < size; i++)
			{
				if (j < n && stop == true)
				{
					t[j] += s[i];
					j++;
				}
				if (j == n)
				{
					stop = false;
					j = n - 2;
					continue;
				}
				if (j >= 0 && stop == false)
				{
					t[j] += s[i];
					j--;
				}
				if (j == 0)
				{
					stop = true;
					continue;
				}
			}
		}
		string s2;
		for (int i = 0; i < numRows; i++)
		{
			s2 = s2 + t[i];
		}
		return s2;
	}
};

int main()
{
	string str = "PAYPALISHIRING";
	Solution lo;
	cout << lo.convert(str, 3);
	return 0;
}