#include <bits/stdc++.h>
using namespace std;

// Step 1: Create a node structure with a letter, frequency, left and right child
struct node
{
  char letter;
  int frequency;

  node *left;
  node *right;

  // Step 1.1 Create a constructor to assign the values letter and freqeuency
  node(char letter, int frequency)
  {
    this->letter = letter;
    this->frequency = frequency;
  }
};

// Step 2: Overload the operator() to compare the frequencies of the nodes
struct compare
{
  // Step 2.1: Create a bool operator() to compare the frequencies of the nodes
  bool operator()(node *left, node *right)
  {
    return (left->frequency > right->frequency);
  }
};

// Step 3: Create a function to print the solution
void print_solution(node *root, string code)
{
  // Step 3.1: Check if the root is null or not
  if (root != NULL)
  {
    // Step 3.2: This condition will only be triggered when the current node is a leaf node
    if (root->letter != '*')
    {
      // Step 3.3: We basically print the character and the code
      cout << root->letter << "\t" << code << "\n";
    }
    else
    {
      // Step 3.4 Since the character is a internal node (not a leaf node) we call the same
      //          print solution function recursively and
      //          when we are going left we add 0 to the string or when we are going right
      //          we add 1 to the code word string
      print_solution(root->left, code + "0");
      print_solution(root->right, code + "1");
    }
  }
}

// Step 4: Creating the main Huffman function the will encode the letters
void huffman(vector<char> &letters, vector<int> frequencies)
{
  // Step 4.1: Create a min heap priority queue to store the nodes in the heap and the compare function will be used
  // to compare the nodes in the heap based on the frequency of the nodes in the heap
  // and the compare function is defined above in the code snippet and the priority queue will be of type node *.
  priority_queue<node *, vector<node *>, compare> pq;

  // Step 4.2: Initializing the priority queue with the nodes
  for (int i = 0; i < letters.size(); i++)
  {
    pq.push(new node(letters[i], frequencies[i]));
  }

  // Step 4.3: Creating the temporary left and right nodes;
  node *left_child, *right_child;

  // Step 4.4: Creating the huffman tree
  //           this loop will run until there is only one node in the priority queue
  //           which must be the node with the root of the huffman tree
  while (pq.size() != 1)
  {
    // Step 4.5: Priority Queue's pop function doesnt return the element that is popped from the queue
    //           so we take the top of the queue and store it in the left and right variables respectively
    left_child = pq.top();
    pq.pop();
    right_child = pq.top();
    pq.pop();

    // Step 4.6: We have basically popped the 2 nodes with the lease frequency
    //           and now we will create a node with its frequency equal to the sum of both of them
    node *new_node = new node('*', left_child->frequency + right_child->frequency);
    // Step 4.7: And since we want to create and traverse this tree we will attach the nodes stored in left and right
    //           to the left and right of this newly created node
    new_node->left = left_child;
    new_node->right = right_child;

    // Step 4.8 Those 2 nodes have been removed from the queue and have been attached to the newly created node
    pq.push(new_node);
    // Step 4.9: This newly created node has been pushed into the priority queue, and it would be placed at a positon
    //           according to its frequency
  }

  print_solution(pq.top(), " ");
}

void run()
{
  char letter;
  int nums, frequency;
  vector<char> letters;
  vector<int> frequencies;
  cout << "Enter the number of characters : ";
  cin >> nums;
  for (int i = 0; i < nums; i++)
  {
    cout << "Enter the " << i + 1 << " th character : ";
    cin >> letter;
    letters.push_back(letter);
    cout << "Enter " << letter << "'s frequency :";
    cin >> frequency;
    frequencies.push_back(frequency);
  }

  huffman(letters, frequencies);
}

int main()
{
  run();
  return 0;
}