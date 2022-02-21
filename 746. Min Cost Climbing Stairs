class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        //[10]
        if (cost.size()==0) return 0;
        if (cost.size()==1) return cost[0];

        int pre=0;
        int cur=0;

        for(int i=2; i<=cost.size();i++){
            int temp=cur;
            cur=min(cur+cost[i-1],pre+cost[i-2]);
            pre=temp;
        }
        return cur;
    }
};
