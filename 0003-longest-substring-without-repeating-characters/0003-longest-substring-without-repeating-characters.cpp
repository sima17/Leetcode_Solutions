class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>lastIndex;
        int maxLength=0;
        int start=0;
     for (int end=0;end<s.length();++end){
        char currentChar=s[end];
        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1;
     }
      lastIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
    }
};