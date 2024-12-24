// Segment Tree for Kth element operations
struct Node { int cnt; Node(int c = 0) : cnt(c) {} };
Node sgtree[400400];
int lc(int i) { return 2 * i; }
int rc(int i) { return 2 * i + 1; }
Node merge(Node a, Node b) { return a.cnt + b.cnt; }

void build(int ind, int l, int r) {
    if (l == r) { sgtree[ind] = Node(0); return; }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid), build(rc(ind), mid + 1, r);
    sgtree[ind] = merge(sgtree[lc(ind)], sgtree[rc(ind)]);
}

void update(int t_id, int l, int r, int val, int insert) {
    if (l == r) { sgtree[t_id] = Node(insert); return; }
    int mid = (l + r) >> 1;
    val <= mid ? update(lc(t_id), l, mid, val, insert)
               : update(rc(t_id), mid + 1, r, val, insert);
    sgtree[t_id] = merge(sgtree[lc(t_id)], sgtree[rc(t_id)]);
}

void query(int ind, int l, int r, int k) {
    if (l == r) { cout << l << endl; return; }
    int mid = (l + r) >> 1;
    sgtree[lc(ind)].cnt >= k ? query(lc(ind), l, mid, k)
                             : query(rc(ind), mid + 1, r, k - sgtree[lc(ind)].cnt);
}

void segTreeSolution() {
    int n, q; cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        int type, x, k;
        cin >> type;
        if (type == 1) cin >> x, update(1, 1, n, x, 1);
        else if (type == 2) cin >> x, update(1, 1, n, x, 0);
        else cin >> k, query(1, 1, n, k);
    }
}

// Fenwick Tree
struct FenwickTree {
    vi fn; int n;
    void init(int n_) { n = n_ + 1; fn.assign(n, 0); }
    void update(int idx, int inc) {
        for (++idx; idx < n; idx += idx & -idx) fn[idx] += inc;
    }
    int query(int idx) {
        int ans = 0;
        for (++idx; idx; idx -= idx & -idx) ans += fn[idx];
        return ans;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

// Convex Hull
struct Point {
    int x, y;
    bool operator<(Point p) const { return x == p.x ? y < p.y : x < p.x; }
    bool operator==(Point p) const { return x == p.x && y == p.y; }
};
bool cw(Point a, Point b, Point c) { return (a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) > 0; }
bool ccw(Point a, Point b, Point c) { return (a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) < 0; }

vector<Point> convexHull(vector<Point>& points) {
    if (points.size() <= 2) return points;
    sort(all(points));
    vector<Point> up, down;
    Point first = points[0], last = points.back();
    for (auto& p : points) {
        while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p)) up.pop_back();
        while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], p)) down.pop_back();
        up.pb(p), down.pb(p);
    }
    vector<Point> result = up;
    result.insert(result.end(), ++down.rbegin(), --down.rend());
    sort(all(result)), result.erase(unique(all(result)), result.end());
    return result;
}



// Graph
struct Graph {
    int n, tme = 1, comp_till_now = 0;
    bool cycle = false, DAG = false;
    vector<vector<int>> gr, levels;
    vector<int> visited, parent, component, topo_order, discovery_time, lowest_time;
    vector<pair<int, int>> bridges;
    set<int> arti_points;
    Graph(int _n) : n(_n) {
        gr.resize(n + 1);
        visited.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        component.resize(n + 1, 0);
        discovery_time.resize(n + 1, 0);
        lowest_time.resize(n + 1, 0);
    }
    void addEdge(int x, int y, int undirected = 1) {
        gr[x].emplace_back(y);
        if (undirected) gr[y].emplace_back(x);
    }
    void dfs_helper(int from, int par) {
        visited[from] = 1;
        parent[from] = par;
        component[from] = comp_till_now;
        discovery_time[from] = lowest_time[from] = tme++;
        int child = 0;
        for (auto to : gr[from]) {
            if (!visited[to]) {
                child++;
                dfs_helper(to, from);
                lowest_time[from] = min(lowest_time[from], lowest_time[to]);
                if (lowest_time[to] > discovery_time[from]) bridges.push_back({from, to});
                if (par && lowest_time[to] >= discovery_time[from]) arti_points.insert(from);
            } else if (to != par && visited[to] == 1) {
                cycle = true;
                lowest_time[from] = min(lowest_time[from], discovery_time[to]);
            }
        }
        visited[from] = 2;
        if (DAG) topo_order.push_back(from);
        if (par == 0 && child > 1) arti_points.insert(from);
    }
    void dfs() {
        fill(visited.begin(), visited.end(), 0);
        comp_till_now = 0;
        tme = 1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs_helper(i, 0);
                comp_till_now++;
            }
        }
    }
    void bfs() {
        fill(visited.begin(), visited.end(), 0);
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()) {
            int sz = Q.size();
            vector<int> cur_level;
            for (int i = 0; i < sz; i++) {
                int from = Q.front();
                Q.pop();
                visited[from] = 1;
                cur_level.push_back(from);
                for (auto to : gr[from]) {
                    if (!visited[to]) {
                        Q.push(to);
                        visited[to] = 1;
                    }
                }
            }
            levels.push_back(cur_level);
        }
    }
    void path_construction(int from, int to) {
        if (!parent[to]) {
            cout << "NO PATH! ROOT NODE." << endl;
            return;
        }
        if (component[from] != component[to]) {
            cout << "NO PATH! DIFFERENT COMPONENT.";
            return;
        }
        while (to != from) {
            cout << to << " ";
            to = parent[to];
        }
        cout << to << endl;
    }
    void topological_order() {
        topo_order.clear();
        DAG = true;
        dfs();
        reverse(topo_order.begin(), topo_order.end());
    }
};

// LCA
const int N = 1e5, M = 20;
vector<int> gr[N];
int dep[N], Par[N][M];

void dfs(int cur, int par) {
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j = 1; j < M; j++) Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    for (auto x : gr[cur]) {
        if (x != par) dfs(x, cur);
    }
}

int LCA(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = M - 1; j >= 0; j--) {
        if ((diff >> j) & 1) u = Par[u][j];
    }
    for (int j = M - 1; j >= 0; j--) {
        if (Par[u][j] != Par[v][j]) {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}

int LengthFromUtoV(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}


// Disjoint Set Union (DSU)
class dsu {
public:
    vector<int> parent, size, rank, mx, mn;
    dsu(int n) {
        for (int i = 0; i <= n; i++) {
            size.push_back(1);
            parent.push_back(i);
            rank.push_back(0);
            mx.push_back(i);
            mn.push_back(i);
        }
    }
    int find(int node) {
        return parent[node] = (parent[node] == node) ? node : find(parent[node]);
    }
    void unionsize(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            mx[pv] = max(mx[pv], mx[pu]);
            mn[pv] = min(mn[pv], mn[pu]);
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            mx[pu] = max(mx[pu], mx[pv]);
            mn[pu] = min(mn[pu], mn[pv]);
        }
    }
    void unionrank(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] == rank[pv]) {
            parent[pu] = pv;
            rank[pu]++;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
    }
};
// Longest Increasing Subsequence (LIS) using Binary Search
int Lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        int length = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (dp[length - 1] < arr[i] && arr[i] < dp[length]) dp[length] = arr[i];
    }
    return max_element(dp.begin(), dp.end()) - dp.begin();
}
// Coordinate Compression
map<int, int> mp, back;
void coordinate_compression(vector<int>& original, vector<int>& duplicate) {
    int index = 0;
    for (int i = 0; i < duplicate.size(); i++) {
        if (!mp[duplicate[i]]) {
            mp[duplicate[i]] = index;
            back[index] = duplicate[i];
            index++;
        }
    }
    for (int i = 0; i < original.size(); i++) {
        original[i] = mp[original[i]];
    }
}

// Longest Common Subsequence (LCS)
const int N = 3000;
string s, t, res;
int n, m, memo[N][N];
int give_lcs(int i, int j) {
    if (i == n || j == m) return 0;
    int& ans = memo[i][j];
    if (ans != -1) return ans;
    if (s[i] == t[j]) ans = give_lcs(i + 1, j + 1) + 1;
    else ans = max(give_lcs(i + 1, j), give_lcs(i, j + 1));
    return ans;
}
void trace_back(int i, int j) {
    if (i == n || j == m) return;
    if (s[i] == t[j]) {
        res += s[i];
        trace_back(i + 1, j + 1);
    } else {
        if (give_lcs(i + 1, j) == give_lcs(i, j)) trace_back(i + 1, j);
        else trace_back(i, j + 1);
    }
}
// Longest Directed Path in Graph
const int N = 1e5 + 1;
vector<int> gr[N];
int memo[N];
int dp(int cur) {
    int& ans = memo[cur];
    if (ans != -1) return ans;
    ans = 0;
    for (auto x : gr[cur]) {
        ans = max(ans, dp(x) + 1);
    }
    return ans;
}
// Knapsack Problem 1
const int N = 100;
int v[N], w[N], W, n, memo[N][100001];
int knapsack(int index, int weight) {
    if (index >= n) return 0;
    int& ans = memo[index][weight];
    if (ans != -1) return ans;
    ans = knapsack(index + 1, weight);
    if (w[index] + weight <= W) {
        ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));
    }
    return ans;
}
// Knapsack Problem 2
const int N = 101;
int v[N], w[N], W, n, mW[N][100001], dp[N][100001];
void knapsack_2() {
    for (int i = 1; i <= n; i++) {
        for (int val = 0; val < 100001; val++) {
            mW[i][val] = 1e13;
            if (dp[i - 1][val]) {
                dp[i][val] = 1;
                mW[i][val] = min(mW[i][val], mW[i - 1][val]);
            }
            if (val - v[i] >= 0 && dp[i - 1][val - v[i]] && mW[i - 1][val - v[i]] + w[i] <= W) {
                dp[i][val] = 1;
                mW[i][val] = min(mW[i][val], mW[i - 1][val - v[i]] + w[i]);
            }
        }
    }
}
