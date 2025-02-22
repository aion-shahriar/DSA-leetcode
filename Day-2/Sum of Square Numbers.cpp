class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int l=0;
        long long int r=sqrt(c);
        while(l<=r) {
            long long int sum=l*l+r*r;
            if(sum==c) return true;
            else if(sum<c) l++;
            else r--;
        }
        return false;
    }
};
