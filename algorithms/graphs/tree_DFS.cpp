// Given a BST, 
// traverse its children and add them all
// to a vector in DFS order
// O(n) time and space
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
		stack<Node*> nodes;
		nodes.push(this);
		
		while(!nodes.empty()) {
			Node *current = nodes.top();
			nodes.pop();
			array->push_back(current->name);
			
			int child_count = current->children.size();
			for(int i = child_count-1; i > -1; i--) {
				nodes.push(current->children[i]);
			}
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
