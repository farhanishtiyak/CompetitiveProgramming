#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int MAX_LOG = 18;

int nodeDepth[MAX_NODES];
int parent[MAX_NODES][MAX_LOG];
vector<int> graph[MAX_NODES];

void performDepthFirstSearch(int currentNode, int currentParent)
{
    parent[currentNode][0] = currentParent;
    for (int i = 1; i < MAX_LOG; ++i)
    {
        if (parent[currentNode][i - 1] != -1)
            parent[currentNode][i] = parent[parent[currentNode][i - 1]][i - 1];
    }
    for (int neighbor : graph[currentNode])
    {
        if (neighbor != currentParent)
        {
            nodeDepth[neighbor] = nodeDepth[currentNode] + 1;
            performDepthFirstSearch(neighbor, currentNode);
        }
    }
}

int findLowestCommonAncestor(int u, int v)
{
    if (nodeDepth[v] > nodeDepth[u])
        swap(u, v);
    int depthDiff = nodeDepth[u] - nodeDepth[v];
    for (int i = 0; i < MAX_LOG; i++)
    {
        if (depthDiff & (1 << i))
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (parent[v][i] != parent[u][i])
        {
            v = parent[v][i];
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

int findKthAncestor(int node, int k)
{
    for (int i = 0; i < MAX_LOG; ++i)
    {
        if (k & (1 << i))
            node = parent[node][i];
    }
    return node;
}

int calculateMidpoint(int u, int v)
{
    int ancestor = findLowestCommonAncestor(u, v);
    int distance = nodeDepth[u] + nodeDepth[v] - 2 * nodeDepth[ancestor];
    int midDistance = distance / 2;
    if (nodeDepth[u] - nodeDepth[ancestor] >= midDistance)
        return findKthAncestor(u, midDistance);
    else
        return findKthAncestor(v, distance - midDistance);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int numNodes;
        cin >> numNodes;

        for (int i = 1; i <= numNodes; ++i)
        {
            graph[i].clear();
            nodeDepth[i] = 0;
            fill(parent[i], parent[i] + MAX_LOG, -1);
        }

        for (int i = 0; i < numNodes - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        performDepthFirstSearch(1, -1);

        int queries;
        cin >> queries;
        while (queries--)
        {
            int u, v;
            cin >> u >> v;
            cout << calculateMidpoint(u, v) << '\n';
        }
    }

    return 0;
}
