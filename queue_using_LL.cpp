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

class queueUsingLL
{
    public:
    Node* start;
    Node* end;
    int sizeLL=0;
    void push(int val)
    {
        Node* temp=new Node(val);
        if(start==NULL)
        {
            start=temp;
            end=temp;
        }
        else
        {
            end->next=temp;
            end=end->next;
        }
        sizeLL++;
    }
    void pop()
    {
        if(start==NULL) return;
        Node* temp=start;
        start=start->next;
        delete temp;
        sizeLL--;
    }
    int top() 
    {
        if(start==NULL) return 0;
        return start->data;
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
    queueUsingLL ob;
    ob.push(7);
    ob.push(2);
    ob.push(3);
    ob.push(6);
    cout<<ob.top()<<" ";
    ob.pop();
    cout<<ob.top()<<" ";
    ob.pop();
    ob.pop();
    cout<<ob.top()<<" ";
}