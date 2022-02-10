class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        int k=0;

        //每次縮減k邊長，只要n-2*k>1，k++
        while (n-2*k+1>1){
            //原本起訖點：0, n；新的起訖點：0+k, n-k
            for (int i=k;i<n-k;i++){ //i的條件很重要
                int temp = matrix[k][i];
                matrix[k][i]=matrix[n-i][k];
                matrix[n-i][k]=matrix[n-k][n-i];
                matrix[n-k][n-i]=matrix[i][n-k];
                matrix[i][n-k]=temp;
            }

            k++;
        }
    }
};
