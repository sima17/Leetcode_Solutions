#include <iostream>
class Solution {
public:
    int coloredCells(int n) {
        return 1 + 4 * ((n - 1) * n / 2);
    }
};