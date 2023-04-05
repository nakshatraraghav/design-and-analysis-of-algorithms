#include <bits/stdc++.h>
using namespace std;

// Step 1: Create a max function that takes 2 inputs and returns the greatest of the 2

int max(int x, int y)
{
  return (x > y ? x : y);
}

// Step 2: Create the cross_sum function that takes the vector nums, low, mid, high values as input
//         What this piece of code does is that it runs from the mid to the low and from the mid + 1 to the high
//         and calculates the maximum possible sum such that sum > left
//         Similarly the value of right is also calculated and the sum of left and right is returned

int cross_sum(vector<int> nums, int low, int mid, int high)
{
  int left = INT_MIN, right = INT_MIN, sum = 0;

  for (int i = mid; i >= low; i--)
  {
    sum += nums[i];
    left = max(left, sum);
  }

  sum = 0;

  for (int i = mid + 1; i <= high; i++)
  {
    sum += nums[i];
    right = max(right, sum);
  }

  return (left + right);
}

// Step 3: Create the max_subarray function that takes the vector nums, low and high as input
//         the maximum sum subarray value can is caluclated using this method
//         its value is equal to the maximum of the following 3 values
//         1) maximum sum subarray value in the left half of the array
//         2) maximum sum subarray value in the right half of the array
//         3) maximum sum subarray value that crosses the mid point of the array
//
//         The maximum sum subarray value that crosses the mid point of the array is calculated using the cross_sum function
//         the maximum of these values is returned
int max_subarray(vector<int> nums, int low, int high)
{
  if (low == high)
  {
    return 0;
  }

  int mid = (low + high) / 2;

  // Step 3.1: Create a temp variable that stores the maximum of the following 2 values
  //           temp variable stores the maximum value of maximym sum subarray value in the left half of the array
  //           and the right half of the array respectively
  int temp = max(max_subarray(nums, low, mid), max_subarray(nums, mid + 1, high));
  return max(temp, cross_sum(nums, low, mid, high));
}

int main()
{
  vector<int> nums = {-3, -4, 5, -1, 2, -4, 6, -1};
  int n = nums.size();
  cout << max_subarray(nums, 0, n - 1);
  return 0;
}