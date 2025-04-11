#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            if (isSymmetric(num)) {
                count++;
            }
        }
        return count;
    }
    
private:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int length = s.length();
        
        // Numbers with odd digits can't be symmetric
        if (length % 2 != 0) {
            return false;
        }
        
        int half = length / 2;
        int firstHalfSum = 0;
        int secondHalfSum = 0;
        
        // Calculate sum of first half digits
        for (int i = 0; i < half; i++) {
            firstHalfSum += s[i] - '0';
        }
        
        // Calculate sum of second half digits
        for (int i = half; i < length; i++) {
            secondHalfSum += s[i] - '0';
        }
        
        return firstHalfSum == secondHalfSum;
    }
};