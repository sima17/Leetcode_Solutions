import java.util.*;

class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        if (n <= 1) {
            return 0;
        }

        Arrays.sort(points, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);  // sort by x ascending
            }
            return Integer.compare(b[1], a[1]);      // if x equal, sort by y descending
        });

        int count = 0;
        for (int i = 0; i < n; i++) {
            int maxY = Integer.MIN_VALUE;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > maxY) {
                        count++;
                    }
                    maxY = Math.max(maxY, points[j][1]);
                }
            }
        }
        return count;
    }
}