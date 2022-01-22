#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Final Variable to Print the Result
vector<int> res;
// Find the Element to be Deleted
int toDel;
bool changed = false;

// Function that returns the Node to be Deleted
void dfs(vector<vector<int>> adj, vector<int> &vis, vector<int> weight, int s, int v)
{
    vis[s] = 1;
    res.push_back(s);

    if (adj[s].size() == 0 and weight[s] % 2 == 0)
    {
        if (toDel == -1)
            toDel = s;
    }

    for (auto num : adj[s])
    {
        if (vis[num] == 0)
        {
            vis[num] = 1;
            dfs(adj, vis, weight, num, v);
        }
    }
}

// Function that Deletes Nodes unless and until None are left
void dfsOfGraph(int V, vector<vector<int>> &adj, vector<int> weight)
{
    while (1)
    {
        vector<int> vis(V + 1, 0);
        toDel = -1;
        dfs(adj, vis, weight, 1, V);

        if (adj[1].size() == 0)
            break;

        // cout << "To Delete: " << toDel << endl;
        if (toDel != -1)
            changed = true;
        if (changed)
        {
            for (int i = 0; i < V + 1; i++)
            {
                vector<int> store;
                for (auto data : adj[i])
                {
                    if (data != toDel)
                        store.push_back(data);
                }
                adj[i] = store;
            }
            vector<int> temp = {};
            adj[toDel] = temp;
            changed = false;
        }
        else
            break;
    }
}

// Basic DFS Traversal
void dfsPrinter(vector<vector<int>> adj, vector<int> &vis, int s, int v)
{
    vis[s] = 1;
    res.push_back(s);
    for (auto num : adj[s])
    {
        if (vis[num] == 0)
        {
            vis[num] = 1;
            dfsPrinter(adj, vis, num, v);
        }
    }
}

vector<int> dfsPrintUtility(int V, vector<vector<int>> adj)
{
    vector<int> vis(V + 1, 0);
    dfsPrinter(adj, vis, 1, V);
    return res;
}

// Function to Find the Depth of the Tree
int bfsOfGraph(int V, vector<vector<int>> adj)
{
    vector<int> res;
    vector<int> visited(V + 1, 0);

    visited[1] = 1;
    int cnt = 0;

    queue<int> q;
    q.push(1);
    q.push(-1);

    while (!q.empty())
    {
        int frnt = q.front();
        if (frnt != -1)
        {
            res.push_back(frnt);
            q.pop();

            for (auto num : adj[frnt])
            {
                if (visited[num] == 0)
                {
                    q.push(num);
                    visited[num] = 1;
                }
            }
        }
        else
        {
            q.pop();
            cnt++;
            if (q.size() == 0)
                break;
            q.push(-1);
        }
    }

    return cnt;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V;
        E = V;
        vector<int> adj[V + 1];
        vector<int> weight;

        for (int i = 0; i < E - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        weight.push_back(0);
        for (int i = 0; i < E; i++)
        {
            int val;
            cin >> val;
            weight.push_back(val);
        }

        // Print Weights
        // for (auto w : weight)
        // {
        //     cout << w << " ";
        // }
        // cout << endl;

        // Convert an Array of Vectors to an Vector of Vectors
        vector<vector<int>> adm;
        for (int i = 0; i < V + 1; i++)
        {
            auto num = adj[i];
            vector<int> temp;
            for (auto val : num)
                temp.push_back(val);
            adm.push_back(temp);
        }

        // // Print the Adjacent Matrix
        // cout << "==========================" << endl;
        // for (int i = 0; i < V + 1; i++)
        // {
        //     cout << "Node: " << i << " Size: " << adm[i].size() << endl;
        //     cout << "|-> ";
        //     for (auto a : adm[i])
        //     {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "==========================" << endl;

        // Print the DFS of the Graph
        vector<int> ans = dfsPrintUtility(V, adm);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        ans.clear();

        // cout << "++++++++++++++++++++++++++++++" << endl;
        // Do Computations MAIN LOGIC
        res.clear();
        dfsOfGraph(V, adm, weight);
        // cout << "++++++++++++++++++++++++++++++" << endl;

        // // Print the Adjacent Matrix
        // cout << "==========================" << endl;
        // for (int i = 0; i < V + 1; i++)
        // {
        //     cout << "Node: " << i << " Size: " << adm[i].size() << endl;
        //     cout << "|-> ";
        //     for (auto a : adm[i])
        //     {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "==========================" << endl;

        vector<int> finalAns(2, 0);
        // Print the DFS of the Graph after clearing previous Ans
        res.clear();
        if (adm[1].size() != 0)
        {
            ans = dfsPrintUtility(V, adm);
            // Print the DFS
            // for (int i = 0; i < ans.size(); i++)
            // {
            //     cout << ans[i] << " ";
            // }
            // cout << endl;
            // cout << "Number of Nodes: " << ans.size() << endl;
            finalAns[0] = ans.size();
            finalAns[1] = bfsOfGraph(V, adm);
        }
        else
        {
            // What if the Tree is Empty or Just has Root?
            // If there is only an Even Weighted Root
            if (weight[1] % 2 == 0)
            {
                finalAns[0] = 0;
                finalAns[1] = 0;
            }
            // If there is only an Odd Weighted Root
            else
            {
                finalAns[0] = 1;
                finalAns[1] = 1;
            }
        }
        cout << "Number of Nodes: " << finalAns[0] << endl;
        cout << "Depth of Tree: " << finalAns[1] << endl;
    }
    return 0;
}