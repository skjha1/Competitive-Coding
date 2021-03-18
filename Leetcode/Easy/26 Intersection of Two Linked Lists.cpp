class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode  *p =headA;
        ListNode *q= headB;
        
        while (p!= q)
        {
            p = !p ? headB : p->next;
            q = !q ? headA : q->next; 
            
        }
        return p;
    }
};
