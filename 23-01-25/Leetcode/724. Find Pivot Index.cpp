// approach 1: brute force
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int leftSum = accumulate(nums.begin(), nums.begin() + i, 0);
        int rightSum = accumulate(nums.begin() + i + 1, nums.end(), 0);
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}
};


// approach 2: prefix sum
class Solution {
public:
int pivotIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}
};


// approach 3: prefix sum with one pass
class Solution {
public:
int pivotIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == (totalSum - nums[i] - leftSum)) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}
};

// approach 4: two pointers
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftSum = 0, rightSum = 0, n = nums.size();
    for (int num : nums) {
        rightSum += num;
    }
    for (int i = 0; i < n; i++) {
        rightSum -= nums[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

