#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int MissingElememnt (vector < int >&array, int n)
  {
    int actualsum = 0, sum = 0, res = 0;
    for (int i = 0; i <= n; i++)
      {
	actualsum += i;
      }
    for (int j = 0; j < n - 1; j++)
      {
	sum += array[j];
      }
    res = actualsum - sum;
    return res;
  }
};

int
main ()
{
  int n;
  cin >> n;
  vector < int >array (n - 1);
  for (int i = 0; i < n - 1; i++)
    {
      cin >> array[i];
    }
  Solution obj;
  cout << obj.MissingElememnt (array, n) << endl;

  return 0;
}
