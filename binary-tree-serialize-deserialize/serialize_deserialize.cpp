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
        // deadass just pre-order traverse but include null nodes
        // quit overthinking shit
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
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
