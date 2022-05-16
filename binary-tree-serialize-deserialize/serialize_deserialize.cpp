#include <iostream>
#include <queue>
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

        // "preorder|inorder"
        string ret;
        dfs_preorder(root, ret);
        // pop the final comma
        ret.pop_back();
        ret.append("|");
        dfs_inorder(root, ret);
        // pop the final comma
        ret.pop_back();

        // cout << ret << endl;

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        vector<int> preorder;
        vector<int> inorder;
        string substr;
        bool populating_preorder = true;

        // parse into arrays
        for (int i = 0; i < data.length(); ++i) {
            switch (data[i]) {
                case ',':
                    if (populating_preorder) {
                        preorder.push_back(stoi(substr, nullptr, 10));
                    } else {
                        inorder.push_back(stoi(substr, nullptr, 10));
                    }
                    substr.clear();
                    break;
                case '|':
                    preorder.push_back(stoi(substr, nullptr, 10));
                    substr.clear();
                    populating_preorder = false;
                    break;
                default:
                    substr.append(1, data[i]);
            }
        }
        // Parse the final substring because it is not followed by any delimiter
        inorder.push_back(stoi(substr, nullptr, 10));

        // populate inorder data into a map for constant time searching
        // unordered_map<int, queue<int>> inorder_map;
        // for (int i = 0; i < inorder.size(); ++i) {
        //     if (inorder_map.find(inorder[i]) == inorder_map.end()) {
        //         queue<int> temp;
        //         temp.push(i);
        //         inorder_map.emplace(inorder[i], temp);
        //     } else {
        //         inorder_map.at(inorder[i]).push(i);
        //     }
        // }

        TreeNode* root = dfs_deser(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder);
        return root;
    }

   private:
    void dfs_preorder(TreeNode* cur_node, string& ret) {
        ret.append(to_string(cur_node->val));
        ret.append(",");
        if (cur_node->left != nullptr) {
            dfs_preorder(cur_node->left, ret);
        }
        if (cur_node->right != nullptr) {
            dfs_preorder(cur_node->right, ret);
        }
    }

    void dfs_inorder(TreeNode* cur_node, string& ret) {
        if (cur_node->left != nullptr) {
            dfs_inorder(cur_node->left, ret);
        }
        ret.append(to_string(cur_node->val));
        ret.append(",");
        if (cur_node->right != nullptr) {
            dfs_inorder(cur_node->right, ret);
        }
    }

    TreeNode* dfs_deser(int pre_start, int pre_end, vector<int>& preorder, int in_start, int in_end, vector<int>& inorder) {
        TreeNode* cur_node = new TreeNode(preorder[pre_start]);

        // Base case: leaf reached
        if (pre_start == pre_end) {
            return cur_node;
        }

        // Find index of cur_node value within inorder array
        // int in_cur_idx = inorder_map[preorder[pre_start]].front();
        // inorder_map[preorder[pre_start]].pop();

        int in_cur_idx;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                in_cur_idx = i;
                break;
            }
        }

        // left next inorder: [in_start, in_cur_idx - 1]
        // num_left_elements = in_cur_idx - in_start
        // num_right_elements = in_end - in_cur_index
        // right next inorder: [in_cur_idx + 1, in_end]
        // left next preorder: [pre_start + 1, pre_start + num_left_elements]
        // right next preorder: [pre_end - num_right_elements + 1 , pre_end]

        int num_left_elements = in_cur_idx - in_start;
        int num_right_elements = in_end - in_cur_idx;

        // dfs left if left child exists
        if (in_cur_idx != in_start) {
            cur_node->left = dfs_deser(pre_start + 1, pre_start + num_left_elements, preorder, in_start, in_cur_idx - 1, inorder);
        }

        // dfs right if right child exists
        if (in_cur_idx != in_end) {
            cur_node->right = dfs_deser(pre_end - num_right_elements + 1, pre_end, preorder, in_cur_idx + 1, in_end, inorder);
        }

        return cur_node;
    }
};

int main() {
    Codec solution;
    string input;
    string serialized;
    TreeNode* deserialized;

    input = "6,0,-1,6,-4|0,-1,6,-4,6";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    input = "4,-7,-3,-9,9,6,0,-1,6,-4,-7,-6,5,-6,9,-2,-3,-4|-7,4,0,-1,6,-4,6,9,-9,5,-6,-7,-2,9,-6,-3,-4,-3";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    input = "6,9,7,2,1,4,2|9,2,7,1,6,2,4";
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

    input = "1|1";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }

    // input = "1:1,2:2,3:3,4:4,7:7,9:9,14:14";
    // deserialized = solution.deserialize(input);
    // serialized = solution.serialize(deserialized);
    // if (serialized.compare(input) == 0) {
    //     cout << "Serialize success: " << input << endl;
    // } else {
    //     cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    // }
}
