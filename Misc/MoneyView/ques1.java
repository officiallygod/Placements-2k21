import java.util.ArrayList;
import java.util.HashMap;

public class ques1 {
    
    public static void helper(int n, int[] a, int k)
    {
        ArrayList<Integer> arr = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++)
        {
            if(mp.get(a[i]) == 0)
            {
                arr.add(a[i]);
                mp.put(a[i], 2);
            }
        }

        if(arr.size() > k)
        {
            System.out.println(arr.get(k - 1));
        }else
        {
            System.out.println("-1");
        }
    }

    public static void main(String[] args) {
        int a[] = {45623, 1321, 55555, 23123, 1321, 56344, 9999, 11111};
        int a1[] = {12, 11, 12, 12, 16, 11, 290, 114, 12};
        helper(8, a, 5);
        helper(9, a1, 1);
    }
}
