class Solution {
    public int maxFrequency(int[] nums, int k, int maxOps) {
        int limit = Arrays.stream(nums).max().getAsInt() + k;
        TreeMap<Integer, Integer> impact = new TreeMap<>();
        Map<Integer, Integer> seen = new HashMap<>();
        
        for (int val : nums) {
            seen.put(val, seen.getOrDefault(val, 0) + 1);
            
            int leftBound = Math.max(0, val - k);
            int rightBound = Math.min(limit, val + k);
            
            impact.put(leftBound, impact.getOrDefault(leftBound, 0) + 1);
            impact.put(rightBound + 1, impact.getOrDefault(rightBound + 1, 0) - 1);
            impact.putIfAbsent(val, 0);
        }
        
        int best = 1;
        int running = 0;
        
        for (Map.Entry<Integer, Integer> entry : impact.entrySet()) {
            int currVal = entry.getKey();
            running += entry.getValue();
            entry.setValue(running);
            
            int existing = seen.getOrDefault(currVal, 0);
            int available = entry.getValue() - existing;
            int canUpgrade = Math.min(available, maxOps);
            
            best = Math.max(best, existing + canUpgrade);
        }
        
        return best;
    }
}