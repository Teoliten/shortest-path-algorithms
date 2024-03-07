#include <iostream>
#include <vector>

using namespace std;

// void matrixToList()
// {

// }

void listToMatrix(vector<vector<pair<int, int>>> adjList)
{
  int nodes = adjList.size();
  // cout << "Nodes in provided adjacency list: " << nodes << endl;

  int newMatrix[nodes][nodes]; // create new n*n matrix based on nodes in provided adj. list
  for (int i = 0; i < nodes; i++)
  {
    for (int j = 0; j < nodes; j++)
    {
      newMatrix[i][j] = 0;
    }
  }

  for (int i = 0; i < nodes; i++)
  {
    for (int j = 0; j < adjList[i].size(); j++) // loop for the amount of edges in node
    {
      newMatrix[i][adjList[i][j].first] = adjList[i][j].second;
    }
  }

  cout << "MATRIX: " << endl;
  for (int i = 0; i < nodes; i++)
  {
    for (int j = 0; j < nodes; j++)
    {
      cout << newMatrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // same network of 3 nodes 3 edges represented in both matrix and adjacency list, to check for correct expected output
  int matrix2[4][4] =
      {
          {0, 3, 5, 0},
          {1, 0, 0, 9},
          {0, 4, 0, 0},
          {4, 2, 2, 0}}; // 3x3 matrix, containing network of 3 nodes and 3 edges with weights.

  vector<vector<pair<int, int>>> adjList2 = {
      // 3 nodes, 5 edges with weights
      {{1, 3}, {2, 5}},          // Node 0: (1,3), (2, 5)
      {{0, 1}, {3, 9}},          // Node 1: (0, 1)
      {{1, 4}},                  // Node 2: (1, 4)
      {{1, 2}, {2, 2}, {0, 4}}}; // Node 3: (1, 2), (2, 2), (0, 4)

  // -----------------------------------------------------------------------------------------

  int matrix[3][3] =
      {
          {1, 0, 0},
          {0, 0, 3},
          {2, 0, 0}}; // 3x3 matrix, containing network of 3 nodes and 3 edges with weights.

  vector<vector<pair<int, int>>> adjList = {
      // 3 nodes, 5 edges with weights
      {{1, 4}}, // Node 0: (1,4)
      {{2, 2}}, // Node 1: (2, 2)
      {{0, 1}}, // Node 2: (0, 1)
  };

  listToMatrix(adjList2); // Transform adjacency list to matrix

  return 0;

} // main
