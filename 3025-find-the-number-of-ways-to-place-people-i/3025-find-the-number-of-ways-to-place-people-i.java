public class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;

        Arrays.sort(points, (a, b) -> (a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]));

        int count = 0;

        for (int i = 0; i < n; i++) {
            TreeSet<Integer> ySeen = new TreeSet<>();
            int[] p1 = points[i];

            for (int j = i + 1; j < n; j++) {
                int[] p2 = points[j];
                if (p1[0] <= p2[0] && p1[1] >= p2[1]) {
                    Integer yInRange = ySeen.ceiling(p2[1]); 
                    if (yInRange == null || yInRange > p1[1]) {
                        count++; 
                    }
                }
                ySeen.add(p2[1]);
            }
        }
        return count;
    }
}