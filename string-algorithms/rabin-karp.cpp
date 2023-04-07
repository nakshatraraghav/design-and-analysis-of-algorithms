#include <bits/stdc++.h>
using namespace std;

#define prime 13

// Rabin-Karp Algorithm
// Time Complexity: O(N + M)

// The Rabin-Karp algorithm is a string matching algorithm that uses hashing to find the pattern string in the main string.
// it works by calculating the hash value of the pattern string and the hash value of the first substring of the main string
// it then checks if these values are equal, if so then only then it performs the string matching operation. (same as naive)
// it then subsequently calculates the hash value of the next substring and checks if they are equal

// The hash function used in rabin karp should be gast and have low chances of spurious hits
// commonly used hashing function is the rollng hash function
// which calculates the hash value of the next string by using the previous string's hash value
// it calculates the hash value of the string by treating it as a polynomial with coeffs corresponding to the ascii values of the characters
// and the degree of the polynomial is the length of the string

// However the Rabin-Karp algorithm is much faster than the naive string matching algorithm because it uses hashing

// Rabin-Karp function takes in 2 strings as input and returns the number of occurences of the pattern string in the main string
// if the pattern string does not occur in the main string then it returns -1
int rabin_karp(string str, string pat)
{
  // Step 1: Declare the variables
  const int slen = str.length(), plen = pat.length();
  const int maxchar = 10;

  int string_hash = 0, pattern_hash = 0;
  int h = 1, count = 0;

  // Step 2: Calculate maxchar^(plen-1) % prime and store it in h
  for (int i = 0; i < plen - 1; i++)
  {
    h = (h * maxchar) % prime;
  }

  // Step 3: Calculate the hash value of the pattern string and the first substring of the main string
  for (int i = 0; i < plen; i++)
  {
    pattern_hash = (pattern_hash * maxchar + pat[i]) % prime;
    string_hash = (string_hash * maxchar + str[i]) % prime;
  }

  // Step 4: Initialize the loop
  for (int i = 0; i < slen - plen; i++)
  {
    int j = 0;
    // Step 5: Check if the hash values are equal if so then only perform the string matching operation
    if (string_hash == pattern_hash)
    {
      while (j < plen && str[i + j] == pat[j])
      {
        j++;
      }

      if (j == plen)
      {
        cout << "pattern found at index : " << i << "\n";
        count++;
      }
    }
    // Step 6: Calculate the hash value of the next substring
    string_hash = ((string_hash - str[i] * h) * maxchar + str[i + j]) % prime;
    if (string_hash < 0)
    {
      string_hash += prime;
    }
  }

  // Retrun the number of occurences of the pattern string in the main string or -1 if
  // the pattern string does not occur in the main string
  if (count != 0)
  {
    return count;
  }
  else
  {
    return -1;
  }
}

int main()
{
  int maxchar;
  string x, y;
  cout << "enter the first string : ";
  cin >> x;
  cout << "enter the second string: ";
  cin >> y;
  int occurences = rabin_karp(x, y);
  if (occurences != -1)
  {
    cout << "the pattern string occured " << occurences << " times in the main string \n";
  }
  else
  {
    cout << "pattern string does not occur in the main string";
  }
  return 0;
}