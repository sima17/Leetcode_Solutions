#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution 
{
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int, int> freq;
        int total = 0;

        // Step 1: Count frequency of each answer
        for (int ans : answers) 
        {
            freq[ans]++;
        }

        // Step 2-4: Process each unique answer
        for (auto& [k, count] : freq) 
        {
            int groupSize = k + 1;

            // Step 3: Compute number of groups needed
            int groups = ceil((double)count / groupSize);

            // Step 4: Add total rabbits for these groups
            total += groups * groupSize;
        }

        // Step 5: Return total
        return total;
    }
};