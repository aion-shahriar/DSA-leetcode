class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>withidx;
        vector<int>ans;
        for(int i=0;i<nums.size();i++) {
            withidx.push_back(make_pair(nums[i],i));
        }
        sort(withidx.begin(),withidx.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r) {
            int sum=withidx[l].first+withidx[r].first;
            if(sum==target) {
                ans.push_back(withidx[l].second);
                ans.push_back(withidx[r].second);
                break;
            }
            else if(sum>target) r--;
            else l++;
        }
        return ans;
    }
};
