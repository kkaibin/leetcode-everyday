class Solution {
public:
    string longestPalindrome(string s) {

        int maxlen=0;
        int start=0;

        //edge cases
        if (s.size() < 2 ) return s;


        for(int i=0; i<=s.size(); ++i){
        //odd numbers:iterate as centers
        //expand two pointers to see if i-1=i+1
        searchPalindrome(s, i, i, maxlen, start);

        //even numbers:iterate i && i+1 as centers
        //expand two pointers to see if i-1=i+1
        searchPalindrome(s, i, i+1, maxlen, start);

        }

        return s.substr(start, maxlen);
    }

     void searchPalindrome(string s, int left, int right, int& maxlen, int& start){
            while(left>=0 && right <=s.size()-1 && s[left]==s[right]){
                //save results
                if (maxlen<right-left+1){
                    maxlen=right-left+1;
                    start=left;
                }
                --left;
                ++right;
            }
        }

};
