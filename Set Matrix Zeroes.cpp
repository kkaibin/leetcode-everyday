class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        //遍歷
        //找到0的話，把該行、該列作記號
        //遍歷完後，將有記號的全部變成0

        int rowzero=1;
        int m=matrix.size();//row 數
        int n=matrix[0].size(); // col 數

        for (int row=0; row<m; row++){
            for (int col=0;col<n;col++){
                if (matrix[row][col]==0){
                    matrix[0][col]=0;
                    if (row==0) rowzero=0;
                    else matrix[row][0]=0;
                }
            }
        }
        //update順序很重要

        //略過row 0不update
        for(int row=1; row<m;row++){
            if (matrix[row][0]==0){
                for (int i=1; i<n; i++){
                    matrix[row][i]=0;
                }
            }
        }
        for(int col=0; col<n;col++){
            if (matrix[0][col]==0){
                for (int i=1; i<m; i++){
                    matrix[i][col]=0;
                }
            }
        }

        //update row 0
        if (rowzero==0){
            for (int i=0; i<n; i++){
                matrix[0][i]=0;
            }
        }
    }
};
