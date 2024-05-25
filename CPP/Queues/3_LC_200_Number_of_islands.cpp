/* Given an m x n 2D binary grid grid which represents a map of 1s (land) and 0s (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is 0 or 1.
*/
#include<iostream>
#include<queue>
using namespace std;
class NumberOfIslands
{
  public:
    int numberofislands(vector<vector<int>> &island);
  private:
    //int navigate_adj_area(vector<vector<int>> &island, int i, int j);
    void markIsLand(vector<vector<int>> &island, int r, int c, int total_rows, int total_cols);
};

int NumberOfIslands::numberofislands(vector<vector<int>> &island)
{
  int rows = island.size();
  int cols = island[0].size();
  int number_of_islands = 0;
  if (rows == 0)
  {
    return 0;
  }
  cout << 2 << endl;
  for (int i = 0;  i < rows; i++)
  {
    for (int j = 0; j < cols ; j++)
    {
      if(island[i][j] == 1)
      {
       // cout << "land = 1" << " x = " << i << "y = " << j << endl; 
        this->markIsLand(island,i,j,rows,cols);
        number_of_islands++;
      }
    }
  }
  return number_of_islands;
}
void NumberOfIslands::markIsLand(vector<vector<int>> &island, int r, int c, int total_rows, int total_cols)
{
   queue<pair<int,int>> q;
   vector<int> dirs = {-1,0,1,0,-1};
   q.emplace(r,c);
  // insert to Q
  // While Q is not empty 
  // Dequeue the front and mark as visited(2)
  // find the nearby lands and insert to Q
  while(!q.empty())
  {
    auto land  = q.front();
    q.pop();
    island[land.first][land.second] = 2;
    for(int i = 0; i < 4; i++)
    {
       int x_next = land.first + dirs[i];
       int y_next = land.second + dirs[i+1];
       if (x_next >= 0 &&  x_next < total_rows && y_next >=0 && y_next < total_cols && island[x_next][y_next] == 1)
       {
          q.emplace(x_next,y_next);
       }
    }
  }
}

int main(void)
{
  vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    NumberOfIslands no_island;
    cout << "1" << endl;
    int count = no_island.numberofislands(grid);
    cout << "Number of island = " << count << endl;
}
