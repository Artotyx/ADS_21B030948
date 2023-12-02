#include <bits/stdc++.h>
 
using namespace std;
 
int main ()
{
  int n, m;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
  int x = 0, y = 0;
  while (x < n or y < m)
    {
      if (x >= n or (y < m && b[y] < a[x]))
	{
	  cout << b[y] << " ";
	  y++;
	}
      else
	{
	  cout << a[x] << " ";
	  x++;
	}
    }
  return 0;

}