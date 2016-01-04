/*Usage:Given a string, find the length of the longest substring without repeating characters. 
	For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 	which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
date:	2015/11/15
author:	haifei
*/



class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int arr[128] = { 0 };
		unsigned int nc = 0;	//������¼�ظ����ַ���һ�γ��ֵ�λ��
		unsigned int max = 0;
		for (unsigned int i = 1; i <= s.size(); i++)//���±�ĳ�Ϊ1��ʼ��Ϊ����arr�еĳ�ʼ��ֵ0����ͻ
		{
			if (arr[s[i-1]] != 0)//i��1��ʼ������Դstring���±껹��Ҫ��i-1��ʼ��
			{
				if (nc < arr[s[i-1]])		//���ifѭ���ĺ������Ϊ��Ӧ�ԡ�abba���������ӡ�
					nc = arr[s[i-1]];//nc��ֵ������һ�θ��ַ���λ�á�
			}
			if (i - nc > max)		//����ͳ��ÿһ�ε�ѭ����nc���û�����max++��nc������˾���i-nc �����бȽ�
			{
				max = i - nc;
			}
			arr[s[i-1]] = i;//��������������±����ó���1��ʼ��
		}

		return max;
	}
};



int main()
{
	Solution so;
	string s("abba");
	cout<<so.lengthOfLongestSubstring(s)<<endl;

	return 0;
}