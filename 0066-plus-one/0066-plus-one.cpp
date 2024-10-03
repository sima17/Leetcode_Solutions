class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int carry=1;
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
int num=digits[i]+carry;
digits[i]=num%10;
carry =num/10;

    }
    if(carry>0){
        digits.push_back(0);
        n=digits.size();
        for(int i=n-1;i>0;i--){
digits[i]=digits[i-1];

        }
        digits[0]=carry;
    }
    return digits;
    }
};