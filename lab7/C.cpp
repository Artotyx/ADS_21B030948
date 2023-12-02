#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 7;
int temp[N];

void sorting (int arr[], int left, int right)
{
  if (left >= right)
    {
      return;
    }
 
  int mid = (left + right) / 2;
 
  sorting (arr, left, mid);
  sorting (arr, mid + 1, right);
 
  int x = left, y = mid + 1, c = 1;
  while (x <= mid or y <= right)
    {
      if (x > mid or (y <= right and arr[y] < arr[x]))
	{
	  temp[c] = arr[y];
	  y++;
	}
      else
	{
	  temp[c] = arr[x];
	  x++;
	}
      c++;
    }
 
  for (int i = 1; i <= right - left + 1; i++)
    {
      arr[left + i - 1] = temp[i];
    }
}
 
bool f[N];
int arr[N], b[N], n, m;
 
int main ()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
  sorting (b, 0, m - 1);
  sorting (arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
	{
	  if (!f[j])
	    {
	      if (b[j] == arr[i])
		{
		  f[j] = true;
		  cout << arr[i] << " ";
		  break;
		}
	    }
	}
    }
  return 0;
}