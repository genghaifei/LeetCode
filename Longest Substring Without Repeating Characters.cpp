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
		unsigned int nc = 0;	//用来记录重复的字符第一次出现的位置
		unsigned int max = 0;
		for (unsigned int i = 1; i <= s.size(); i++)//将下标改成为1开始是为了与arr中的初始化值0不冲突
		{
			if (arr[s[i-1]] != 0)//i从1开始，但是源string的下标还是要从i-1开始；
			{
				if (nc < arr[s[i-1]])		//这个if循环的含义就是为了应对“abba”这种例子。
					nc = arr[s[i-1]];//nc的值就是上一次该字符的位置。
			}
			if (i - nc > max)		//用来统计每一次的循环后nc如果没变就是max++，nc如果变了就是i-nc ，进行比较
			{
				max = i - nc;
			}
			arr[s[i-1]] = i;//将现如今的数组的下标设置成由1开始。
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