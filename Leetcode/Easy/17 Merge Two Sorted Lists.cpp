class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2; // if l1 is empty take l2 as it is 
        if(!l2) return l1; // if l2 is empty take l1 as it is 
        
        ListNode* head = l1; //this is the resulting head make a head node pointing to l1
        if(l1->val > l2->val){ // if l1 is having more elemnts then l2 
            head = l2; // so head should point on the smallest of these 
            l2 = l2->next; //we had taken a node so l2 should move to next everytime
        } else
            l1 = l1->next; // move l1 to next 
        
        ListNode* curr = head; // lets take a current pointer pointing to head 
        while(l1 && l2){ // we will run a loop till both are present in the list // if anyone of them become null we will appent the remaining 
            if(l1->val < l2->val){ // if l2 value is greater then the l1
                curr->next = l1; // then we will pick from l1
                l1 = l1->next; //we had taken a node so l1 should move to next everytime
            } else {
                curr->next = l2; // take from l2
                l2 = l2->next; // and move next 
            }
            curr = curr->next; // change the pointer
        }
        if(!l1) curr->next = l2; // if l1 got null take all remaining from l2 
        else curr->next = l1; // else l2 got null take all remaining from l1 
        
        return head; // store all the node in head pointer and return it 
    }
};

