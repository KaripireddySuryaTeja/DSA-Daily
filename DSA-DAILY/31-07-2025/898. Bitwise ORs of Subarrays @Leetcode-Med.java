import java.util.*;
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> res=new HashSet<>();
        Set<Integer> curr=new HashSet<>();
        for(int i:arr){
            Set<Integer> temp=new HashSet<>();
            temp.add(i);
            for(int j:curr){
                temp.add(i|j);
            }
            res.addAll(temp);
            curr=temp;
        }
        return res.size();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an array of numbers separated by spaces: ");
        String input = scanner.nextLine();
        int[] arr = Arrays.stream(input.split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
        Solution solution = new Solution();
        int result = solution.subarrayBitwiseORs(arr);
        System.out.println("Number of distinct bitwise ORs: " + result);
    }
}