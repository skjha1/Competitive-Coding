/*Your program is to use the brute-force approach in order to find the Answer 
to Life, the Universe, and Everything. More precisely… rewrite small numbers from
 input to output. Stop processing input after reading in the number 42.
 All numbers at input are integers of one or two digits.

Sample Input:
1
2
88
42
99
Sample Output:
1
2
88
*/

#include <iostream>
using namespace std;

int main() {
	int i;
	int A[100];
	while (true)
	{
	    cin>>A[i];
	    if (A[i]==42) 
	    {
	        break;
	    }
	    else
	    {
	        cout<<A[i]<<endl;
	    }
	    
	}
	return 0;
}

---------------------


#include <iostream>
using namespace std;

int main() {
	int i;
	int A[INT_MAX];
	for (i=0;i<INT_MAX;i++)
	{
	    cin>>A[i];
	    if (A[i]==42) 
	    {
	        break;
	    }
	    else
	    {
	        cout<<A[i]<<endl;
	    }
	    
	}
	return 0;
}