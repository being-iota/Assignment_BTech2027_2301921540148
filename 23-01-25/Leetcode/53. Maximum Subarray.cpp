// approach 1: brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN; 

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}
};

// approach 2: better 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
        
            sum += nums[j];

            maxi = max(maxi, sum); 
        }
    }

    return maxi;
}
};

// approach 3: optimal 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(auto num : nums){
            sum+=num;
            maxSum = max(sum, maxSum);
            sum = max(0, sum);
        }
        return maxSum;
    }
};
