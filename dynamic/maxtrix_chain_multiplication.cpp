#include <bits/stdc++.h>
using namespace std;

// In the matrix chain multipliaction problem WE ARE NOT actually multiplying the matrices
// we are trying to find the optimal way to multiply the matrices so that the cost of
// multiplication can be minimized

// The cost of multiplication is defined as the number of multiplications that are performed

// EXAMPLE:
// Let's say we have 4 matrices A, B, C, D, E
// We can multiply them in the following ways
// (A * B) * (C * D) * E
// (A * B) * C * (D * E)
// A * (B * C) * (D * E)
// A * ((B * C) * (D * E))
// A * (B * (C * (D * E)))

// Our goal with problem is to find which of these following multipliactions will result in the least
// number of multiplications

// Formula for the cost of multiplication
// matrix[i, j] = min(i <=k < j) { matrix[i, k] + matrix[k + 1, j] + d[i - 1] * d[k] * d[j] }

int matrix_chain(int i, int j, vector<vector<int>> matrix, vector<int> dimmension)
{
  if (i == j)
  {
    return 0;
  }

  if (matrix[i][j] != -1)
  {
    return matrix[i][j];
  }

  int min_value = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int temp = matrix_chain(i, k, matrix, dimmension) + matrix_chain(k + 1, j, matrix, dimmension) + dimmension[i - 1] * dimmension[k] * dimmension[j];
    min_value = min(min_value, temp);
  }

  matrix[i][j] = min_value;
  return matrix[i][j];
}

int main()
{
  int size;
  cout << "Enter the number of matrices: ";
  cin >> size;
  vector<int> dimmension(size + 1);
  cout << "Enter the dimmensions of the matrices: ";
  for (int i = 0; i < size; i++)
  {
    cin >> dimmension[i];
  }

  vector<vector<int>> matrix(size + 1, vector<int>(size + 1, -1));
  cout << "The minimum number of multiplications required is: " << matrix_chain(1, size, matrix, dimmension) << endl;
  return 0;
}

// int main()
// {
//   vector<int> dimmension = {1, 2, 3, 4};
//   int n = dimmension.size();
//   vector<vector<int>> matrix(n, vector<int>(n, -1));
//   cout << matrix_chain(1, n - 1, matrix, dimmension) << endl;
//   return 0;
// }