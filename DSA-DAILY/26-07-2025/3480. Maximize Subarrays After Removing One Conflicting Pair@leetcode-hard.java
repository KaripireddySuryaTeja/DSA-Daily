import java.util.*;
class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        List<Integer>[] r=new ArrayList[n+1];
        for(int i=0;i<=n;i++){
            r[i]=new ArrayList<>();
        }
        for(int[] p:conflictingPairs){
            r[Math.max(p[0],p[1])].add(Math.min(p[0],p[1]));
        }

        long res=0;
        long[] l={0,0};
        long[] b=new long[n+1];

        for(int ri=1;ri<=n;ri++){
            for(int lv:r[ri]){
                if(lv>l[0]){
                    l[1]=l[0];
                    l[0]=lv;
                }else if(lv>l[1]){
                    l[1]=lv;
                }
            }
            res+=ri-l[0];
            if(l[0]>0)b[(int)l[0]]+=l[0]-l[1];
        }
        long bon=0;
        for(long bo:b){
            bon=Math.max(bon,bo);
        }
        return res+bon;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // Example input
        int n = 5; // Number of elements
        int[][] conflictingPairs = {{1, 2}, {2, 5}, {3, 5}};
        long result = sol.maxSubarrays(n, conflictingPairs);
        System.out.println("Maximum Subarrays After Removing One Conflicting Pair: " + result);
    }
}
