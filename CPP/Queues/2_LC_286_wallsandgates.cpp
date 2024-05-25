/*
Description
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 

Example 1:



Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]
 

Constraints:

m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
*/

#include<iostream>
#include<queue>

#define INT_MAX  2147483647 
using namespace std;

// Test
int main(void)
{
    
    
}


class WallsandGate
{
public:
    void findDistaceFromGate(vector<vector<int>> &rooms);
};

void WallsandGate::findDistaceFromGate(vector<vector<int>> &rooms)
{
    // Enqueue all gates to Queue
    queue<pair<int,int>> myQ;
    int rows = rooms.size();
    int cols = rooms[0].size();
    for(int i = 0 ; i < rows; i++)
    {
        for (int j = 0 ; j < cols; j++)
        {
            if(rooms[i][j] == 0)
            {
                myQ.emplace(i,j);
            }
        }
    }
    // define distance 
    int d = 0;
    vector<int> dir = {-1,0,1,0,-1} ; //left, up,right, down
    while(!myQ.empty())
    {
        d++; // increase the distance
        int q_size = myQ.size();
        for(int i = 0; i<q_size; i++)
        {
            //de_q
            auto gm_cord = myQ.front();
            myQ.pop();
            for(i = 0; i < 4; i++) //check four direction of gate or room
            {
                int adj_x = gm_cord.first + dir[i];
                int adj_y = gm_cord.second + dir[i+1];
                //if adjacent rooms are valid && value is inf upate it proper
                if (adj_x >= 0 && adj_x < rows && adj_y >= 0 && adj_y > cols && rooms[adj_x][adj_y] == INT_MAX)
                {
                    rooms[adj_x][adj_y] = d;
                }
            }
        }
    }
}
