#include<bits/stdc++.h>
using namespace std;
 
int temp[505][505], n, m;
 
bool cmp (int a[], int b[])
{
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < m; i++)
    {
      sum1 += a[i];
      sum2 += b[i];
    }
  if (sum1 == sum2)
    {
      for (int i = 0; i < m; i++)
	{
	  if (a[i] < b[i])
	    return 1;
	  if (a[i] > b[i])
	    return 0;
	}
    }
  return sum1 > sum2;
}
 
void sorting (int arr[][505], int left, int right)
{
  if (left >= right)
    return;
 
  int mid = (left + right) / 2;
 
  sorting (arr, left, mid);
  sorting (arr, mid + 1, right);
 
  int x = left, y = mid + 1, cur = 1;
  while (x <= mid or y <= right)
    {
      if (x > mid or (y <= right and cmp (arr[y], arr[x])))
	{
	  for (int i = 0; i < m; i++)
	    {
	      temp[cur][i] = arr[y][i];
	    }
	  y++;
	}
      else
	{
	  for (int i = 0; i < m; i++)
	    {
	      temp[cur][i] = arr[x][i];
	    }
	  x++;
	}
      cur++;
    }
 
  for (int i = 1; i <= right - left + 1; i++)
    {
      for (int j = 0; j < m; j++)
	{
	  arr[left + i - 1][j] = temp[i][j];
	}
    }
}
 
int main ()
{
  cin >> n >> m;
  int arr[505][505];
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
	{
	  cin >> arr[i][j];
	}
    }
  sorting (arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
	{
	  cout << arr[i][j] << " ";
	}
      cout << endl;
    }
  return 0;
}