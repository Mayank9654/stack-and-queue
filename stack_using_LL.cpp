#include <bits/stdc++.h>
using namespace std;
    
class Node
{
    public:
    int data;
    Node* next;
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }
};

class stackUsingLL
{
    public:
    Node* topElement;
    int sizeLL=0;
    void push(int d)
    {
        Node* temp=new Node(d);
        temp->next=topElement;
        topElement=temp;
        sizeLL++;
    }
    void pop()
    {
        Node* temp=topElement;
        topElement=topElement->next;
        sizeLL--;
        delete temp;
    }
    int top()
    {
        return topElement->data;
    }
    int size()
    {
        return sizeLL;
    }
};

Node* convertArrayToLL(vector<int>a)
{
    Node* head=new Node(a[0]);
    Node* prev=head;
    for(int i=1;i<a.size();i++)
    {
        Node* temp=new Node(a[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    vector<int> a={1,2,3,4,5};
    // Node* head=convertArrayToLL(a);
    // display(head);
    stackUsingLL ob;
    ob.push(2);
    ob.push(5);
    ob.push(7);
    cout<<ob.top()<<" ";
    ob.pop();
    cout<<ob.top()<<" ";
    ob.pop();
    cout<<ob.top()<<" ";
}