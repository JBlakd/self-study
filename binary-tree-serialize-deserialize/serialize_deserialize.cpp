#include <iostream>
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

        // find right-most node to see how many characters the string needs
        TreeNode* cur_node = root;
        int count = 1;
        while (cur_node->right != nullptr) {
            cur_node = cur_node->right;
            count = 2 * count + 1;
        }
        if (cur_node->left != nullptr) {
            count *= 2;
        }

        // Have a vector of ints to hold the serialized result. Turn it into a comma-separated string later.
        // A val of 1001 denotes a null node
        vector<int> vec(count, 1001);

        // Recursively populate vec
        dfs_serial(root, 1, vec);

        // Turn vec into a comma-separated string
        string ret;
        for (int i = 0; i < vec.size(); ++i) {
            ret.append(to_string(vec[i]));

            if (i < vec.size() - 1) {
                // comma
                ret.append(",");
            }
        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        stringstream ss(data);
        vector<int> vec;

        // Parse string into int vector
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            vec.push_back(stoi(substr, nullptr, 10));
        }

        // Create new TreeNodes, store their pointers in treenode_vec;
        vector<TreeNode*> treenode_vec(vec.size(), nullptr);
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] != 1001) {
                treenode_vec[i] = new TreeNode(vec[i]);
            }
        }

        // Link the nodes in treenode_vec
        for (int i = 0; i < treenode_vec.size(); ++i) {
            if (treenode_vec[i] == nullptr) {
                continue;
            }
            int one_index = i + 1;
            if (2 * one_index <= treenode_vec.size()) {
                treenode_vec[i]->left = treenode_vec[2 * one_index - 1];
            }
            if (2 * one_index + 1 <= treenode_vec.size()) {
                treenode_vec[i]->right = treenode_vec[2 * one_index];
            }
        }

        return treenode_vec[0];
    }

   private:
    void dfs_serial(TreeNode* cur_node, int one_index, vector<int>& vec) {
        vec[one_index - 1] = cur_node->val;
        if (cur_node->left != nullptr) {
            dfs_serial(cur_node->left, 2 * one_index, vec);
        }
        if (cur_node->right != nullptr) {
            dfs_serial(cur_node->right, 2 * one_index + 1, vec);
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
    Codec solution;
    string input;
    string serialized;
    TreeNode* deserialized;

    input = "1,2,3,1001,1001,4,5,1001,1001,1001,1001,6,7";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

    input = "1,2,3,1001,1001,4,5,6,7";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << " Expected: " << input << endl;
    }

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

    input = "69";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }

    input = "1,2,3,4,1001,1001,7,1001,9,1001,1001,1001,1001,14";
    deserialized = solution.deserialize(input);
    serialized = solution.serialize(deserialized);
    if (serialized.compare(input) == 0) {
        cout << "Serialize success: " << input << endl;
    } else {
        cout << "Serialize fail. Got: " << serialized << ". Expected: " << input << endl;
    }
}
