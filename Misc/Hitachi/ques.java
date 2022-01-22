public class ques {
        public static void main(String[] args) {
        int k=2, n=4;
        int[][] nums = {{0, 1, 15, 6},
                        {2, 0, 7, 3},
                        {9, 6, 0, 12},
                        {10, 4, 8, 0}};
        System.out.println(getMinDistance(nums, k, n));
    }

    static int res = Integer.MAX_VALUE;
    private static int getMinDistance(int[][] nums, int k, int n) {
        boolean[] visited = new boolean[n];
        visited[0] = true;
        dfs(nums, visited, k, 0, 0);
        return res;
    }

    private static void dfs(int[][] nums, boolean[] visited, int k, int cur, int tmp) {
        if(isAllVisited(visited)) {
            tmp += nums[cur][k-1] + nums[k-1][0];
            res = Math.min(res, tmp);
        }
        for(int i=0;i<visited.length;i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(nums, visited, k, i, tmp + nums[cur][i]);
                visited[i] = false;
            }
        }
    }

    static boolean isAllVisited(boolean[] visited) {
        for(boolean v : visited)
            if(!v)
                return false;
        return true;
    }
}