class Solution {
public:
    int nextGreaterElement(int n) {
        stringstream ss;
        ss<<n;
        string str=ss.str();

        next_permutation(begin(str),end(str));

        long long result=stoll(str);

        if(result>INT_MAX || result<=n) return -1;
        else return result;
        
    }
};
