class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxarea=0;
        int distance=height.size()-1;

        //move the pointers until they meet
        while(left<=right){
            int area=min(height[left],height[right])*distance;
            maxarea=max(maxarea,area);
            if(height[left]<=height[right]){
                left++;
            }
            else right--;
            distance--;
        }
        return maxarea;
    }
};
