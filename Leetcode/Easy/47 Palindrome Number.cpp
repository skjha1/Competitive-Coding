class Solution {
public:
    bool isPalindrome(int x) {
        long long digit,rev=0;
        long long n=x;
        if (x<0)
            return false;
        do
        {
            digit=x%10;
            rev=(rev*10)+digit;
            x/=10;
        }while(x!=0);
        if (rev==n)
            return true;
        return false;
            
    }
};
