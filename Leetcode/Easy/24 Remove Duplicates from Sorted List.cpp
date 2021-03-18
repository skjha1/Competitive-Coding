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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* q = head; // point q on head 
	while (q && q->next) // when element is there in the list
	{
		if (q->val == q->next->val) // if data is matching  // means duplicate is there
		{
			q->next=q->next->next; // then skip that and point next to next
		}
		else // if there is duplicate value 
		{
			
			q = q->next; // and move q to next  
		}
         
    }
       return head; // at last take the list 
    }
};
