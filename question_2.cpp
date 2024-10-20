#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;           
    vector<int> nge(n, -1); 

   
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            nge[i] = arr[s.top()];
        }
        s.push(i);
    }
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
