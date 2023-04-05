#include <bits/stdc++.h>
using namespace std;

// Normal multiplication algorithm for 2 numbers of n digits is O(n^2) operation
// But by using karatsuba's multiplication algorithm the number of multiplications can be reduced to O(n^1.58)
// For example if the 2 numbers are 10 and 20
// then by normal multipliaction there would total 4 partial products and then they would be added according
// to their weights, but using karatsuba's algorithm there would be only 3 partial products and then they would be added
// However there is one disadvantage of karatsuba's algorithm, it requires more space than the normal multiplication algorithm
// both numbers should have the same number of digits if not so then pad the smaller number with 0's (only for pen and paper calculations)

// Step 1: digits function calculates the number of digits in an number and returns it

int digits(int nums)
{
  int count = 0;
  while (nums > 0)
  {
    count++;
    nums /= 10;
  }

  return count;
}

// Step 2: karatsuba function takes 2 numbers as input and returns their product
int karatsuba(int x, int y)
{
  // Step 2.1: Base condition of the karatsuba algorithm
  //           when both the numbers are single digits then their product is returned
  if (x < 10 && y < 10)
  {
    return x * y;
  }

  // The reaseon we take n = size / 2 is because we want to split the number into 2 equal parts
  // and the numbers both might not have the same number of digits
  int size = max(digits(x), digits(y));
  int n = ceil(size / 2);
  // The reason we take power = pow(10, n) is because we want to split the number into 2 equal parts
  // power will be used to calculate the a, b, c, d
  int power = pow(10, n);

  // Step 2.2: Splitting the numbers into 2 equal parts and calculating a, b, c, d
  int a = floor(x / power);
  int b = x % power;
  int c = floor(y / power);
  int d = y % power;

  // Step 2.3: Calculating the partial products s1, s2, s3
  int s1 = karatsuba(a, c);
  int s2 = karatsuba(b, d);
  int s3 = karatsuba(a + b, c + d);

  // Step 2.4: Calculating the final product and returning it
  return s1 * pow(10, 2 * n) + (s3 - s2 - s1) * pow(10, n) + s2;
}

int main()
{
  int x, y;
  cin >> x >> y;
  cout << karatsuba(x, y) << endl;
  return 0;
}
