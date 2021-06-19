 bool isPalindrome(ListNode* head) {
	
        stack<ListNode*> nodeStack; // A stack is first in last out, traversing a list is quasi-first in first out
		
        ListNode* pHead = head;
        while (pHead) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
        
        while (head) {
            if (head->val != nodeStack.top()->val) { // We are going forwards on the linked list and backwards via a stack.
                return false;  // If the values differ, well it isn't a palindrome.
            }
            nodeStack.pop(); // Similar to head->next but in reverse.
            head = head->next;
        }
        return true; // If we get to the end of the linked list and the values in the stack didn't differ from those
		// of the linked list, then it is a palindrome.
    }
