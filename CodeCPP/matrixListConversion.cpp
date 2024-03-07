#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
  cout << "Matrix: " << endl;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix.size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
} // printMatrix

// void matrixToList()
// {
// }

vector<vector<int>> listToMatrix(const vector<vector<pair<int, int>>> &adjList)
{
  int nodes = adjList.size();
  vector<vector<int>> newMatrix(nodes, vector<int>(nodes, 0)); // create new n*n matrix initialized with 0s

  for (int i = 0; i < nodes; i++)
  {
    for (int j = 0; j < adjList[i].size(); j++)
    {
      newMatrix[i][adjList[i][j].first] = adjList[i][j].second;
    }
  }

  return newMatrix;
} // listToMatrix

int main()
{
  // same network of 4 nodes 8 edges represented in both matrix and adjacency list, to check for correct expected output
  vector<vector<int>> matrix =
      {
          {0, 3, 5, 0},
          {1, 0, 0, 9},
          {0, 4, 0, 0},
          {4, 2, 2, 0}}; // 4x4 matrix, containing network of 4 nodes and 8 edges with weights.

  vector<vector<pair<int, int>>> adjList = {
      // 4 nodes, 8 edges with weights
      {{1, 3}, {2, 5}},          // Node 0: (1,3), (2, 5)
      {{0, 1}, {3, 9}},          // Node 1: (0, 1)
      {{1, 4}},                  // Node 2: (1, 4)
      {{1, 2}, {2, 2}, {0, 4}}}; // Node 3: (1, 2), (2, 2), (0, 4)

  // --------------------------------------

  vector<vector<int>> resultMatrix = listToMatrix(adjList); // Transform adjacency list to matrix
  printMatrix(resultMatrix);                                // print generated matrix

  return 0;

} // main
