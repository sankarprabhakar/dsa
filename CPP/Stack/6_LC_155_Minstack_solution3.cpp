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

getmin <-- upload the mins
update <-- top with data - min <== 
pop <== data + min

a b c d
a b-a c-a a-d e-d f-d
d
if poped - min != 

Solution : Using one stack .. push 2*<<input>> - <prev_min>>

*/
#include<iostream>
#include<vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    MinStack()    {
        cout << "Constructor " << endl;
    }
    int getMin()
    {
        if(this->my_stack.empty())
        {
            return -1;
        }
        else
        { 
            return this->min_val;
        }
    }
    void push(int data)
    {
        if (this->my_stack.empty())
        {    
            this->my_stack.push(data);
            this->min_val = data;
            //this->min_stack.push_back(data);
        }
        else if(data < this->min_val)
        {
          // prev_min_val = min_val
          // push (2 * data - prev_min_val)
          // min_val = data
          int prev_min = this->min_val;
          int stack_prev = 2 * data - prev_min;
          this->my_stack.push(stack_prev);
          this->min_val = data; 
        }
        else
        {
            this->my_stack.push(data);
        }
     
    }
    int peep()
    {
        if (this->my_stack.empty() == 1)
        {
            return 0xFFFFFF;
        }
        else
        {
             int data = this->my_stack.top();
             if (data < this->min_val)
             {
                return this->min_val;
             }
             else
             {
                return data;
             }

        }
    }
    int pop()
    {
        if (this->my_stack.empty())
        {
            return 1;
        }
        else{

             int data = this->my_stack.top();
             this->my_stack.pop();
             if (data < this->min_val)
             {
                this->min_val = 2 * this->min_val - data;
             }
        }
    return 0;
    }
private:
    stack<int> my_stack;
    int min_val;
    //vector<int> min_stack;
    
};

int main(void)
{
    MinStack s;
    cout << "empty peep " << s.peep() <<endl;
    s.push(1);
    s.push(2);
    s.push(-3);
    cout << "Get min" << s.getMin() << endl;
    cout << "empty peep " << s.peep() <<endl; // -3
    s.pop();
    cout << "Get min" << s.getMin() << endl;
    cout << "empty peep " << s.peep() <<endl; // 2
    cout << "Get min" << s.getMin() << endl;

}