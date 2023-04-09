#include <bits/stdc++.h>
using namespace std;

struct candidate
{
  int rank;
  int status;
};

void randomized_hiring(vector<candidate> candidates)
{
  int rand_idx;
  int nums_hired = 0, best_candiate = -1;
  srand(time(NULL));

  for (int i = 0; i < candidates.size(); i++)
  {
    do
    {
      rand_idx = rand() % candidates.size();
    } while (candidates[rand_idx].rank == 1);

    if (best_candiate == -1)
    {
      best_candiate = rand_idx;
      nums_hired++;
    }
    else if (candidates[best_candiate].rank < candidates[rand_idx].rank)
    {
      best_candiate = rand_idx;
      nums_hired++;
    }
  }
  cout << "nr of hired candidates is " << nums_hired << "\n";
  cout << "best candidate index and rank " << best_candiate << ", " << candidates[best_candiate].rank;
}

int main()
{
  // int size;
  // cout << "enter the number of candidates : ";
  // cin >> size;
  vector<candidate> candidates = {{6}, {4}, {12}, {11}, {13}, {10}, {15}, {8}};

  randomized_hiring(candidates);
}