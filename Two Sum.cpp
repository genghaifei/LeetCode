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
		map<int, int> hmap;					//��ʼ��һ��map
		for (int i = 0; i < nums.size(); i++)
		{
			hmap.insert(pair<int, int >(nums[i], i));	//��key��val��ʽ����ֵȫ������map�ڣ�
			//keyΪ��ֵ��valΪ�±�
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int j = target - nums[i];			//�ȿ���һ��ֵ�����Ӧ��ֵ��û��
			if (hmap.count(j))
			{
				int n = hmap[j];				//����еĻ����͵õ����±�
				if (i>n)
				{
					ret.push_back(n + 1);		//���ҵ���ֵ���뷵�ص�vector�С�
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