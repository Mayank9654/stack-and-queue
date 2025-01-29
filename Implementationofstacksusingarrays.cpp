//Implementation of stack using an array
#include<bits/stdc++.h>
using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() 
    {
      top = -1;
      size = 1000;
      arr = new int[size];
    }

  void push(int x) 
  {
    top++;
    arr[top] = x;
  }
  int pop() 
  {
    int x = arr[top];
    top--;
    return x;
  }
  int Top()
  {
    return arr[top];
  }
  int Size() 
  {
    return top + 1;
  }
};
int main() 
{
  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack " << s.Top() << endl;
  cout << "Size of stack  " << s.Size() << endl;
  cout << "Deleted element is " << s.pop() << endl;
  cout << "Size of stack  " << s.Size() << endl;
  cout << "Top of stack " << s.Top() << endl;
  return 0;
}