class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        int maxVal = INT_MIN; // Initialize maxVal with the smallest possible integer
        int l = 0; // Left pointer at the beginning of the array
        int r = nums.size() - 1; // Right pointer at the end of the array

        // Iterate until the left pointer is less than the right pointer
        while (l < r) {
            int sum = nums[l] + nums[r]; // Compute the sum of the current pair
            
            // Update maxVal if the current sum is greater
            if (sum > maxVal) {
                maxVal = sum;
            }
            
            // Move the pointers inward
            l++;
            r--;
        }

        return maxVal;
    }
};
