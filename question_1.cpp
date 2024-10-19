#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int>);
void reverseStack(stack<int>& stk);
void insertAtBottom(stack<int>& st, int element);
int main(){
    stack <int> stk;
    stk.push(31);
    stk.push(30);
    stk.push(29);
    stk.push(28);

    cout << "Oringinal Stack: ";
    printStack(stk);

    reverseStack(stk);

    cout << "Reversed Stack: ";
    printStack(stk);

    return 0;

}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void reverseStack(stack<int>& stk){
    if(stk.empty()){
        return;
    }
    // Hold the top element and pop it
    int topElement = stk.top();
    stk.pop();

    // Recursively reverse the rest of the stack
    reverseStack(stk);

    // Insert the top element at the bottom of the reversed stack
    insertAtBottom(stk, topElement);
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int element) {
    // If the stack is empty, push the element to the bottom
    if (st.empty()) {
        st.push(element);
        return;
    }

    // Hold all elements in the stack until we reach the bottom
    int topElement = st.top();
    st.pop();
    
    // Recursively insert the element at the bottom
    insertAtBottom(st, element);
    
    // Push the top element back on the stack
    st.push(topElement);
}