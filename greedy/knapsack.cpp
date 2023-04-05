#include <bits/stdc++.h>
using namespace std;

// Step 1: Creating a class for item

class item
{
public:
  double profit, weight;

  // Step 1.1 : Creating a constructor for item class

  item(double profit, double weight)
  {
    this->profit = profit;
    this->weight = weight;
  }
};

// Step 2: Creating a function to compare the profit/weight ratio of two items

bool compare(item x, item y)
{
  return (x.profit / x.weight > y.profit / y.weight);
}

double knapsack(vector<item> &items, double capacity)
{
  double amount = 0.0;
  // Step 3: Sorting the items in decreasing order of profit/weight ratio
  //         First item in the vector will have the highest profit/weight ratio
  sort(items.begin(), items.end(), compare);
  for (int i = 0; i < items.size(); i++)
  {
    // Step 4: If the weight of item is less than or equal to the current capacity of the knapsack
    //         then it can be added to the knapsack
    if (items[i].weight <= capacity)
    {
      capacity -= items[i].weight;
      amount += items[i].profit;
    }
    // Otherwise we take the fraction of the particular items that can be added to the knapsack
    // and break out of the loop since we have filled the knapsack
    else
    {
      amount += items[i].profit * (capacity / items[i].weight);
      break;
    }
  }
  return amount;
}

int main()
{
  double capacity, nums;
  double profit, weight;
  cout << "enter the number of items: ";
  cin >> nums;
  vector<item> items;

  cout << "enter the capacity of knapsack: ";
  cin >> capacity;

  for (int i = 0; i < nums; i++)
  {
    cout << "enter the profit and weight of item " << i + 1 << ": ";
    cin >> profit >> weight;
    items.push_back(item(profit, weight));
  }

  cout << "maximum profit: " << knapsack(items, capacity) << endl;
}