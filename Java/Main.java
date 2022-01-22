import java.util.*;

public class Main {

    private static void testEnergy(int N, int[] energies)
    {
        int i = 0, count = 1;
        boolean flag = true;
        boolean changed = false;
        ArrayList<Integer> ans = new ArrayList<>();

        while(i < N - 1)
        {
            if(energies[i]>energies[i+1])
                ans.add(energies[i]);
            else
                changed = true;
        }

        if(changed == false)
            flag = false;

        while(flag)
        {
            count++;
            i = 0;
            changed = false;

            while(i < ans.size() - 1)
            {
                if(ans.get(i)>ans.get(i+1))
                    ans.add(ans.get(i));
                else
                    changed = true;
            }

            if(changed == false)
                flag = false;
        }
        
        System.out.println(count);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] energies = new int[N];
        for(int i  = 0; i < N; i++)
        {
            energies[i] = sc.nextInt();
        }

        testEnergy(N, energies);
        sc.close();
    }
}