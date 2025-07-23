class Solution {
    
  
    private int help(String s, int x, int y, String prefer) {
        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();

     
        if (!prefer.equals("ab")) {
            int temp = x;
            x = y;
            y = temp;
        }

        int point = 0;

      
        for (char c : s.toCharArray()) {
            if (!stack1.isEmpty() && stack1.peek() == prefer.charAt(0) && c == prefer.charAt(1)) {
                stack1.pop();  
                point += x;    
            } else {
                stack1.push(c);  
            }
        }

        
        while (!stack1.isEmpty()) {
            if (!stack2.isEmpty() && stack2.peek() == prefer.charAt(0) && stack1.peek() == prefer.charAt(1)) {
                stack1.pop();
                stack2.pop();
                point += y;  
            } else {
                stack2.push(stack1.pop());  
            }
        }

        return point;
    }

    public int maximumGain(String s, int x, int y) {
        String prefer = (x > y) ? "ab" : "ba";
        return help(s, x, y, prefer);
    }
}