#include<iostream>
#include <stack>
using namespace std;
int main(void)
{
    stack<int> s;
    cout << "Hello world" << endl;
    s.push(1); 
    s.push(2);
    cout << "poped data = " << s.top() << endl; // 2
    cout << "stack size " << s.size() << endl; // 2
    s.pop();
    cout << "poped data = " << s.top() << endl; //1
    return 1;
    
   
}