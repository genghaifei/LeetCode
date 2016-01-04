/*Usage:You are given two linked lists representing two non-negative numbers.
        The digits are stored in reverse order and each of their nodes contain a single digit.
        Add the two numbers and return it as a linked list.
        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
date:	2015/11/15
author:	haifei
*/


#include <iostream>
using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode *ret, *tmp;
		ret = new ListNode(0);	//给返回值开辟空间
		tmp = ret;
		int odd = 0;			//标记进位
		while (l1 != NULL || l2 != NULL)	//当两者都为空时，结束循环
		{
			if (l1 == NULL)					//第一个链表为空第二个链表不为空时，直接将第二个链表中节点的值复制到tmp中
			{
				if ((l2->val + odd) > 9)	//如果第二个链表节点的值加上进位大于9，就又要进位
				{
					tmp->val = (l2->val + odd) % 10;	//将余数取出，将进位符置1
					odd = 1;

				}
				else
				{
					tmp->val = l2->val + odd;			//如果第二个链表的节点的值加上进位不大于9，就将其相加，将进位符置0，
					odd = 0;
				}
				//l2 = l2->next;
				//continue;
			}
			if (l2 == NULL)		//同上
			{
				if ((l1->val + odd) > 9)
				{
					tmp->val = (l1->val + odd) % 10;
					odd = 1;

				}
				else
				{
					tmp->val = l1->val + odd;
					odd = 0;
				}
				//l1 = l1->next;
				//continue;
			}
			if (l1 != NULL && l2 != NULL)	//如果两个链表都不空的话
			{
				if ((l1->val + l2->val + odd) > 9)	//将两个链表对应节点的值相加再加上进位符如果大于9
				{
					tmp->val = (l1->val + l2->val + odd) % 10;	//取余数给tmp
					odd = 1;									//进位符置1
				}
				else
				{
					tmp->val = l1->val + l2->val + odd;			//不大于的情况
					odd = 0;									//进位符置0
				}
			}

			if (l1 != NULL)
				l1 = l1->next;		//循环
			if (l2 != NULL)
				l2 = l2->next;		//循环

			if (l1 != NULL || l2 != NULL || odd != 0)	//如果l1或者l2不为空的话，就要再开辟节点，但是如果都为空且进位符为1的话，就要在开辟节点来放进位符。
			{
				tmp->next = new ListNode(0);
				tmp = tmp->next;
			}
			if (l1 == NULL && l2 == NULL && odd == 1)	//两个节点都为空但是进位符不为0的情况。
			{
				tmp->val = 1;
			}
		}
		return ret;
	}
};


int main()
{
	ListNode *lt = new ListNode(1);	//测试 1 和9->9
	//ListNode *li = new ListNode(7);
	/*lt->next = li;
	li = new ListNode(3);
	lt->next->next = li;*/

	ListNode *le = new ListNode(9);
	ListNode *li = new ListNode(9);
	le->next = li;
	/*li = new ListNode(4);
	le->next->next = li;*/

	solution so;
	li = so.addTwoNumbers(lt, le);
	while (li != NULL)
	{
		cout << li->val << " ";
		li = li->next;
	}

	
}