#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to print the Next Greater Element (NGE) for each element in the array
void printNGE(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;           // Stack to store the indexes of elements
    vector<int> nge(n, -1); // Vector to store the NGE for each element, initialized to -1

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i)
    {
        // Pop elements from the stack that are smaller than or equal to the current element
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        // If the stack is not empty, the top of the stack is the NGE for arr[i]
        if (!s.empty())
        {
            nge[i] = arr[s.top()];
        }

        // Push the current index onto the stack
        s.push(i);
    }

    // Output the NGE results
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main()
{
    vector<int> arr; // Define the vector
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(25);
    printNGE(arr);
    return 0;
}
