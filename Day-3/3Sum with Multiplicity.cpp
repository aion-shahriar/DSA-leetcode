class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long MOD = 1e9 + 7;  // Modulo value to prevent overflow
        long long ans = 0;  // Variable to store the final result
        sort(arr.begin(), arr.end());  // Sort the array to handle duplicate elements

        for (int i = 0; i < arr.size() - 2; i++) {
            int j = i + 1;  // Pointer to the next element after 'i'
            int k = arr.size() - 1;  // Pointer to the last element

            while (j < k) {  // Continue until pointers 'j' and 'k' meet
                long long sum = arr[i] + arr[j] + arr[k];  // Calculate the sum of the three elements

                if (sum == target) {  // If the sum matches the target
                    long long cnt1 = 1;  // Count of elements equal to arr[j]
                    long long cnt2 = 1;  // Count of elements equal to arr[k]

                    // Count how many times arr[j] repeats
                    while (j < k && arr[j] == arr[j + 1]) {
                        cnt1++;
                        j++;
                    }

                    // Count how many times arr[k] repeats
                    while (j < k && arr[k] == arr[k - 1]) {
                        cnt2++;
                        k--;
                    }

                    cnt1 = cnt1 % MOD;  // Take mod to prevent overflow
                    cnt2 = cnt2 % MOD;  // Take mod to prevent overflow

                    if (j == k) {  // If j and k meet, it means we have duplicates at a single point
                        long long add = (cnt1 * (cnt1 - 1) / 2) % MOD;  // Combination of cnt1 elements taken 2 at a time
                        ans = (ans + add) % MOD;  // Add to the result
                    }
                    else {  // If j and k are different, we multiply the counts
                        long long add = (cnt1 * cnt2) % MOD;  // Multiply the counts of repeated elements
                        ans = (ans + add) % MOD;  // Add to the result
                    }
                    j++;  // Move j pointer
                    k--;  // Move k pointer
                }
                else if (sum < target) {  // If the sum is less than the target, move the j pointer
                    j++;
                }
                else {  // If the sum is greater than the target, move the k pointer
                    k--;
                }
            }
        }

        return ans;  // Return the result modulo 1e9 + 7
    }
};
