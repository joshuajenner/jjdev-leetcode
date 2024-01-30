// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//
// Evaluate the expression.Return an integer that represents the value of the expression.
//
// Note that :
//
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32 - bit integer.

#include <vector>
#include <string>
#include <stack>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    stack<int> st;
    void operation(string &op)
    {
        if (st.empty())
            return;

        int n2 = st.top();
        st.pop();

        if (st.empty())
            return;

        int n1 = st.top();
        st.pop();

        int x;
        switch (op[0])
        {
        case '+':
            x = n1 + n2;
            break;
        case '-':
            x = n1 - n2;
            break;
        case '*':
            x = n1 * n2;
            break;
        case '/':
            x = n1 / n2;
            break;
        }
        st.push(x);
    }
    int evalRPN(vector<string> &tokens)
    {
        for (string &s : tokens)
        {
            if (s.size() > 1 || isdigit(s[0]))
            {
                int x = stoi(s);
                st.push(x);
            }
            else
                operation(s);
        }

        if (st.empty())
            return 0;

        return st.top();
    }
};