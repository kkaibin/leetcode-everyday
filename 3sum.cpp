class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        // sort
        sort(nums.begin(), nums.end());

        // two pointers

        //edge cases
        if(nums.empty()|| nums.back() < 0 || nums.front() > 0||nums.size()<3 ) return {};

        for (int i=0; i<nums.size()-2;++i){
            int L=i+1, R=nums.size()-1;
            while(L<R){
                //no repeat answers
                if(i!=0){
                    if (nums[i]==nums[i-1]) break;
                }
                int sum=nums[L]+nums[R]+nums[i];
                if(sum==0) {
                    res.push_back({nums[i],nums[L],nums[R]});
                    L++;
                    R--;
                    //avoid repeat answers
                    while (L<R && nums[L]==nums[L-1]) L++;
                }
                else if(sum<0) L++;
                else R--;
            }
        }
        return res;
    }
};
