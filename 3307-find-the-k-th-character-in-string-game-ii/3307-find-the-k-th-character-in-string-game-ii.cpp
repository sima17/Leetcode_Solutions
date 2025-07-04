class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1){
            return 'a';
        }
        int n = operations.size();
        long long length = 1;
        long long newk = -1;
        int operationtype = -1;
        for(int i = 0 ; i  < n ; i++){
            length *= 2;
            if(length >= k){
                operationtype = operations[i];
                newk = k - length/2;
                break;
            }
        }
        char ch  = kthCharacter(newk, operations);

        if(operationtype == 0)
         return ch;
        
        return ch == 'z' ? 'a' : ch+1 ;
    }
};