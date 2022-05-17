#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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
        // deadass just pre-order traverse but include null nodes
        // quit overthinking shit
        string ret;
        dfs(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        vector<int> preorder;
        string substr;

        // parse data into array
        // array[i] == 1001 denotes null
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ',') {
                if (data[i - 1] != 'N') {
                    preorder.push_back(stoi(substr, nullptr, 10));
                } else {
                    preorder.push_back(1001);
                }
                substr.clear();
            } else if (data[i] == 'N') {
                // automatically move to comma
                continue;
            } else {
                substr.append(1, data[i]);
            }
        }

        // Recursive parsing
        int index = 0;
        TreeNode* root = dfs_deser(preorder, index);

        return root;
    }

   private:
    void dfs(TreeNode* cur_node, string& ret) {
        if (cur_node == nullptr) {
            ret.append("N,");
            return;
        }

        ret.append(to_string(cur_node->val));
        ret.append(",");
        dfs(cur_node->left, ret);
        dfs(cur_node->right, ret);
    }

    TreeNode* dfs_deser(vector<int>& preorder, int& index) {
        // Base case
        if (index >= preorder.size()) {
            return nullptr;
        }

        TreeNode* cur_node = nullptr;
        if (preorder[index] != 1001) {
            cur_node = new TreeNode(preorder[index]);
        } else {
            return nullptr;
        }

        index++;
        cur_node->left = dfs_deser(preorder, index);
        index++;
        cur_node->right = dfs_deser(preorder, index);

        return cur_node;
    }
};

int main() {
    Codec solution;
    string input;
    string serialized;
    TreeNode* deserialized;

    input = "6,0,N,-1,N,N,6,-4,N,N,N,";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    input = "3,2,3,N,N,N,4,N,N,";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    input = "3,N,2,N,3,N,4,N,N,";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    // input = "6,0,-1,6,-4|0,-1,6,-4,6";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    // }

    // input = "4,-7,-3,-9,9,6,0,-1,6,-4,-7,-6,5,-6,9,-2,-3,-4|-7,4,0,-1,6,-4,6,9,-9,5,-6,-7,-2,9,-6,-3,-4,-3";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    // }

    // input = "6,9,7,2,1,4,2|9,2,7,1,6,2,4";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    // }

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
    // string empty_string = solution.serialize(nullptr);
    // if (empty_string.compare("") == 0) {
    //     cout << "null TreeNode serialize success" << endl;
    // } else {
    //     cout << "null TreeNode serialize fail" << endl;
    // }

    // TreeNode* null_treenode = solution.deserialize("");
    // if (null_treenode == nullptr) {
    //     cout << "empty string deserialize success" << endl;
    // } else {
    //     cout << "empty string deserialize success" << endl;
    // }

    // input = "";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    // }

    // input = "1,N,N";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    // }

    // input = "1:1,2:2,3:3,4:4,7:7,9:9,14:14";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    // }
}
