/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Solution:
1. Create a stack
2. If open string push to stack
3. if closes paranthesis - then pop and check if it matches if not return false
4. if end of string check if stack is empty if not return false
5. return true.
*/

#include <stack>
#include<iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class ParanthesisValidator
{
    private:
        stack<char> paranthesis;
        string open = "([{";
        string close = ")]}";
        map<char,char> parthesis_match = {
            {'}','{'},
            {')','('},
            {']','['}
        };
        
        bool isOpen(char c)
        {
            for(char s  : this->open)
            {
                if(s == c)
                    return true;
            }
            return false;
        }
         bool isClose(char c)
        {
            for(char s  : this->close)
            {
                if(s == c)
                    return true;
            }
            return false;
        }
        bool isMatch(char c, char o)
        {
            if(o == this->parthesis_match[c])
            {
                //cout << "Open - " << o << "Close = " << c <<  "match" <<endl; 
                return true;
            }
          //  cout << "Open - " << o << "Close = " << c << "Non match" <<endl; 
            return false;

        }
        //string input;
    public:
    bool isValid(string s) {
        for (char c : s)
        {
            if(this->isOpen(c))
            {
                //cout << "open = " << c << endl; 
                this->paranthesis.push(c);
            }
            if(this->isClose(c))
            {
                //cout << "close = " << c << endl;
                if(this->paranthesis.empty())
                {
                    return false;
                }
                else if (!this->isMatch(c, this->paranthesis.top()))
                {
                    return false;
                }
                else
                {
                  //  cout << "poped = " << this->paranthesis.top() << endl;
                    this->paranthesis.pop();
                }
            }

        }
        if(this->paranthesis.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

        
};

int main(void)
{
    string s = "(){[()]{}}";
    ParanthesisValidator p;
    cout << "Valid = " << p.isValid(s) << endl;

}