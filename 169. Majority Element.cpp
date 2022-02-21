class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //sol 1 time: O(n); space: O(n)
        //iterate through nums, store the frequency in a hashmap
        //return the number with the highest frequency
        // unordered_map<int, int> map;
        // for (int i: nums) map[i]++;
        // int max=INT_MIN;
        // int maxi=nums[0];
        // for (auto i: map){
        //     if(max<i.second){
        //         max=i.second;
        //         maxi=i.first;
        //     }
        // }
        // return maxi;

        //sol2 Moore Voting
        //+1
        //see a different number from curmax, -1
        //if sum up to 0, start the next from +1

        int sum=0;
        int res=nums[0];
        for (int i: nums){
            if (sum==0){
                sum=1;
                res=i;
            }
            else if (i==res) {
                ++sum;
            }
            else {
                --sum;
            }
        }
        return res;

    }
};
