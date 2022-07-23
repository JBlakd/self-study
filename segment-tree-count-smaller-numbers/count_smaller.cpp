#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    tree = vector<tuple<int, int, int>>(4 * nums.size());
    dfs_construct(0, nums.size() - 1, 0, nums);
  }

  void update(int index, int val) {
    dfs_update(0, index, val);
  }

  int sumRange(int left, int right) {
    int ret = 0;
    dfs_sum_range(0, left, right, ret);
    return ret;
  }

 private:
  // <lo, hi, val>
  vector<tuple<int, int, int>> tree;

  int dfs_construct(int lo, int hi, int cur_node, vector<int>& nums) {
    // leaf found
    if (lo == hi) {
      tree[cur_node] = {lo, hi, nums[lo]};
      return nums[lo];
    }

    int mid = lo + (hi - lo) / 2;

    int cur_node_val = dfs_construct(lo, mid, 2 * cur_node + 1, nums) + dfs_construct(mid + 1, hi, 2 * cur_node + 2, nums);
    tree[cur_node] = {lo, hi, cur_node_val};
    return cur_node_val;
  }

  int dfs_update(int cur_node, int index, int val) {
    auto& [lo, hi, cur_val] = tree[cur_node];
    // found
    if (lo == hi) {
      // update
      cur_val = val;
      // return updated value to propagate change upwards
      return cur_val;
    }

    int mid = lo + (hi - lo) / 2;
    if (index <= mid) {
      // recurse left and update current node's value upon returning from function call
      cur_val = dfs_update(2 * cur_node + 1, index, val) + get<2>(tree[2 * cur_node + 2]);
    } else {
      // recurse right
      cur_val = get<2>(tree[2 * cur_node + 1]) + dfs_update(2 * cur_node + 2, index, val);
    }

    return cur_val;
  }

  void dfs_sum_range(int cur_node, int& left, int& right, int& sum) {
    auto& [lo, hi, cur_val] = tree[cur_node];
    int mid = lo + (hi - lo) / 2;

    if (lo >= left && hi <= right) {
      // base case: current node's range is fully encompassed by asking range
      sum += cur_val;
      return;
    }

    // explore both children, but check the validity of the child before making the function call
    if (get<1>(tree[2 * cur_node + 1]) >= left) {
      dfs_sum_range(2 * cur_node + 1, left, right, sum);
    }

    if (get<0>(tree[2 * cur_node + 2]) <= right) {
      dfs_sum_range(2 * cur_node + 2, left, right, sum);
    }
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    // find smallest and largest
    int smallest = numeric_limits<int>::max();
    int largest = numeric_limits<int>::min();
    for (int& num : nums) {
      smallest = min(smallest, num);
      largest = max(largest, num);
    }
    int offset = smallest * -1;

    vector<int> buckets(largest - smallest + 1, 0);
    NumArray seg_tree(buckets);

    vector<int> ret(nums.size(), 0);
    // iterate nums from right to left
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] + offset == 0) {
        // edge case: querying the smallest number is impossible so just set the answer to 0
        ret[i] = 0;

      } else {
        // get answer for current index
        ret[i] = seg_tree.sumRange(0, nums[i] + offset - 1);
      }

      // incrementing bucket to keep track of the count of numbers encountered
      ++buckets[nums[i] + offset];
      seg_tree.update(nums[i] + offset, buckets[nums[i] + offset]);
    }

    return ret;
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
