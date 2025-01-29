//Infinix to Postfix

#include<bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
int priority(char c) 
{
  if (c == '^') return 3;
  else if (c == '/' || c == '*') return 2;
  else if (c == '+' || c == '-') return 1;
  else return -1;
}

string infinix_to_postfix(string s)
{
    stack<char> st; // Stack for operators and parentheses
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        // If the character is an operand, add it to the result
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            ans += c;
        }
        // If the character is an opening parenthesis, push it onto the stack
        else if (c == '(') {
            st.push(c);
        }
        // If the character is a closing parenthesis, pop and output from the stack
        // until an opening parenthesis is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Remove the opening parenthesis from the stack
            }
        }
        // If the character is an operator
        else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s="a+b*(c^d-e)";
    string res=infinix_to_postfix(s);
    cout<<"Infinix expression "<<s<<endl<<"Postfix expression "<<res<<endl;
}