/*
Description
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INT_MAX INT_MAXinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INT_MAX as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INT_MAX.

 

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
//#define INT_MAX INT_MAX
class WallsandGate
{
public:
    void findDistaceFromGate(vector<vector<int>> &rooms);
};

// Test
int main(void)
{
   vector<vector<int>> inp = {{INT_MAX,  -1,  0,  INT_MAX},  {INT_MAX, INT_MAX, INT_MAX,  -1},  {INT_MAX,  -1, INT_MAX,  -1},  {  0,  -1, INT_MAX, INT_MAX}};
   WallsandGate wg ;// = new WallsandGate();
   wg.findDistaceFromGate(inp);
   cout << "OUTPUT" << endl;
   for(int i = 0 ; i < inp.size(); i++)
   {
    for (int j = 0 ; j < inp[0].size(); j++)
    {
            cout << inp[i][j] << " ";
    }
    cout << endl;
    }   
}



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
               // cout << "gates found" << endl;
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
        cout << "Process Q" << "depth = " << d << endl;
        int q_size = myQ.size();
        for(int i = 0; i<q_size; i++)
        {
            //de_q
            auto gm_cord = myQ.front();
            myQ.pop();
            for(int j = 0; j < 4; j++) //check four direction of gate or room
            {
                int adj_x = gm_cord.first + dir[j];
                int adj_y = gm_cord.second + dir[j+1];
                cout << adj_x  << " x " << rows << " " << adj_y  << " x " << cols  <<  endl;
                //if adjacent rooms are valid && value is INT_MAX upate it proper
                if (adj_x >= 0 && adj_x < rows && adj_y >= 0 && adj_y < cols && rooms[adj_x][adj_y] == INT_MAX)
                {
                    cout << "updating" << endl;
                    rooms[adj_x][adj_y] = d;
                    myQ.emplace(adj_x, adj_y);
                }
            }
        }
    }
}
