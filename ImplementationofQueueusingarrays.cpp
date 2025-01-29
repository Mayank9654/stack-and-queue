#include<bits/stdc++.h>
using namespace std;

class Queue 
{
    int *a;
    int start, end, currSize, maxSize;
    public:
    Queue() 
    {
      a = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxs) 
  {
    maxSize = maxs;
    a = new int[maxs];
    start = -1;
    end = -1;
    currSize = 0;
  }
  
  void push(int newElement) 
  {
    if (currSize == maxSize) 
    {
      cout << "Queue is full\nExiting..." << endl;
    }
    if (end == -1) 
    {
      start = 0;
      end = 0;
    } 
    else end = (end + 1) % maxSize;
    a[end] = newElement;
    currSize++;
  }
  
  int pop() {
    if (start == -1) cout << "Queue Empty" << endl;
    int popped = a[start];
    if (currSize == 1) 
    {
      start = -1;
      end = -1;
    } 
    else start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() 
  {
    if (start == -1) 
    {
      cout << "Queue is Empty" << endl;
    }
    return a[start];
  }
  int size() 
  {
    return currSize;
  }

};

int main() 
{
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;
  return 0;
}