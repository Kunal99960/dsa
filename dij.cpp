#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;
int dij(int source, int n, vector<pair<int, int> > graph[])
{
    vector<int> dist(500, inf);
    vector<int> visited(500, 0);
    set<pair<int, int> > s;
    s.insert(make_pair(0,source));
    dist[source] = 0;
    while (s.size() > 0)
    {
        auto top = *s.begin();
        int v = top.second;
        int wt = top.first;
        s.erase(s.begin());
        if (visited[v])
            continue;
        visited[v] = 1;
        for (auto child : graph[v])
        {
            int v_c = child.first;
            int wt_c = child.second;
            if (wt + wt_c < dist[v_c])
            {
                dist[v_c] = wt + wt_c;
                s.insert(make_pair(dist[v_c], v_c));
            }
        }
    }
    int ans = 0;
    for (int i = i; i <= n; i++)
    {
        if (dist[i] == inf)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
int networkDelayTime(vector<int> times[], int n, int k)
{
    vector<pair<int, int> > g[500];
    for (auto v : times)
    {
        int a = v[0], b = v[1], c = v[2];
        g[a].push_back(make_pair(b,c));
    }
    return dij(k, n, g);
}
int main()
{
    vector<int> times[3];
    times[0]={2,1,1};
    times[1]={2,3,1};
    times[2]={3,4,1};
    cout << networkDelayTime(times, 4, 2);
}
