#include <iostream>
#include <vector>

using namespace std;

// ------------ NODE ------------

class Node
{
public:
  Node(int id) : id(id) {} // Constructor

  // Add a function to connect this node to another node
  void connect(int value, Node *other);
  // friend class Network;
  int getId() const { return id; }

private:
  int id;
  vector<pair<int, Node *>> connectedNodes; // List of value and pointer pair
};

void Node::connect(int value, Node *other)
{
  connectedNodes.push_back(make_pair(value, other));
} // connect
// ------------ NODE ------------

// ------------ NETWORK ------------
class Network
{
public:
  Network();
  ~Network();

  void addNode(int id, int value);

private:
  vector<pair<int, Node *>> nodesInNetwork; // id, pointer to node
  int nodes;
  Node *root;
};

Network::Network()
{
  Node *rootNode = new Node(0);
  nodesInNetwork.push_back(make_pair(0, rootNode));
  nodes = 1;
  root = rootNode;
}

Network::~Network()
{
  // Implement destructor if necessary
}

void Network::addNode(int id, int value) // id to connect to, value of the connection
{
  // Create a new node
  Node *newNode = new Node(nodes);

  // Search for a node with the given ID in nodesInNetwork
  for (auto &pair : nodesInNetwork)
  {
    if (pair.first == id)
    {
      cout << "found" << endl;
      // Connect the newly created node to the found node
      pair.second->connect(id, newNode);
      break; // Exit loop since we found the node
    }
    else
    {
      cout << "not found" << endl;
    }
  }

  // Increment the node count
  nodes++;

  // Add the new node to the nodesInNetwork vector
  nodesInNetwork.push_back(make_pair(nodes - 1, newNode));
}

// ------------ NETWORK ------------

// ------------ MAIN ------------
int main()
{
  // Create a network
  Network network;

  // Add nodes
  network.addNode(0, 420);
  // network.addNode(1, 421);
  // network.addNode(2, 422);

  return 0;
} // main
  // ------------ MAIN ------------