#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int myatoi(string str)
	{
		int num = 0;//���صĽ��
		int pw = 10;//����
		int stop = 1;//���������
		int len = str.length();//���䳤�ȡ�
		char *s = (char *)str.c_str();
		
		while (*s == 32)//�Ƴ��ո�
		{
			s++;
			len--;
		}
		int haha = len;//�ų������ŵ����⡣��ֻ��һ�����Ż��߸��žͿ��ԣ���һ�����Ͼͷ���0
		if (*s == '-')
		{
			stop = stop *(-1);
			len--;
		}
		if (*s == '+')
		{
			len--;
		}
		if (len == haha-1)//���ֻ��һ�����Ż��߸��ŵĻ����ͽ�����ˡ�
			s++;
		while (len > 0)
		{
			if (*s < 48 || *s > 57)//�����Ż������Ų���һ���Ļ��������з����ֳ��ֵĻ���
			{
				break;
			}
			if (stop == 1)//��������Խ���Ժ󣬷�������ֵ��
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
			if (stop == -1)//����Խ��
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
			num = num*pw + ((int)(*s) - 48);//�����ַ�������Ӧ��intֵ
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