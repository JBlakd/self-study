#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &nums) {
  printf("[");
  for (int i = 0; i < nums.size() - 1; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d]\n", nums[nums.size() - 1]);
}

int search(vector<int> &nums, int target) {
  print_vector(nums);

  if (nums.size() == 1) {
    if (target == nums[0]) {
      return 0;
    } else {
      return -1;
    }
  }

  auto left = nums.begin();
  auto right = nums.end();
  --right;
  auto mid = left + (distance(left, right) / 2);

  while (*left <= *right) {
    if (target < *mid) {
      if (mid == nums.begin()) {
        return -1;
      }
      right = mid - 1;
    } else if (target > *mid) {
      if (mid == (nums.end() - 1)) {
        return -1;
      }
      left = mid + 1;
    } else {
      return distance(nums.begin(), mid);
    }
    mid = left + (distance(left, right) / 2);
  }

  printf("left: %d, right: %d, mid: %d\n", *left, *right, *mid);
  return -1;
}

int main(void) {
  // vector<int> nums = {-1, 0, 3, 5, 9, 12};
  vector<int> nums = {2, 5};

  int result = search(nums, 0);

  printf("%d\n", result);

  return 0;
}