/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
#include<iostream>
#include<stack>
#include <vector>

using namespace std;
class ReversePolishEvaluation
{
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand_stack;
        for (string c : tokens)
        {
            if (!this->isOperator(c))
            {
               // cout << "c = " << c << endl;
                operand_stack.push(stoi(c));
            }
            else
            {
                int op1 = operand_stack.top();
                operand_stack.pop();
                int op2 = operand_stack.top();
                operand_stack.pop();
                int op3 = 0;
                if(!c.compare("+"))
                {
                    op3 = op2 + op1;
                }
                else if (!c.compare("-"))
                {
                    op3 = op2 + op1;
                }
                else if (!c.compare("*"))
                {
                  op3 = op2 * op1;  
                }
                else
                {
                    op3 = op2 / op1;
                }
                operand_stack.push(op3);
            }   
        }//for
    return operand_stack.top(); 
    }
    

    bool isOperator(string c)
    {
        //cout << "operator " << c << endl;
        string plus = "+";
        if (c.compare("+") == 0 || c.compare("-") == 0 || c.compare("*") == 0 || c.compare("/") == 0)
        {
            return true;
        }
        //cout << "Ending " << endl;
        return false;    
    }

};

int main(void)
{
    ReversePolishEvaluation rpn;
    vector<string> a = {"10", "6", "7"};
    int evicted = rpn.evalRPN(a);
    cout << evicted <<  endl;

}