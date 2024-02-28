#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int id;
  vector<pair<int, Node *>> connectedNodes; // List of value and pointer pair

  Node(int id) : id(id) {} // Constructor

  // Add a function to connect this node to another node
  void connect(Node *other, int value)
  {
    connectedNodes.push_back(make_pair(value, other));
  }
};

class Network
{
public:
  Network();
  ~Network();

  void addNode(int id, int value);

  int nodes;
  Node *root;
};

Network::Network()
{
  nodes = 0;      // Initialize to 0, we increment it when adding nodes
  root = nullptr; // Initialize to nullptr
}

Network::~Network()
{
  // Implement destructor if necessary
}

void Network::addNode(int id, int value)
{
  // Create a new node
  Node *newNode = new Node(id);

  if (!root)
  {
    root = newNode; // If root is nullptr, set the new node as root
  }
  else
  {
    // Connect the new node to the previous node
    Node *prevNode = root;
    while (!prevNode->connectedNodes.empty())
    {
      prevNode = prevNode->connectedNodes[0]; // Follow the chain of connections
    }
    prevNode->connect(newNode);
  }

  nodes++; // Increment the node count
}

int main()
{
  // Create a network
  Network network;

  // Add nodes
  network.addNode(0, 0);
  network.addNode(1, 5);
  network.addNode(2, 8);

  // Print connections (just for visualization)
  Node *current = network.root;
  while (current)
  {
    cout << "Node " << current->id << " is connected to: ";
    for (Node *connected : current->connectedNodes)
    {
      cout << connected->id << " ";
    }
    cout << endl;
    if (!current->connectedNodes.empty())
    {
      current = current->connectedNodes[0];
    }
    else
    {
      current = nullptr;
    }
  }

  return 0;
}
