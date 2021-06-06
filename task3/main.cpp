#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;


class StackNode {
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}

int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";

    cout << "Top element is " << peek(root) << endl;

    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }

    cout<<endl<<"-----------------------------------------------------------"<<endl;

    queue<string> q;

    q.push("A");        // Insert `A` into the queue
    q.push("B");        // Insert `B` into the queue
    q.push("C");        // Insert `C` into the queue
    q.push("D");        // Insert `D` into the queue

    // Returns the total number of elements present in the queue
    cout << "The queue size is " << q.size() << endl;

    // Prints the front of the queue (`A`)
    cout << "The front element is " << q.front() << endl;

    // Prints the rear of the queue (`D`)
    cout << "The rear element is " << q.back() << endl;

    q.pop();            // removing the front element (`A`)
    q.pop();            // removing the next front element (`B`)

    cout << "The queue size is " << q.size() << endl;

    // check if the queue is empty
    if (q.empty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }
    return 0;
}
