class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Step 1: Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Initialize closest sum with the first three elements
        int close_dif = nums[0] + nums[1] + nums[2];

        // Step 2: Iterate through each number as the first element of the triplet
        for(int i = 0; i < nums.size(); i++) {

            // Initialize two pointers
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];  // Calculate current sum
                int dif = abs(target - sum);  // Difference between sum and target
                int close = abs(close_dif - target);  // Difference for closest sum

                // If the exact target sum is found, return it immediately
                if(sum == target) return sum;

                // If this sum is closer to the target, update close_dif
                if(dif < close) {
                    close_dif = sum;
                }

                // Move pointers accordingly
                if(sum < target) {
                    j++;  // Increase sum by moving left pointer forward
                } else {
                    k--;  // Decrease sum by moving right pointer backward
                }
            }
        }
        return close_dif;  // Return the closest sum found
    }
};
