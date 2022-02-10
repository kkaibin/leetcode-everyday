class Solution {
public:

//樹的遞迴：每次看到node的時候，判斷該node，再往下看left, right
//每次要判斷什麼：
//max path是leftpathsum+1 or rightpathsum+1 or leftpathsum+rightpathsum
//return max(rightpathsum+1, rightpathsum+1)

    int maxPathSum(TreeNode* root) {

        //initialization
        int maxp=INT_MIN;
        int sum = helper(root, maxp);

        return maxp;
    }

    int helper(TreeNode* t, int &maxp){
        //base case
        if (!t) return 0;

        //該node左右兩邊的path sum
        int left=max(helper(t->left, maxp),0);
        int right=max(helper(t->right, maxp),0);

        //該node至今的path sum
        int curpath=max(left+t->val, right+t->val);

        maxp=max(maxp, left+right+t->val);

        return curpath;


    }

};
