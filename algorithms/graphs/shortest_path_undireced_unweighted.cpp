/*
Given a graph, color the nodes with at most D+1 colors where D is the highest degree
in the graph.

N is the number of nodes and M is the number of edges.

The algorithm is greedy. It iterates over all the nodes, gets their neighbors in constant time.
For each node, at worst all of its neighbors are checkes. Throughout the graph, this happens a total of 2M times.

For each node, at most all of its neighbors' colors have to be checked + 1. In total this is 2M + 1N times in the graph.

Total runtime of O(M + N) and space O(D).
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class GraphNode
{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const
    {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor)
    {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const
    {
        return !color_.empty();
    }

    const string& getColor() const
    {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color)
    {
        color_ = color;
    }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    // create a valid coloring for the graph
    for(auto node : graph) {
        
        unordered_set<GraphNode*> neighbors = node->getNeighbors();
        
        if(neighbors.find(node) != neighbors.end()) {
            throw invalid_argument("loop from a node to iteslf: " + node->getLabel());
        }
        
        unordered_set<string> forbidden_colors;
        
        for(auto neighbor : neighbors) {
            if(neighbor->hasColor()) {
                forbidden_colors.insert(neighbor->getColor());
            }
        }
        
        for(auto color: colors) {
            if(forbidden_colors.find(color) == forbidden_colors.end()) {
                node->setColor(color);
                break;
            }
        }
    }
}
