class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int>mp;
        int i=0;
        while(i<word.size()){
            int count=1;
            bool is_consecutive=false;
            while(i+1<word.size() && word[i+1]==word[i]){
                is_consecutive=true;
                count++;
                i++;
            }
            if(is_consecutive){
                mp[i]=count;
            }
            i++;

        }
        int ans=0;
        for(auto &it:mp){
            ans+=(it.second-1);
        }
        return ans+1;
        
    }
};