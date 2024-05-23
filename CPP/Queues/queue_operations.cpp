#include<iostream>
#include <queue>
using namespace std;

// use inbuild Q and use it for the Q operations 1. Enqueue 2. Dequeue 3. First Element
int main(void)
{
    cout << "Hello " << endl;
    queue<int> myq;
    myq.push(1);
    myq.push(2);
    myq.push(3);
    myq.push(4);
    myq.push(5);
    cout << "data size in Q = " << myq.size() << endl;
    cout << "front in Q = " << myq.front() << endl;
    cout << "data at back  of Q = " << myq.back() << endl;
    myq.pop(); // pop out one element
    //myq.pop()
    cout << "Popping first element " <<  myq.front() <<  endl; // 4 expected
    return 0;
}