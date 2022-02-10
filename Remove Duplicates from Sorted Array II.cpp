class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointers
        //一個指向(R)要裝數字的位置、一個指向(L)要裝的數字
        //一個count來儲存數字的次數
        //在count<=2，
        // if(nums.size()==0) return 0;

        int L=1;
        int R=1;
        int pre=nums[0];
        int count=1;
        for (;R<nums.size();R++){
            //先update R
            if(nums[R]==pre){
                count++;
            }
            else count=1;
            //如果R的count<=2，儲存到L所在的地方。
            if(count<=2){
                nums[L]=nums[R];
                L++;
            }
            //update L & pre
            pre=nums[R];

        }
        return L;
    }
};
