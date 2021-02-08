/* 
Given an Integer N, write a program to reverse it.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, display the reverse of the given number N, in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
4
12345
31203
2123
2300
Output
54321
30213
3212
32
*/
#include <iostream>
using namespace std;

int main() {
	int no,i;
	cin>>no;
	int A[no];
	for (i=0;i<no;i++)
	{
	    cin>>A[i];
	    int temp= A[i];
	    A[i]=0;
	    while(temp!=0)
	    {
	        int rem= temp%10;
	        A[i]=A[i]*10+rem;
	        temp=temp/10;
	    }
	}
	for (i=0;i<no;i++)
	{
	    cout<<A[i]<<endl;
	}
	
	return 0;
}
