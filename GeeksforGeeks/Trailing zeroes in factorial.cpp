#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int trailingzero(int N){
        int count=0;
        if (N<=0)
        return -1;
        for (int i=5;N/i>=1;i*=5){
            count+=N/i;
        }
        return count;
        
    }
};

int main (){
    int N;
    cin>>N;
    Solution obj;
    cout << obj.trailingzero(N)<<endl;
    return 0;
}
