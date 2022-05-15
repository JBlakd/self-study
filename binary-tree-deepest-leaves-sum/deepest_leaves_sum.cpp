#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int deepestLeavesSum(TreeNode *root) {
        // Priority queue to store all the visited leaves. Deepest leaves are prioritised
        priority_queue<pair<int, TreeNode *>> leaves;
        dfs(root, leaves, 0);

        // Extract the leaves of the deepest depth from the pq
        int deepest_sum = 0;
        while (!leaves.empty()) {
            auto cur_top = leaves.top();
            deepest_sum += cur_top.second->val;
            leaves.pop();
            if (cur_top.first != leaves.top().first) {
                break;
            }
        }

        return deepest_sum;
    }

   private:
    void dfs(TreeNode *cur_node, priority_queue<pair<int, TreeNode *>> &leaves, int depth) {
        // Base case: return on a leaf node
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            leaves.emplace(depth, cur_node);
            return;
        }

        if (cur_node->left != nullptr) {
            dfs(cur_node->left, leaves, depth + 1);
        }
        if (cur_node->right != nullptr) {
            dfs(cur_node->right, leaves, depth + 1);
        }
    }
};

template <typename T>
void print_vector(vector<T> vec) {
    cout << "{";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}";
}

int main() {
    Solution solution;
    vector<TreeNode *> input;
    vector<int> node_vals;

    node_vals = {8};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    cout << solution.deepestLeavesSum(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {8, 1, 2};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    cout << solution.deepestLeavesSum(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();

    node_vals = {1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, -1, -1, 8};
    // Node initialisation
    for (int val : node_vals) {
        if (val == -1) {
            input.push_back(nullptr);
            continue;
        }
        TreeNode *cur_node = new TreeNode(val);
        input.push_back(cur_node);
    }
    // Node connection
    for (int i = 0; i < input.size(); ++i) {
        int left_index = (i + 1) * 2 - 1;
        int right_index = (i + 1) * 2;

        if (input[i] == nullptr) {
            continue;
        }

        if (left_index < input.size()) {
            input[i]->left = input[left_index];
        }
        if (right_index < input.size()) {
            input[i]->right = input[right_index];
        }
    }
    cout << solution.deepestLeavesSum(input[0]) << endl;
    for (auto node : input) {
        delete node;
    }
    input.clear();
    node_vals.clear();
}
