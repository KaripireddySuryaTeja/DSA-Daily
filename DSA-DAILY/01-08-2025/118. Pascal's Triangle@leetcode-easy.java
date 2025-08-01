import java.util.*;
class Solution {
    public List<List<Integer>> generate(int num) {
        List<List<Integer>> dp = new ArrayList<>();

        dp.add(new ArrayList<>());
        dp.get(0).add(1);
        for(int i=1;i<num;i++){
            List<Integer> curr = new ArrayList<>();
            List<Integer> prev=dp.get(i-1);
            curr.add(1);
            for(int j=1;j<i;j++){
                int k=prev.get(j-1)+prev.get(j);
                curr.add(k);
            }
            curr.add(1);
            dp.add(curr);
        }
        return dp;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        Scanner scanner = new Scanner(System.in);
        int n;
        n=scanner.nextInt();
        List<List<Integer>> result = sol.generate(n);
        for (List<Integer> row : result) {
            System.out.println(row);
        }
    }
}