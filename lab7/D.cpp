#include <bits/stdc++.h>
using namespace std;


const int N = 200005;
map < string, double >g;
 
struct Student
{
  string name;
  string surname;
  double GPA;
 
    Student (string name, string surname, double GPA)
  {
    this->name = name;
    this->surname = surname;
    this->GPA = GPA;
  }
};
 
Student *arr[N];
Student *temp[N];
 
int cmp1 (string a, string b)
{
  for (int i = 0; i < min (a.size (), b.size ()); i++)
    {
      if (a[i] < b[i])
	return 1;
      if (a[i] > b[i])
	return -1;
    }
  if (a.size () != b.size ())
    {
      if (a.size () < b.size ())
	return 1;
      if (a.size () > b.size ())
	return -1;
    }
  else
    {
      return 0;
    }
}
 
bool cmp2 (Student * a, Student * b)
{
  if (a->GPA < b->GPA)
    return true;
  if (a->GPA > b->GPA)
    return false;
  if (a->GPA == b->GPA)
    {
      if (cmp1 (a->surname, b->surname) > 0)
	return true;
      if (cmp1 (a->surname, b->surname) < 0)
	return false;
      if (cmp1 (a->surname, b->surname) == 0)
	return cmp1 (a->name, b->name) > 0;
    }
}
 
void sorting (Student * arr[], int left, int right)
{
  if (left >= right)
    return;
 
  int mid = (left + right) / 2;
 
  sorting (arr, left, mid);
  sorting (arr, mid + 1, right);
 
  int x = left, y = mid + 1, c = 1;
  while (x <= mid or y <= right)
    {
      if (x > mid or (y <= right and cmp2 (arr[y], arr[x])))
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
    arr[left + i - 1] = temp[i];
}
 
int main ()
{
  int n;
  cin >> n;
  g["A+"] = 4;
  g["A"] = 3.75;
  g["B+"] = 3.5;
  g["B"] = 3;
  g["C+"] = 2.5;
  g["C"] = 2;
  g["D+"] = 1.5;
  g["D"] = 1;
  g["F"] = 0;
  for (int i = 0; i < n; i++)
    {
      string name, surname;
      cin >> surname >> name;
      int m;
      cin >> m;
      double sum = 0, cnt = 0;
      for (int j = 0; j < m; j++)
	{
	  string x;
	  int y;
	  cin >> x >> y;
	  cnt += y;
	  sum += g[x] * y;
	}
      double GPA = sum / cnt;
      arr[i] = new Student (name, surname, GPA);
    }
  sorting (arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    {
      cout << fixed << setprecision (3) << arr[i]->surname << " " << arr[i]->
	name << " " << arr[i]->GPA;
    cout << "\n";
    }
  return 0;

}