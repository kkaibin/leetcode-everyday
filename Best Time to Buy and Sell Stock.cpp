class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointers
        //邊找最低點、邊update max profit
//         int maxp=0;
//         int L=0, R=1;

//         for (;R<prices.size();R++){
//             maxp=max(maxp,prices[R]-prices[L]);
//             if(prices[L]>prices[R]){
//                 L=R;
//             }
//         }
//         return maxp;


        //sol2: dp
        //dp[i] 當天賣的最大獲利
        int dp=0;
        int maxp=0;
        for (int i=1; i<prices.size();i++){
            dp=max(dp-prices[i-1]+prices[i], prices[i]-prices[i-1]);
            maxp=max(maxp, dp);
        }
        return maxp;


    }
};
