import java.util.*;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int N=heights.length;
        Stack<Integer> st=new Stack<>();
        int maxArea=0;

        for(int i=0;i<=N;i++) {
            int cur;

            if(i==N) cur=0;
            else cur=heights[i];

            while(!st.isEmpty() && heights[st.peek()]>=cur) {
                int height=heights[st.pop()];

                int left;

                if(st.isEmpty()) left=-1;
                else left=st.peek();

                int width=i-left-1;

                maxArea=Math.max(maxArea,height*width);
            }

            st.push(i);
        }

        return maxArea;
    }
}