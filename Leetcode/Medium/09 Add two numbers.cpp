// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0); // initialize a resultant node with zero 
        ListNode *p = l1, *q= l2, *current = res; // assifgn to new pointers 
        int carry =0;
        
        while (p || q )
        {
            int x = (p)? p->val : 0;
            int y = (q)? q->val : 0;
            int sum = carry+x+y;
            carry= sum/10; // take carry suppose 19/10 =1 carry
            current->next= new ListNode(sum%10); // store reminder in the new node like 19 %9 = 9--> srore it in new node 
            current= current->next;
            if (p) p=p->next; // move p to next everytime 
            if (q) q= q->next;
        }
        if (carry > 0) 
            current->next = new ListNode(carry);
        return res->next; // return next because we initialized 1st res node as zero on the top 
    }
    
};
