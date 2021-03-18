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
    int getDecimalValue(ListNode* head) {
        ListNode* p=head;
        int c=0;
        while (p)
        {
            c++;
            p=p->next;
        }
        p=head;
        int decimal=0;
        while (p)
        {
            c--;
            if(p->val==1)
            {
                decimal=decimal+pow(2,c);
            }
            p=p->next;
        }
        return decimal;
        
    }
};
