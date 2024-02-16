#include <iostream>
#include <vector>

using namespace std;
// _____________________
//|                     |
//| Dijkstra algorithm  |
//| implemented in C++  |
//|_____________________|

// _____________________
//|                     |
//|        NODE         |
//|_____________________|
class Node
{
public:
  Node(int id);

private:
  int id;
  vector<pair<Node *, int>> connections;

}; // Class Node

Node::Node(int id)
{
  this->id = id;
} // Node
// _____________________
//|                     |
//|        NODE         |
//|_____________________|

// _____________________
//|                     |
//|       NETWORK       |
//|_____________________|
class Network
{

public:
  Network(/* args */);
  ~Network();

  void addNode();

private:
  /* data */
};

Network::Network(/* args */)
{
}

Network::~Network()
{
}

// _____________________
//|                     |
//|       NETWORK       |
//|_____________________|

// _____________________
//|                     |
//|        MAIN         |
//|_____________________|
int main()
{

  return 0;
}
// _____________________
//|                     |
//|        MAIN         |
//|_____________________|