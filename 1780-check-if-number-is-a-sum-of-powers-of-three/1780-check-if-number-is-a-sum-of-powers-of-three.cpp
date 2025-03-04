class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3!=0) {
                n = n - 1;
            }

            if(n%3 != 0) return false;

            n/=3;
        }
        return true;
    }
};