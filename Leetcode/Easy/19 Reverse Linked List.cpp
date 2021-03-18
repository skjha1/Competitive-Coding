/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* q = NULL, *r = NULL; // we requre three pointer p,q,r
	ListNode* p = head; 
	while (p != NULL)
	{/*
	 sliding pointer */
		r = q; // r  sud come upon q
		q = p;// q sud come upon p
		p = p->next;// p sud move to next node 
		q->next = r;// q next sud points on 
	}
	return q; // once we came out of while loop // 1st pointer sud point on q 
        
    }
};
