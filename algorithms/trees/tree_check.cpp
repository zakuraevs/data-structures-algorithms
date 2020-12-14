#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// REMOVE ALL THE MEMBERS_ FROM OUTSIDE CLASS DEFINITIONS
class Node {
  private: 
    
    
  public:
    std::string value;
    Node* left_child;
    Node* right_child;
    Node* parent;
  
    Node(){
        value = -1;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr; 
    }
    
    Node(std::string input_value) {
        value = input_value;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }
    
};

class UnionFindDS {
    
  public:
    std::unordered_map<std::string, int> ranks_;
    std::unordered_map<std::string, Node> parents_;
    int number_of_elements_;
    int number_of_sets_;
    
    UnionFindDS() {
        number_of_elements_ = 0;
        number_of_sets_ = 0;
    }
    
    bool MakeSet(Node node) {
        if(parents_.find(node.value) == parents_.end()) {
            parents_[node.value] = node;
            ranks_[node.value] = 0;
            ++number_of_elements_;
            ++number_of_sets_;
            return true;
        } else {
            return false;
        }
    }
    
    Node FindSet(Node node) {
        Node parent = parents_[node.value];
        if(parent.value == node.value) return node;
        return FindSet(parent);
    }
    
    // By reference here?
    void Union(Node first, Node second) {
        Node parent1 = parents_[first.value];
        Node parent2 = parents_[second.value];
        
        Node root1 = FindSet(first);
        Node root2 = FindSet(second);
        
        if(root1.value != root2.value) {
            if(ranks_[root1.value] > ranks_[root2.value]){
                parents_[root2.value] = root1;
            } else {
                parents_[root1.value] = root2;
                if(ranks_[root1.value] == ranks_[root2.value]) {
                    ranks_[root2.value] = ranks_[root2.value] + 1;
                } 
            }
            number_of_sets_ -= 1;
        }
    }

};

/*void print_valid_tree(Node current_node, std::string& output) {
    output += "(";
    output += current_node.value;
    // FIX
    if(current_node.left_child== nullptr && current_node.right_child == nullptr) {
    // Has a left child.    
    } else {
        
        if(current_node.left_child != nullptr && current_node.right_child == nullptr) {
            print_valid_tree(*current_node.left_child, output);
        } else if(current_node.left_child == nullptr && current_node.right_child != nullptr) {
            print_valid_tree(*current_node.right_child, output);
        } else {
            if(current_node.right_child > current_node.left_child) {
                print_valid_tree(*current_node.left_child, output);
                print_valid_tree(*current_node.right_child, output);
            } else {
                print_valid_tree(*current_node.right_child, output);
                print_valid_tree(*current_node.left_child, output);
            }
        }   
    }
    output += ")";
}*/
void print_valid_tree(Node current_node, std::string& output) {
    output += "(";
    output += current_node.value;
    // FIX
    if(current_node.left_child == nullptr && current_node.right_child == nullptr) {
    // Has a left child.    
    } else {
        
        if(current_node.left_child != nullptr && current_node.right_child == nullptr) {
            print_valid_tree(*current_node.left_child, output);
        } else if(current_node.left_child == nullptr && current_node.right_child != nullptr) {
            print_valid_tree(*current_node.right_child, output);
        } else {
            if(current_node.right_child->value > current_node.left_child->value) {
                print_valid_tree(*current_node.left_child, output);
                print_valid_tree(*current_node.right_child, output);
            } else {
                print_valid_tree(*current_node.right_child, output);
                print_valid_tree(*current_node.left_child, output);
            }
        }   
    }
    output += ")";
}

bool treeContainsCycles(Node node, int actual_size, int& counter, std::unordered_set<std::string> visited) {
    
    counter += 1;
    visited.insert(node.value);
    
    if(node.parent != nullptr && visited.find(node.parent->value) == visited.end()) {
        treeContainsCycles(*node.parent, actual_size, counter, visited);
    }
    if(node.left_child != nullptr && visited.find(node.left_child->value) == visited.end()) {
        treeContainsCycles(*node.left_child, actual_size, counter, visited);
    }
    if (node.right_child != nullptr &&
        visited.find(node.right_child->value) == visited.end()) {
      treeContainsCycles(*node.right_child, actual_size, counter, visited);
    }

    if(counter > actual_size) return true;
    return false;
    
}

int main() {
    
    // The initial imput string
    std::string input;
    std::getline(std::cin, input);
    
    // Precomputing input size
    int n = input.size();
    
    // Initializing the map that represents the tree
    // char -> node
    std::unordered_map<std::string, Node> tree;
    
    
    UnionFindDS sets;
    
    // This is bad!
    std::unordered_map<std::string, Node> parents;
    std::unordered_map<std::string, Node> children;
    std::vector<std::string> found_errors;
    
    // Handle E1 here!
    int no_errors = true;
    if(input[0] != '(' || input[n-1] != ')') {
        no_errors = false;
        found_errors.push_back("E1");
    }
    int i = 1;
    while(i < n && no_errors) {
        std::string parent;
        std::string child;
        parent = input[i];
        i += 2;
        child = input[i];
        
        if(i >= n) break;
        
        // Creating nodes and adding them to the tree.
        // BAD!!
        if(parents.find(parent) != parents.end() && children.find(child) != children.end()) {
            // E2
            found_errors.push_back("E2");
        }
        // BAD
        Node new_parent_temp(parent);
        parents[parent] = new_parent_temp;
        
        Node new_child_temp(child);
        children[child] = new_child_temp;
        
        sets.MakeSet(new_parent_temp);
        sets.MakeSet(new_child_temp);
        sets.Union(new_parent_temp, new_child_temp);
        
        if(tree.find(parent) == tree.end()) {
            Node new_parent(parent);
            tree[parent] = new_parent;
        } 
        if(tree.find(child) == tree.end()) {
            Node new_child(child);

            new_child.parent = &tree[parent];
            tree[child] = new_child;
        } else {
            // HMMMM
            if(tree[child].parent != nullptr) {
                found_errors.push_back("E4");
            }
            tree[child].parent = &tree[parent];
        }
            
        // Adding child to the parent
        if(tree[parent].left_child == nullptr) tree[parent].left_child = &tree[child];
        else if (tree[parent].right_child == nullptr)
          tree[parent].right_child = &tree[child];
        else {
            // E3
            found_errors.push_back("E3");
        }
        i += 3;
        if(input[i] != '(' && i < n) {
            no_errors = false;
            found_errors.push_back("E1");
        }
        i += 1;
    }
    
    // E5
    if(sets.number_of_sets_ > 1) {
        found_errors.push_back("E5");
    } 
    
    std::string output = "";
    std::unordered_set<std::string> visited;
    int counter = 0;
    if(treeContainsCycles(tree[std::string(1,input[1])], sets.number_of_elements_, counter, visited)) {
        found_errors.push_back("E4");
    } else {
        // Need to traverse the tree to the root.
        Node root = tree[std::string(1,input[1])];
        while(root.parent != nullptr) {
            root = *root.parent; 
        } 
        
        print_valid_tree(root, output);
    }
    
    //BAD
    if(!found_errors.empty()) {
        std::sort(found_errors.begin(), found_errors.end());
        std::cout << found_errors[0] << std::endl;
    } else {
        std::cout << output << std::endl;
    }
    return 0;
}