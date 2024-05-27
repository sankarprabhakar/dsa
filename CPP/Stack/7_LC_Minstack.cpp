/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
#include<iostream>
#include <vector>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
        cout << "Constructor " << endl;
    }
    void push(int data)
    {
        if (this->stack.empty())
        {
            this->min = data;
            this->stack.push_back(0);
        }
        else if (data > this->min)
        {
            this->stack.push_back(data - this->min);
        }
        else
        {
            this->stack.push_back(data - this->min);
            this->min = data;
        }
        return;
    }
    int peep()
    {
        if (this->stack.empty() == 1)
        {
            return 0xFFFFFF;
        }
        else
        {
            return this->stack.back();
        }
    }
    int pop()
    {
        if (this->stack.empty())
        {
            return 1;
        }
        else{
            this->stack.pop_back();
            return 0;
        }
    }
private:
    vector<int> stack;
    int min;
};

int main(void)
{
    MinStack s;
    cout << "empty peep " << s.peep() <<endl;
    s.push(1);
    s.push(2);
    s.push(-3);
    cout << "empty peep " << s.peep() <<endl; // -3
    s.pop();
    cout << "empty peep " << s.peep() <<endl; // 2

}