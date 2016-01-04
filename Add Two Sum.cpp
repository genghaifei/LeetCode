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
		ret = new ListNode(0);	//������ֵ���ٿռ�
		tmp = ret;
		int odd = 0;			//��ǽ�λ
		while (l1 != NULL || l2 != NULL)	//�����߶�Ϊ��ʱ������ѭ��
		{
			if (l1 == NULL)					//��һ������Ϊ�յڶ�������Ϊ��ʱ��ֱ�ӽ��ڶ��������нڵ��ֵ���Ƶ�tmp��
			{
				if ((l2->val + odd) > 9)	//����ڶ�������ڵ��ֵ���Ͻ�λ����9������Ҫ��λ
				{
					tmp->val = (l2->val + odd) % 10;	//������ȡ��������λ����1
					odd = 1;

				}
				else
				{
					tmp->val = l2->val + odd;			//����ڶ�������Ľڵ��ֵ���Ͻ�λ������9���ͽ�����ӣ�����λ����0��
					odd = 0;
				}
				//l2 = l2->next;
				//continue;
			}
			if (l2 == NULL)		//ͬ��
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
			if (l1 != NULL && l2 != NULL)	//��������������յĻ�
			{
				if ((l1->val + l2->val + odd) > 9)	//�����������Ӧ�ڵ��ֵ����ټ��Ͻ�λ���������9
				{
					tmp->val = (l1->val + l2->val + odd) % 10;	//ȡ������tmp
					odd = 1;									//��λ����1
				}
				else
				{
					tmp->val = l1->val + l2->val + odd;			//�����ڵ����
					odd = 0;									//��λ����0
				}
			}

			if (l1 != NULL)
				l1 = l1->next;		//ѭ��
			if (l2 != NULL)
				l2 = l2->next;		//ѭ��

			if (l1 != NULL || l2 != NULL || odd != 0)	//���l1����l2��Ϊ�յĻ�����Ҫ�ٿ��ٽڵ㣬���������Ϊ���ҽ�λ��Ϊ1�Ļ�����Ҫ�ڿ��ٽڵ����Ž�λ����
			{
				tmp->next = new ListNode(0);
				tmp = tmp->next;
			}
			if (l1 == NULL && l2 == NULL && odd == 1)	//�����ڵ㶼Ϊ�յ��ǽ�λ����Ϊ0�������
			{
				tmp->val = 1;
			}
		}
		return ret;
	}
};


int main()
{
	ListNode *lt = new ListNode(1);	//���� 1 ��9->9
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