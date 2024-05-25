/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

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
grid[i][j] is '0' or '1'.
*/
#include<iostream>
#include<queue>
using namespace std;
class NumberOfIslands
{
  public:
    int numberofislands(vector<vector<int>> &island);
  private:
    int navigate_adj_area(vector<vector<int>> &island, int i, int j);
};

int NumberOfIslands::numberofislands(vector<vector<int>> &island)
{
  int rows = island.size();
  int cols = island[0].size();
  if (rows == 0)
  {
    return 0;
  }
  for (int i = 0;  i < rows; i++)
  {
    for (int j = 0; i < cols ; j++)
    {
      
    }
  }
}
