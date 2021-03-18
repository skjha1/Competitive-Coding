/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* p = head;
        ListNode* q = head;
        while (p->next != NULL && p->next->next != NULL) {  // this condition should be satisfied for forting a loop
            q = q->next; // move everytime q to one position 
            p = p->next->next; // everytime move p two times 
            if (p == q) // if this two meets at a place then there will ba cycle 
                return true;
        }
        return false;
    }
};
