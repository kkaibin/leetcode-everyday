class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end()); //記得sort的方法
        //iterate
        int n=intervals.size();
        for (int i=0; i<n-1; i++){
            //判斷有沒有overlap
            //if      i1 end < i2 start >>no
            //else if i2 end < i1 start >>no
            //else >> yes
            if (intervals[i][1]<intervals[i+1][0]) res.push_back(intervals[i]);

            //merge the overlapped
            //[start, end]=[min(i1 i2 start), max(i1 i2 end)]
            else {

                intervals[i+1][0]=min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1]=max(intervals[i][1], intervals[i+1][1]);
            }
        }
        res.push_back(intervals[n-1]);
        return res;


    }
};
