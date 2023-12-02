#include<bits/stdc++.h>
const int N = 2e5 + 7;
 
using namespace std;
 
string a[N], temp[N];
 
bool 
cmp (string a, string b)
{
  if (a.size () > b.size ())
    return false;
  if (a.size () < b.size ())
    return true;
  return false;
}
 
void 
sorting (string a[], int left, int right)
{
  if (left >= right)
    return;
 
  int mid = (left + right) / 2;
 
  sorting (a, left, mid);
  sorting (a, mid + 1, right);
 
  int x = left, y = mid + 1, cur = 1;
  while (x <= mid or y <= right)
    {
      if (x > mid or (y <= right and cmp (a[y], a[x])))
	{
	  temp[cur] = a[y];
	  y++;
	}
      else
	{
	  temp[cur] = a[x];
	  x++;
	}
      cur++;
    }
 
  for (int i = 1; i <= right - left + 1; i++)
    {
      a[left + i - 1] = temp[i];
    }
}
 
int main ()
{
  int t;
  cin >> t;
  string s;
  getline (cin, s);
  while (t--)
    {
      getline (cin, s);
      string q = "";
      int n = 0;
      for (int i = 0; i < s.size (); i++)
	{
	  if (s[i] != ' ')
	    {
	      q += s[i];
	    }
	  else
	    {
	      a[n] = q;
	      n++;
	      q = "";
	    }
	}
      if (!q.empty ())
	{
	  a[n] = q;
	  n++;
	}
      sorting (a, 0, n - 1);
      for (int i = 0; i < n; i++)
	{
	  cout << a[i] << " ";
	}
      cout << endl;
    }
  return 0;
}