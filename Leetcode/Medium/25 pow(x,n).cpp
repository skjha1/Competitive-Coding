class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if (nn<0)  // if number is negetive make it posetive 
            nn=nn*-1;
        while (nn){
            if (nn%2==0) // when power is even
            {
                x*=x; // multiply number by number 
                nn/=2;// devide power by 2
            }
            else // when power is odd
            {
                ans =ans*x;// multiply ans by given number 
                nn-=1; // decrease power everytime 
            }
        }
        if (n<0) // when power is negetive 
            ans=(double)(1.0)/(double)(ans); // keep ans in denominator
        return ans;// at last return the answer 
    }
};
