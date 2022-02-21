class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort the arrays by the starting point
        //iterate through intervals, check covered or not
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());

        int pre_end = intervals[0][1];
        int pre_begin = intervals[0][0];

        for (int i=1; i<intervals.size(); i++){
            //covered 1, pre covered i, delete i
            if (pre_end>=intervals[i][1]){
                n--;
            }
            //covered 2, i covered pre, delete pre
            else if(pre_begin==intervals[i][0]){
                n--;
                pre_end=intervals[i][1];
            }
            //uncovered, update pre
            else {
                pre_end=intervals[i][1];
                pre_begin=intervals[i][0];
            }

        }
        return n;


    }
};
