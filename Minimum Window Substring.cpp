class Solution {
public:
    string minWindow(string s, string t) {
        //使用兩個pointer來製造window
        //滑動R直到s的end，遇到t裡面有的字母(使用hashmap紀錄t有的字母)，count++
        //一旦count=t長度，達到目標，update minlen、save R, L
        //滑動L，直到count!=t長度

        int R=0, L=0;
        int m=s.length();
        int n=t.length();
        int cnt=0;
        int minlen=INT_MAX;
        string res="";

        //做t的hashmap
        unordered_map<char, int>dict; //數字代表還缺多少個
        for (char c :t) dict[c]++;

        while(R<m){
            if (--dict[s[R]]>=0) cnt++;
            while (cnt==n) {
                if (minlen>R-L+1){
                    minlen=R-L+1;
                    res=s.substr(L, minlen);
                }
                if (++dict[s[L]]>0) cnt--;
                ++L;
            }
            ++R;
        }

        return res;


    }
