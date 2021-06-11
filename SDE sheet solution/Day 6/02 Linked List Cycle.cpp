/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
->Use two pointers, walker and runner.
->walker moves step by step. runner moves two steps at time.
->if the Linked List has a cycle walker and runner will meet at some
point.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
                return true;            
        }
        return false;
    }
};

/*

 use faster and lower runner solution. (2 pointers)
 the faster one move 2 steps, and slower one move only one step.
 if there's a circle, the faster one will finally "catch" the slower one. 
 (the distance between these 2 pointers will decrease one every time.)
 
 if there's no circle, the faster runner will reach the end of linked list. (NULL)
 */