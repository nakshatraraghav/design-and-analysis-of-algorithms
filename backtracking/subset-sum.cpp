#include <bits/stdc++.h>
using namespace std;

void print_solution(vector<int> selected)
{
  for (int i = 0; i < selected.size(); i++)
  {
    cout << selected[i] << " ";
  }
  cout << "\n";
}

bool solve(vector<int> nums, vector<int> selected, int target, int sum, int index)
{
  if (target == sum)
  {
    print_solution(selected);
    return true;
  }

  for (int i = index; i < nums.size(); i++)
  {
    if (nums[i] + sum <= target)
    {
      sum += nums[i];
      selected.push_back(nums[i]);
      if (solve(nums, selected, target, sum, index + 1))
      {
        return true;
      }
      selected.pop_back();
      sum -= nums[i];
    }
  }
  return false;
}

int main()
{
  vector<int> nums = {10, 7};
  vector<int> selected;
  int target = 35;
  int sum = 0;
  int index = 0;
  bool solved = solve(nums, selected, target, sum, index);
  if (!solved)
    cout << "No solution found\n";
  return 0;
}