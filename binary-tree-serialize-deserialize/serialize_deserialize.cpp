#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        // Have a hashmap to hold the serialized result. Turn it into a comma-separated string later.
        // Key is the one-index, val is the TreeNode*
        unordered_map<unsigned long long, TreeNode*> hashmap;

        // Recursively populate hashmap
        unsigned long long max_one_index = 0;
        dfs_serial(root, 1, hashmap, max_one_index);

        // Turn hashmap into a comma-separated string
        string ret;
        for (auto& entry : hashmap) {
            ret.append(to_string(entry.first));
            ret.append(":");
            ret.append(to_string(entry.second->val));
            ret.append(",");
        }
        // Pop the last comma
        ret.pop_back();
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        stringstream ss(data);
        unordered_map<unsigned long long, TreeNode*> hashmap;

        // Parse string into hashmap
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            string key = substr.substr(0, substr.find(':'));
            string val = substr.substr(substr.find(':') + 1);
            TreeNode* node = new TreeNode(stoi(val, nullptr, 10));
            hashmap.emplace(stoull(key, nullptr, 10), node);
        }

        // Recursively link the nodes in hashmap
        dfs_deserial(hashmap, 1);

        return hashmap[1];
    }

   private:
    void dfs_serial(TreeNode* cur_node, unsigned long long one_index, unordered_map<unsigned long long, TreeNode*>& hashmap, unsigned long long& max_one_index) {
        hashmap.emplace(one_index, cur_node);
        if (one_index > max_one_index) {
            max_one_index = one_index;
        }
        if (cur_node->left != nullptr) {
            dfs_serial(cur_node->left, 2 * one_index, hashmap, max_one_index);
        }
        if (cur_node->right != nullptr) {
            dfs_serial(cur_node->right, 2 * one_index + 1, hashmap, max_one_index);
        }
    }

    void dfs_deserial(unordered_map<unsigned long long, TreeNode*>& hashmap, unsigned long long cur_node_one_index) {
        // if left child exists
        if (hashmap.find(2 * cur_node_one_index) != hashmap.end()) {
            // connect cur_node to left child
            hashmap[cur_node_one_index]->left = hashmap[2 * cur_node_one_index];
            // visit left child
            dfs_deserial(hashmap, 2 * cur_node_one_index);
        }

        // if right child exists
        if (hashmap.find(2 * cur_node_one_index + 1) != hashmap.end()) {
            // connect cur_node to right child
            hashmap[cur_node_one_index]->right = hashmap[2 * cur_node_one_index + 1];
            // visit left child
            dfs_deserial(hashmap, 2 * cur_node_one_index + 1);
        }
    }
};

int main() {
    Codec solution;
    string input;
    string serialized;
    TreeNode* deserialized;

    input = "1:1,2:2,3:3,6:4,7:5,12:6,13:7";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    // invalid
    // input = "1,2,3,1001,1001,4,5,6,7";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    // }

    // Test serialize null TreeNode
    string empty_string = solution.serialize(nullptr);
    if (empty_string.compare("") == 0) {
        cout << "null TreeNode serialize success" << endl;
    } else {
        cout << "null TreeNode serialize fail" << endl;
    }

    TreeNode* null_treenode = solution.deserialize("");
    if (null_treenode == nullptr) {
        cout << "empty string deserialize success" << endl;
    } else {
        cout << "empty string deserialize success" << endl;
    }

    input = "";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }

    input = "1:69";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }

    input = "1:1,2:2,3:3,4:4,7:7,9:9,14:14";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }
}
