class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        // Note:
        //需考慮k=0的情況

        unordered_map<int, int>m;
        int cnt=0;

        for (int n : nums) m[n]++;
        for (auto item: m ){
            if(k==0 && m[item.first]>=2) cnt++;
            if(k>0 && m.count(item.first+k)) cnt++;
        }
        return cnt;
    }
};
