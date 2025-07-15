class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;
        
        bool vowel = false;
        bool con = false;
        
        for(int i=0; i<n; i++){
            
            if(word[i] == '@' || word[i] == '#' || word[i] == '$') return false;
            
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
               vowel = true;
            else if( (word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')) 
               con = true;
        }
                    
        if(vowel == true && con == true) return true;
        return false;    
    }
};