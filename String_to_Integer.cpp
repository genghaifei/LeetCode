#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int myatoi(string str)
	{
		int num = 0;//返回的结果
		int pw = 10;//倍数
		int stop = 1;//标记正负数
		int len = str.length();//求其长度。
		char *s = (char *)str.c_str();
		
		while (*s == 32)//移除空格
		{
			s++;
			len--;
		}
		int haha = len;//排出正负号的问题。即只有一个正号或者负号就可以，有一个以上就返回0
		if (*s == '-')
		{
			stop = stop *(-1);
			len--;
		}
		if (*s == '+')
		{
			len--;
		}
		if (len == haha-1)//如果只有一个正号或者负号的话，就将其过滤。
			s++;
		while (len > 0)
		{
			if (*s < 48 || *s > 57)//当负号或者正号不是一个的话，或者有非数字出现的话。
			{
				break;
			}
			if (stop == 1)//关于正数越界以后，返回最大的值。
			{
				if (num > 1000000000 && (*(s + 1) > 48 || *(s + 1) < 57))
				{
					return 2147483647;
				}
				if (num * pw >= 0)                                  
				{
					if (((num < 0) || (num >= 214748364)) && (((int)(*s) - 48) > 7))
					{
						return 2147483647;
					}
				}
				else
				{
					return 2147483647;
				}
			}
			if (stop == -1)//负数越界
			{
				if (num > 1000000000 && (*(s + 1) > 48 || *(s + 1) < 57))
				{
					return -2147483648;
				}
				if (num * pw >= 0)
				{
					if (((num < 0) || (num >= 214748364)) && (((int)(*s) - 48) > 8))
					{
						return -2147483648;
					}
				}
				else
				{
					return -2147483648;
				}
				
			}
			num = num*pw + ((int)(*s) - 48);//计算字符串所对应的int值
			s++;
			len--;
			
		}
		if (stop == -1)
		{
			return num*stop;
		}
		if (stop == 1)
		{
			return num;
		}
	}
};

int main()
{
	int result;
	string s("325446");
	Solution so;
	result = so.myatoi(s);
	cout << result<<endl;
	return 0;
}