class Solution {
public:
    bool isPalindrome(ListNode* head) {
            
        vector <int> v;  // creating a vector 
        while (head!=0) // while elements is there in the linkedlist
        {
            v.push_back(head->val); // put all the element in the vector from the list 
            head=head->next; // move everytime pointer to the next 
        }
        int first= 0, last= v.size()-1; // setting first as zero and last as the size of the list
        while (first<last) // as long as they both meet 
        {
            if (v[first++] != v[last--]) // compare if they are not equal then false else true 
                return false;            
        }
        return true;
    }
};
