#include <bits/stdc++.h>
using namespace std;

// The 0/1 Knapsack problem is a classic optimization problem in computer science and operations research.
// The problem is defined as follows: Given a set of items, each with a weight and a value,
// determine the number of each item to include in a collection so that the total weight is less than or equal
// to a given limit and the total value is as large as possible

// Step 1: Create a structure variable to store the prfit and the weight of the item
struct item
{
  double profit, weight;

  // Step 1.1: Create a constructor to initialize the profit and weight of the item
  item(double profit, double weight)
  {
    this->profit = profit;
    this->weight = weight;
  }
};

// Step 2: Create a function to calculate the maximum profit of the items that can be stored in the knapsack
//         It takes the following inputs
//         1. items: The vector of items
//         2. dp: The 2D vector to store the intermediate results
//         3. capacity: The capacity of the knapsack
//         4. nums: The number of items
int knapsack(vector<item> items, vector<vector<int>> &dp, double capacity, int nums)
{
  // Step 2.1: This is the base case of the recursion whenever the capacity of the knapsack is 0 or the number of items is 0
  //           we have exhause all the items or the knapsack is full
  if (nums == 0 || capacity == 0)
  {
    return 0;
  }

  // Step 2.2: Since the base case was not triggered it means that we are in the clear
  //           we are checking in the dp vector if this result has already been calculated or not
  //           if so then we will directly return this result
  if (dp[nums][capacity] != -1)
  {
    return dp[nums][capacity];
  }
  else
  {
    // Step 2.3: If the weight of the current item is greater than or equal to the capacity of the knapsack then it cannot
    //           be included in the knapsack so we will call the function again with the same capacity and the next item
    if (items[nums - 1].weight > capacity)
    {
      dp[nums][capacity] = knapsack(items, dp, capacity, nums - 1);
      return dp[nums][capacity];
    }
    // Step 2.4: Since the item has a weight less than the capacity of the knapsack we have two options
    //           1. We can reject the item and move on to the next item
    //           2. We can accept the item and move on to the next item
    //           We will take the that choice which results in greater profit so we will take the max of the two
    int rejected = knapsack(items, dp, capacity, nums - 1);
    int accepted = items[nums - 1].profit + knapsack(items, dp, capacity - items[nums - 1].weight, nums - 1);

    // And then store the result in the dp vector so that it can be used in the future
    dp[nums][capacity] = max(rejected, accepted);
    return dp[nums][capacity];
  }
}

int main()
{
  int nums;
  cout << "Enter the number of items: ";
  cin >> nums;
  double capacity;
  cout << "Enter the capacity of the knapsack: ";
  cin >> capacity;

  vector<vector<int>> dp(nums + 1, vector<int>(capacity + 1, -1));

  vector<item> items(nums, item(0, 0));

  for (int i = 0; i < nums; i++)
  {
    cout << "Enter the profit and weight of item " << i + 1 << ": ";
    cin >> items[i].profit >> items[i].weight;
  }

  cout << "Maximum profit: " << knapsack(items, dp, capacity, nums) << endl;
}

// int main()
// {
//   vector<item> items;
//   items.push_back(item(60, 10));
//   items.push_back(item(100, 20));
//   items.push_back(item(120, 30));

//   int capacity = 50;
//   int nums = items.size();

//   cout << knapsack(items, capacity, nums) << endl;
//   return 0;
// }