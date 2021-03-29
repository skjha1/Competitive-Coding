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
    ListNode* middleNode(ListNode* head) {
        ListNode* p=head; // create a pointer node p and move on the head node 
        while (head && head->next) // iterate through the list till nodes is there.
        {
            head=head->next->next; //the time p will move one head will move two
            p=p->next; // this way we can take nodes 
        } 
        return p;
            
    }
};
