/*Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait 
after the ith day to get a warmer temperature. If there is no future day for
 which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

solution : Monotonic decreasing Stack.. when a value high than top is found pop stack till empty 
or value < cur val is found... then push value to stack with index. When we do pop from stack we will
be able to find the delta days to current day using the index stored. 

*/
#include<iostream>
#include<vector>
#include <stack>

using namespace std;

class DailyTemperature{
public:
    // stack stores the value in decending order..
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> answer(len);
        stack<pair<int,int>> data_stack;
        //cout << "len = " << len << endl;
        for(int i = 0; i<len;i++)
        {
            int cur_temp = temperatures[i];

            while (!data_stack.empty() && data_stack.top().first < cur_temp)
            {
                // count++;
                //cout << "Poping = " << data_stack.top().first << endl;
                auto stack_top = data_stack.top();
                int delta_for_higher_temp = i - stack_top.second;
                answer[stack_top.second] = delta_for_higher_temp;
                data_stack.pop();
            }
            data_stack.emplace(cur_temp,i);
        }
        // Not required if anwer is initialized with 0
       /* while (!data_stack.empty())
        {
            auto stack_top = data_stack.top();
            int delta_for_higher_temp = 0;
            answer[stack_top.second] = delta_for_higher_temp;
            data_stack.pop();
        }
        */
        
        return answer;
    }
 };

 int main(void)
 {
    DailyTemperature d;
    vector<int> temp = {1,2,3,5,6};
    d.dailyTemperatures(temp);
    return 1;
 }