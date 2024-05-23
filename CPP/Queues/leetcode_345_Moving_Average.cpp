#include<iostream>
#include<queue>

/* Question
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

/*
1. Maintain a queue of size 3 and init will data of 0 and initialize the sum_of_num as 0 and 
   window size as given input value.
2. When new data comes : 
        * Check the size of queue if <  window size insert to queue and add the data to sum
        * If size of queue is >= window size then dequeue one element form queue, enqueue new data 
        and compute the new sum of items in queue (sum + new data - dequeud data)
3. compute the average by sum/window size
*/
using namespace std;
class MovingAverageClass
{
public:
    int insertdata(int data);
    float get_moving_avg(void);
    int print_q_entry(void);
    MovingAverageClass(int window_size)
    {
        this->window_size = window_size;
        this->sum = 0;
        this->moving_average = 0;
        this->data_size = 0;
    }

private:
    queue<int> myQ;
    int window_size;
    int sum;
    float moving_average;
    int data_size;
    };
int MovingAverageClass::insertdata(int data)
{
    if (this->data_size < 3)
    {
        this->myQ.push(data);
        this->sum += data;
        this->data_size += 1;
        this->moving_average = ((float)this->sum) / this->data_size;
    }
    else
    {
        int dq_data = this->myQ.front();
        this->myQ.pop();
        this->myQ.push(data);
        this->sum =  this->sum + data - dq_data;
        this->moving_average = ((float)this->sum) / this->data_size;
    }
    return this->moving_average;
}

float MovingAverageClass::get_moving_avg(void)
{
    return this->moving_average;
}

int MovingAverageClass::print_q_entry()
{
    for(int i =0 ; i< this->data_size; i++)
    {
        ;
    }
    return 1;
}

/*
Test cases
*/
int main(void)
{
    MovingAverageClass m = MovingAverageClass(3);
    m.insertdata(1);
    cout << "Moving avg of data " << m.get_moving_avg() << endl;
    m.insertdata(10);
    cout << "Moving avg of data " << m.get_moving_avg() << endl;
    printf("%f", m.get_moving_avg());
    m.insertdata(3);
    cout << "Moving avg of data " << m.get_moving_avg() << endl;
    m.insertdata(5);
    cout << "Moving avg of data " << m.get_moving_avg() << endl;
    m.insertdata(15);
    //cout << "Moving avg of data " << m.get_moving_avg() << endl;
    

}