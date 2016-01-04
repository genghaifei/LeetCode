#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;
		map<int, int> hmap;					//初始化一个map
		for (int i = 0; i < nums.size(); i++)
		{
			hmap.insert(pair<int, int >(nums[i], i));	//以key，val形式，将值全部放在map内，
			//key为数值，val为下标
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int j = target - nums[i];			//先看第一个值与其对应的值有没有
			if (hmap.count(j))
			{
				int n = hmap[j];				//如果有的话，就得到其下标
				if (i>n)
				{
					ret.push_back(n + 1);		//将找到的值放入返回的vector中。
					ret.push_back(i + 1);
					return ret;
				}
			}
		}
		return ret;
	}
		
};


int main()
{
	vector<int> sum;
	vector<int> ret;
	int a[] = { 2, 7, 11, 14 };
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		sum.push_back(a[i]);
	}
	solution so;
	int target = 9;
	ret = so.twoSum(sum, target);
	vector<int>::iterator lt;
	for (lt = ret.begin(); lt != ret.end(); lt++)
	{
		cout << *lt << endl;
	}

	return 0;

}