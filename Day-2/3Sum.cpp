class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;  

        // Step 1: Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());  

        // Step 2: Iterate through each number as the first element of the triplet
        for(int i = 0; i < nums.size(); i++) {  

            // Skip duplicate numbers to avoid duplicate triplets
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;  // Left pointer
            int k = nums.size() - 1;  // Right pointer

            // Step 3: Use two-pointer approach to find pairs that sum to -nums[i]
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {  
                    // Found a valid triplet, add it to the result
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;  

                    // Skip duplicate numbers to avoid duplicate triplets
                    while(nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
                else if(sum < 0) {  
                    // If sum is too small, move the left pointer to the right
                    j++;
                }
                else {  
                    // If sum is too large, move the right pointer to the left
                    k--;
                }
            }
        }
        return ans;  // Return the list of unique triplets
    }
};
