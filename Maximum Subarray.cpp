class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i] 包含i的最大sum
        //dp[i]=max(dp[i-1]+nums[i], nums[i])
        //res 存max

        int dp=0; //為啥不能放INT_MIN (ans: 萬一nums[0]又是負數的話會stack overflow)
        int res=nums[0];

        for (int i=0; i<nums.size();++i){
            dp=max(dp+nums[i],nums[i]);
            res=max(res, dp);
        }
        return res;
    }
};
