#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> map;
        queue<Node*> q;

        // create a copy of origin
        Node* node_copy = new Node(node->val);
        // mark origin as explored
        map.insert({node, node_copy});
        q.push(node);

        while (!q.empty()) {
            Node* cur_node = q.front();
            q.pop();
            Node* cur_node_copy = map.at(cur_node);
            for (auto neighbor : cur_node->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    Node* neighbor_copy = new Node(neighbor->val);
                    cur_node_copy->neighbors.push_back(neighbor_copy);
                    map.insert({neighbor, neighbor_copy});
                    q.push(neighbor);
                } else {
                    cur_node_copy->neighbors.push_back(map.at(neighbor));
                }
            }
        }

        return node_copy;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input;

    // input = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    Node* node_1 = new Node(1);
    Node* node_2 = new Node(2);
    Node* node_3 = new Node(3);
    Node* node_4 = new Node(4);
    node_1->neighbors = {node_2, node_4};
    node_2->neighbors = {node_1, node_3};
    node_3->neighbors = {node_2, node_4};
    node_4->neighbors = {node_1, node_3};

    Node* deep_copy = solution.cloneGraph(node_1);
}
