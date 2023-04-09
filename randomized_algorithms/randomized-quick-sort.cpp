#include <bits/stdc++.h>
using namespace std;

void swap_values(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void print_array(vector<int> array)
{
  for (int i = 0; i < array.size(); i++)
  {
    cout << array[i] << " ";
  }
  cout << "\n";
}

void quick_sort(vector<int> &array, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  srand(time(NULL));
  int pivot = (rand() % (right - left + 1)) + left;
  swap_values(&array[pivot], &array[left]);
  pivot = left;

  int l = left, r = right;

  while (l < r)
  {
    while (array[pivot] >= array[l])
    {
      l++;
    }

    while (array[pivot] < array[r])
    {
      r--;
    }

    if (l < r)
    {
      swap_values(&array[l], &array[r]);
    }
  }

  swap_values(&array[pivot], &array[r]);
  quick_sort(array, left, r - 1);
  quick_sort(array, r + 1, right);
}

int main()
{
  int size;
  cout << "enter the size : ";
  cin >> size;
  vector<int> array(size, 0);
  cout << "enter the array : \n";
  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }
  cout << "\narray before sorting : \n";
  print_array(array);
  quick_sort(array, 0, array.size() - 1);
  print_array(array);
  return 0;
}