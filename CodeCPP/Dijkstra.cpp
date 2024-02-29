#include <iostream>
#include <vector>

using namespace std;

// ------------ NODE ------------
class Node
{
public:
  Node(int id) : id(id) {} // Constructor
  void connect(int value, Node *other);
  int getId() const { return id; }

private:
  int id;
  vector<pair<int, Node *>> connectedNodes; // connection value, and pointer to node

}; // Class Node

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
  void addConnection(int id, int id2);

private:
  vector<pair<int, Node *>> nodesInNetwork; // id, pointer to node
  int nodes;
  Node *root;
}; // Class Network

Network::Network()
{
  Node *rootNode = new Node(0);
  nodesInNetwork.push_back(make_pair(0, rootNode));
  nodes = 1;
  root = rootNode;
} // Constructor

Network::~Network()
{
  // Implement destructor if necessary
} // Destructor

void Network::addNode(int id, int value)
{
  // Create a new node
  bool found = false;
  Node *newNode = new Node(nodes);

  // Search for a node with the given ID in nodesInNetwork
  for (auto &pair : nodesInNetwork)
  {
    if (pair.first == id)
    {
      found = true;
      // Connect the newly created node to the found node
      newNode->connect(value, pair.second);
      pair.second->connect(value, newNode);
      break; // Exit loop since we found the node
    }
  }

  if (found)
  {
    // Increment the node count
    nodes++;

    // Add the new node to the nodesInNetwork vector
    nodesInNetwork.push_back(make_pair(nodes - 1, newNode));
  }
  else
  {
    cout << "addNode_err: connecting node not found" << endl;
  }
} // addNode

void Network::addConnection(int id, int id2)
{
  Node *node1;
  Node *node2;

  bool f1 = false, f2 = false;

  for (auto &pair : nodesInNetwork)
  {
    if (pair.first == id)
    {
      node1 = pair.second; // link node1 to the found node
      f1 = true;
    }
    else if (pair.first == id2)
    {
      node2 = pair.second; // link node2 to the found node
      f2 = true;
    }
  }

  if (f1 && f2) // both nodes found and pointers saved
  {
    node1->connect(id2, node2);
    node2->connect(id, node1);
  }
  else // didnt find both nodes
  {
    cout << "addConnection_err: nodes not found" << endl;
  }
} // addConnection
// ------------ NETWORK ------------

// ------------ MAIN ------------
int main()
{
  // Create a network
  Network network; // creates root node, id: 0

  // Add nodes
  // network.addNode(0, 420);  // id: 1
  // network.addNode(0, 421);  // id: 2
  // network.addNode(1, 422);  // id: 3
  // network.addNode(3, 111);  // id: 4
  // network.addNode(10, 111); // no node with id 10, wont create node.

  network.addNode(0, 2); // id:1
  network.addNode(0, 6); // id:2
  network.addNode(1, 5); // id:3
  // network.addConnection(3, 2); // connecting node 2 and 3

  while (true)
  {
  }

  return 0;
} // main
  // ------------ MAIN ------------