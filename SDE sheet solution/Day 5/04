/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 
 * };
 
 The difference between the final node and the to_be_delete node is N. And here the assumption is that n is always valid.

fast pointer points to the node which is N step away from the to_be_delete node.

slow pointer points to the to_be_delete node.
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Make an offset pointer and make it move n spaces.
        ListNode* offset = head;
        
        //Then start moving from head again(using curr) so that you can get the n-last position
        ListNode* curr = head;
        
        //Prev required so that curr can be deleted rightaway
        ListNode* prev = new ListNode(-1);
        prev->next = curr;
        
        for(int i = 1; i < n; ++i)
            offset = offset->next;

    
        while(offset->next != NULL)
        {
            offset = offset->next;
            prev=curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        
        //For cases where only one number is there OR the first number is deleted
        if(curr==head)
            return head->next;
        
        //Delete the node from memory to avoid leak
        delete curr;
        
        return head;
    }
};
--------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start = new ListNode(0);
        start->next = head;
        
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};
