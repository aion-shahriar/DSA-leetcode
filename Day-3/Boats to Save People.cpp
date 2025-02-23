class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the array to allow pairing the lightest and heaviest person
        sort(people.begin(), people.end());
        
        int l = 0;  // Pointer for the lightest person
        int r = people.size() - 1;  // Pointer for the heaviest person
        int ans = 0;  // Counter for the number of boats needed

        while (l <= r) {
            int sum = people[l] + people[r];  // Check the weight of the two people
            
            // If they fit within the weight limit, move both pointers
            if (sum <= limit) {
                ans += 1;  // Use one boat
                l++;  // Move to the next lightest person
                r--;  // Move to the next heaviest person
            } 
            else {
                // If they exceed the limit, the heavier person must go alone
                r--;  // Move to the next heaviest person
                ans += 1;  // Use one boat
            }
        }
        
        return ans;  // Return the total number of boats required
    }
};
