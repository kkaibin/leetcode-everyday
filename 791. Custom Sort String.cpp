class Solution {
public:
    string customSortString(string order, string s) {
        //用hashmap存取s裡面出現過的所有字母
        //iterate through order有出現的字母就放進vector
        unordered_map<char, int>map;
        string res;
        for (char c :s) map[c]++;

        for (char c : order){
            while (map[c]>0){
                res+=c;
                map[c]--;
            }
        }

        //iterate through map
        for (auto i :map){
            while (i.second>0){
                res+=i.first;
                i.second--;
            }
        }
        return res;
    }
};
