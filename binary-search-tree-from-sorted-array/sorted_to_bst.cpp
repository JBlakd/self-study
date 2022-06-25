#include <cassert>
#include <iostream>
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        nums_ptr = &nums;
        return dfs(0, nums.size() - 1);
    }

   private:
    vector<int> *nums_ptr;

    TreeNode *dfs(int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }

        int mid = lo + ((hi - lo) / 2);
        TreeNode *cur_node = new TreeNode(nums_ptr->at(mid));

        cur_node->left = dfs(lo, mid - 1);
        cur_node->right = dfs(mid + 1, hi);

        return cur_node;
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

    /* UNIT TESTS HERE */

    cout << "Great success!" << '\n';
}
