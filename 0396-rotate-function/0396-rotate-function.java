class Solution {
    public int maxRotateFunction(int[] nums) {
        int N=nums.length;
        long fnval=0,sum=0;
        for(int i=0; i<N; i++)
        {
            fnval+=(i*nums[i]);
            sum+=nums[i];
        }
        long ans=fnval;
        for(int li=N-1; li>0; li--)
        {
            fnval=fnval=fnval-(nums[li]*(N-1))+sum-nums[li];
            ans=Math.max(fnval,ans);    
        }
        return (int)ans;
    }
}