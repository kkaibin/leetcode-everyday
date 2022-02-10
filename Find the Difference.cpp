class Solution {
public:
    char findTheDifference(string s, string t) {
        //use a hashmap
        //iterate through s, then iterate through t
        unordered_map<char, int>dict;
        for(char c :s) ++dict[c];
        for(char c :t) {
            if(--dict[c]<0) return c;
        }
        return -1;
    }
};
