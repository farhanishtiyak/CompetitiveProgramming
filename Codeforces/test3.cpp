// Bit Manipulation
int getIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
void setIthBit(int &n, int i)
{
    int mask = (1 << i);
    n |= mask;
}
void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n &= mask;
}
void updateIthBit(int &n, int i, int v)
{
    clearIthBit(n, i);
    int mask = (v << i);
    n |= mask;
}
void clearLast_i_Bit(int n, int i)
{
    int mask = (-1 << i);
    n &= mask;
}
void clearBitsInRange(int &n, int i, int j)
{
    int a = (-1 << i);
    b = (1 << i) - 1;
    n &= (a | b);
}
void replaceBits(int &n, int i, int j, int m)
{
    clearBitsInRange(n, i, j);
    n |= (m << i);
}
bool powerOfTwo(int n)
{
    if (n & (n - 1) == 0)
        return 1;
    else
        return 0;
}
int countNoOfSetBits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n &= (n - 1);
        ans++;
    }
    return ans;
}

// Exponentiation
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mod_sub(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b) % mod) + mod) % mod;
}
ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll fast_mul(ll a, ll b, ll c)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
        {
            res += a;
            res %= c;
        }
        a += a;
        a %= c;
        b >>= 1;
    }
    return res;
}

// Inversion Count
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;
int count_inversion()
{
    int ans = 0;
    pbds St;
    for (int i = 0; i < n; i++)
    {
        ans += (i - St.order_of_key(a[i]));
        St.insert(a[i]);
    }
    return ans;
}

// Math
// Seive
const int N = 1e7 + 9;
int spf[N]; // Smallest Prime Factor
vector<int> primes;
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
            spf[i] = i, primes.push_back(i);
        int sz = primes.size();
        for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++)
        {
            spf[i * primes[j]] = primes[j];
        }
    }
}

// String Algo's
// String Hashing
const int p = 31, mod = 1e9 + 7;
int poly_hash(string s)
{
    int hash = 0;
    int p_power = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= p;
        hash %= mod;
        p_power %= mod;
    }
    return hash;
}
int powr(int a, int b) { ... }
int inv(int x) { return powr(x, mod - 2); }
int32_t main()
{
    string text = "ababbabbaba";
    string pattern = "aba";
    int pat_hash = poly_hash(pattern);
    int n = text.size(), m = pattern.size();
    int text_hash = poly_hash(text.substr(0, m));
    if (pat_hash == text_hash)
    {
        cout << 0 << '\n';
    }
    for (int i = 1; i + m <= n; i++)
    {
        // remove last character
        text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
        text_hash = (text_hash * inv(p)) % mod;
        text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;
        if (text_hash == pat_hash)
        {
            cout << i << '\n';
        }
    }
}

// KMP
vector<int> compute_lps_better(string s)
{
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 and s[i] != s[j])
        {
            j = lps[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

vector<int> kmp(string text, string pattern)
{
    int n = text.size(), m = pattern.size();
    vector<int> lps = compute_lps_better(pattern);
    vector<int> occurences;
    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            (j == 0) ? i++ : j = lps[j - 1];
        }
        if (j == m)
        { // Occurences found
            occurences.push_back(i - m);
            j = lps[j - 1];
        }
    }
    return occurences;
}

vector<int> string_matching(string text, string pattern)
{
    string good = pattern + "&" + text;
    vector<int> lps = compute_lps_better(good);
    vector<int> occurences;
    for (int i = pattern.size() + 1; i < good.size(); i++)
    {
        if (lps[i] == pattern.size())
        { // Occurences found
            // int index = (i - pattern.size() + 1) - (pattern.size() + 1);
            int index = i - (2 * pattern.size());
            occurences.push_back(index);
        }
    }
    return occurences;
}

void solution()
{
    string s, t;
    cin >> s >> t;
    vi occurences = kmp(s, t);
    output(occurences);
}

// Z-Algorithm
vector<int> z_best(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= R)
        {
            z[i] = min(z[i - L], R - i + 1);
        }
        while (i + z[i] < n and s[z[i]] == s[z[i] + i])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > R)
        {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

// Find All the occurences of a string
vector<int> match_string(string text, string pattern)
{
    string good = pattern + "$" + text;
    vector<int> z = z_best(good);
    vector<int> occurences;
    for (int i = pattern.size() + 1; i < good.size(); i++)
    {
        if (z[i] == pattern.size())
        {
            occurences.pb(i - (pattern.size() + 1));
        }
    }
    return occurences;
}

// Longest Palindromic Prefix
int longest_palindromic_prefix(string s)
{
    int n = s.size();
    string good = s + "%";
    reverse(s.begin(), s.end());
    good += s;

    vector<int> z = z_best(good);

    cout << good << endl;
    int ans = INT_MIN;
    for (int i = 0; i < good.size(); i++)
    {
        if (i + z[i] == good.size())
        {
            ans = max(ans, z[i]);
        }
    }
    return ans;
}

void solution()
{
    string s;
    cin >> s;
    string t;
    cin >> t;

    int ans = longest_palindromic_prefix(s);
    output(ans);
}
// Manacher's Algorithm O(n)  // Longest Palindromic Substring O(n)
string transform(string &s)
{
    string temp = "#";
    for (auto ch : s)
    {
        temp += ch;
        temp += '#';
    }
    return temp;
}

string manachers_algo(string &s)
{
    string t = transform(s);
    int n = t.size(), mxLen = 0, centre; // centre-> mid point of lps
    int l = 0;                           // to track the left boundary of the right most plaindrome
    int r = 0;                           // to track the left boundary of the right most plaindrome
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int k;
        if (i > r)
        {
            k = 0;
        }
        else
        {
            int j = l + (r - i);
            if (j - p[j] > l)
            {
                p[i] = p[j];
                continue;
            }
            else
            {
                k = r - i;
            }
        }
        while (i - k >= 0 and i + k < n and t[i - k] == t[i + k])
        {
            k++;
        }
        k--;
        p[i] = k;
        if (p[i] > mxLen)
        {
            mxLen = p[i];
            centre = i / 2;
        }
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return s.substr(centre - (mxLen / 2), mxLen);
}

// Segment Tree

// summation
struct segmenttree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r)
        {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};

// Lazy Propagation
// Max Value - lazy propagation
struct segmenttreelazy
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    void build(int start, int ending, int node, vector<int> &v)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + ending) / 2;
        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);
        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return INT_MIN;
        }
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            st[node] = max(st[node], lazy[node]);
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] = max(lazy[node], lazy[2 * node + 1]);
                lazy[2 * node + 2] = max(lazy[node], lazy[2 * node + 2]);
            }
            lazy[node] = 0;
        }
        // complete overlap
        if (start >= l && ending <= r)
        {
            return st[node];
        }
        // partial case
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        return max(q1, q2);
    }
    void update(int start, int ending, int node, int l, int r, int value)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return;
        }
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0)
        {
            // pending updates
            // update the segment tree node
            st[node] = max(st[node], lazy[node]);
            if (start != ending)
            {
                // propagate the updated value
                lazy[2 * node + 1] = max(lazy[node], lazy[2 * node + 1]);
                lazy[2 * node + 2] = max(lazy[node], lazy[2 * node + 2]);
            }
            lazy[node] = 0;
        }
        // complete overlap
        if (start >= l && ending <= r)
        {
            st[node] = max(st[node], value);
            if (start != ending)
            {
                lazy[2 * node + 1] = max(value, lazy[2 * node + 1]);
                lazy[2 * node + 2] = max(value, lazy[2 * node + 2]);
            }
            return;
        }
        // partial case
        int mid = (start + ending) / 2;
        update(start, mid, 2 * node + 1, l, r, value);
        update(mid + 1, ending, 2 * node + 2, l, r, value);
        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

// Euler Tour  (subtree Queries)
const int N = 2e5 + 10;
vector<int> gr[N];
vector<int> tin(N), tout(N);
int timer;

void tour3(int node, int parent)
{
    // cout << node << " ";
    tin[node] = ++timer; // 1 based (initally timer = 1)
    for (auto child : gr[node])
    {
        if (child != parent)
        {
            tour3(child, node);
        }
    }
    tout[node] = timer;
    // cout << node << " ";
}

void solution()
{
    int n;
    cin >> n;
    vi val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    // input Graph
    timer = 0;
    tour3(1, 0);
    // build array for segment tree
    vi arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        arr[tin[i]] = val[i];
    }
    segmenttree tree;
    tree.init(n + 1);
    tree.build(arr);
    int ans = tree.query(tin[1], tout[1]); // summation of subtree
    output(ans);
}

// Kth element in a segment tree
// Problem     : Given a set of N(1e5) dictinct integers
// operation 1 : insert x in the set
// operation 2 : remove x from the set
// operation 3 : what is the kth element present in the set

int lc(int i) {return 2 * i;}
int rc(int i) {return 2 * i + 1;}
struct node {
    int cnt; // Number of value present in the associated range
    node(int c = 0): cnt(c) {
    }
};
node sgtree[400400];
node merge(node a, node b) {
    return a.cnt + b.cnt;
}
void build(int ind, int l, int r) {
    if (l == r) {
        sgtree[ind] = node(0);
        return;
    }

    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    sgtree[ind] = merge(sgtree[lc(ind)], sgtree[rc(ind)]);
}

void update(int t_id, int l, int r, int val, int insert) {
    if (l == r) {
        if (insert) {sgtree[t_id] = node(1);}
        else {sgtree[t_id] = node(0);}
        return;
    }

    int mid = (l + r) >> 1;
    if (val <= mid) {
        update(lc(t_id), l, mid, val, insert);
    } else {
        update(rc(t_id), mid + 1, r, val, insert);
    }

    sgtree[t_id] = merge(sgtree[lc(t_id)], sgtree[rc(t_id)]);
}

void query(int ind, int l, int r, int k) {
    if (l == r) {
        cout << l << endl;
        return;
    }

    int mid = (l + r) / 2;
    if (sgtree[lc(ind)].cnt >= k) {
        query(lc(ind), l, mid, k);
    } else {
        query(rc(ind), mid + 1, r, k - sgtree[lc(ind)].cnt);
    }
    return;
}

void solution()
{
    int n;
    cin >> n;
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // insert x
            int x;
            cin >> x;
            update(1, 1, n, x, 1);
        } else if (type == 2) { // delete x
            int x;
            cin >> x;
            update(1, 1, n, x, 0);
        } else { // find kth elemnt
            int k;
            cin >> k;
            query(1, 1, n, k);
        }
    }
}

// Fenwick Tree
struct fenwick
{
    vector<int> fn;
    int n;

    void init(int n)
    {
        this->n = n + 1;
        fn.resize(this->n, 0);
    }
    void update(int idx, int increment)
    {
        idx++; // 1 based index
        while (idx < n)
        {
            fn[idx] += increment;
            idx += (idx & (-idx));
        }
    }
    int query(int idx)
    {
        idx++; // 1 based index
        int ans = 0;
        while (idx)
        {
            ans += fn[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
    // summation
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

// Convex Hull
struct Point
{
    int x, y;
    bool operator<(Point P) const
    {
        if (x == P.x)
            return y < P.y;
        else
            return x < P.x;
    }
    bool operator==(Point P) const { return (x == P.x && y == P.y); }
};
bool cw(Point a, Point b, Point c)
{
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}
bool ccw(Point a, Point b, Point c)
{
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}
bool cll(Point a, Point b, Point c)
{
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}
vector<Point> convex_hull(vector<Point> points)
{
    if (points.size() <= 2)
        return points;
    sort(points.begin(), points.end());
    vector<Point> up, down;
    Point first = points[0], last = points.back();
    up.push_back(first);
    down.push_back(first);
    for (int i = 1; i < points.size(); i++)
    {
        if (i == points.size() - 1 || cw(first, points[i], last))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i]))
            {
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if (i == points.size() - 1 || ccw(first, points[i], last))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2],
                                            down[down.size() - 1], points[i]))
            {
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }
    points.clear();
    for (int i = 0; i < up.size(); i++)
    {
        points.push_back(up[i]);
    }
    for (int i = 0; i < up.size(); i++)
    {
        points.push_back(down[i]);
    }
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    return points;
}
int main()
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    vector<Point> convex_hull_vector = convex_hull(points);
}

// Graph
// Unweighted Graph
struct Graph
{
    int n, tme = 1;
    bool cycle = false;
    bool DAG = false;
    vector<vector<int>> gr, levels;
    vector<int> visited, parent, component, topo_order;
    vector<int> discovery_time, lowest_time;
    vector<pair<int, int>> bridges;
    set<int> arti_points;
    Graph(int _n) : n(_n)
    {
        gr.resize(n + 1);
        visited.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        component.resize(n + 1, 0);
        discovery_time.resize(n + 1, 0);
        lowest_time.resize(n + 1, 0);
    }
    void addEdge(int x, int y, int undirected = 1)
    {
        gr[x].emplace_back(y); // {node , weight}
        if (undirected)
        {
            gr[y].emplace_back(x); // {node , weight}
        }
    }
    void cycle_print(int u, int v)
    {
        while (u != v)
        {
            cout << u << " ";
            u = parent[u];
        }
        cout << u << endl;
        // exit(0); // terminates the program
    }
    int comp_till_now = 0;
    void dfs_helper(int from, int par)
    {
        // cout<<from<<" ";
        visited[from] = 1; // visited and in the call stack
        parent[from] = par;
        component[from] = comp_till_now;
        discovery_time[from] = lowest_time[from] = tme++;
        int child = 0;
        for (auto to : gr[from])
        {
            if (visited[to] == 0)
            {
                child++;
                dfs_helper(to, from);
                lowest_time[from] = min(lowest_time[from], lowest_time[to]);

                // bridges
                if (lowest_time[to] > discovery_time[from])
                {
                    bridges.push_back(make_pair(from, to));
                }

                // articulation point
                if (par != 0 and lowest_time[to] >= discovery_time[from])
                {
                    arti_points.insert(from);
                }
            }
            else if (to != par and visited[to] == 1)
            { // not the parent and in the call stack
                // Backedge
                cycle = true;
                // cycle_print(from, to);
                lowest_time[from] = min(lowest_time[from], discovery_time[to]);
            }
        }
        visited[from] = 2; // visited and not in call stack
        if (DAG)
        {
            topo_order.push_back(from);
        }
        // root is an arti or not
        if (par == 0 && child > 1)
        {
            arti_points.insert(from);
        }
    }
    void dfs()
    {
        fill(visited.begin(), visited.end(), 0);
        comp_till_now = 0;
        tme = 1;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs_helper(i, 0);
                comp_till_now++;
            }
        }
    }
    void bfs()
    {
        fill(visited.begin(), visited.end(), 0);
        queue<int> Q;
        Q.push(1); // source node
        while (!Q.empty())
        {
            int sz = Q.size();
            vector<int> cur_level;
            for (int i = 0; i < sz; i++)
            {
                int from = Q.front();
                Q.pop();
                visited[from] = 1;
                cur_level.push_back(from);
                for (auto to : gr[from])
                {
                    if (visited[to] == 0)
                    {
                        Q.push(to);
                        visited[to] = 1;
                    }
                }
            }
            levels.push_back(cur_level);
        }
    }
    void path_construction(int from, int to)
    {
        if (parent[to] == 0)
        {
            cout << "NO PATH! ROOT NODE." << endl;
            return;
        }

        int from_component = component[from];
        int to_component = component[to];
        if (from_component != to_component)
        {
            cout << "NO PATH! DIFFERENT COMPONENT.";
            return;
        }

        while (to != from)
        {
            cout << to << " ";
            to = parent[to];
        }
        cout << to << endl;
    }
    void topological_order()
    {
        topo_order.clear();
        DAG = true;
        dfs();
        reverse(topo_order.begin(), topo_order.end());
    }
};

// LCA Sparse Table
const int N = 1e5, M = 20;
vector<int> gr[N];
int dep[N], Par[N][M];
// O(N*M)
void dfs(int cur, int par)
{
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j = 1; j < M; j++)
    {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}

// O(M) = logN
int LCA(int u, int v)
{
    if (u == v)
        return u;
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            u = Par[u][j];
        }
    }
    // u and v are on the same level
    for (int j = M - 1; j >= 0; j--)
    {
        if (Par[u][j] != Par[v][j])
        {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}
// O(1)
int LengthFromUtoV(int u, int v)
{
    int lca = LCA(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1, 0); // cout << LCA(9, 12) << '\n';
    cout << LengthFromUtoV(10, 8) << '\n';
}

// DSU
class dsu
{
public:
    vector<int> parent, size, rank, mx, mn;

public:
    dsu(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            size.push_back(1);
            parent.push_back(i);
            rank.push_back(0);
            mx.pb(i);
            mn.pb(i);
        }
    }
    int find(int node)
    {
        return parent[node] = (parent[node] == node) ? node : find(parent[node]);
    }
    void unionsize(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
        {
            return;
        }

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
            mx[pv] = max(mx[pv], mx[pu]);
            min(mn[pv], mn[pu]);
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            mx[pu] = max(mx[pv], mx[pu]);
            mn[pu] = min(mn[pv], mn[pu]);
        }
    }
    void unionrank(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
        {
            return;
        }
        if (rank[pu] == rank[pv])
        {
            parent[pu] = pv;
            rank[pu]++;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
        }
    }
};

// DP
// Lis using Dp with Binary Search
// dp[i] -> contains the best value from the given array for length i
// dp[i]<arr[i]<dp[i+1] in that case dp[i+1] = arr[i];
int Lis(vi &arr)
{
    int n = arr.size();
    vi dp(n + 1);
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        int lenght = upper_bound(all(dp), arr[i]) - dp.begin();
        if (dp[lenght - 1] < arr[i] and arr[i] < dp[lenght])
        {
            dp[lenght] = arr[i];
        }
    }
    int lis = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            lis = i;
        }
    }
    return lis;
}

// Co-Ordinate Compression
map<int, int> mp, back;
void coordinate_compression(vector<int> &original, vector<int> &duplicate)
{
    int n = original.size(), index = 0;
    for (int i = 0; i < n; i++)
    {
        if (!mp[duplicate[i]])
        {
            mp[duplicate[i]] = index;
            back[index] = duplicate[i];
            index++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        original[i] = mp[original[i]];
    }
}
void solution()
{
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    // Coordinate Compression
    vector<int> duplicate;
    for (int i = 0; i < arr.size(); i++)
    {
        duplicate.push_back(arr[i]);
    }
    sort(duplicate.begin(), duplicate.end());
    output(arr);                            // original
    coordinate_compression(arr, duplicate); // arr has been compressed
    output(arr);                            // compressed
    for (int i = 0; i < n; i++)
    {
        arr[i] = back[arr[i]];
    }
    output(arr); // original
}

// LCS
const int N = 3000;

string s, t, res;
int n, m, memo[N][N];
int give_lcs(int i, int j) {
    if (i == n || j == m) return 0;
    int &ans = memo[i][j];
    if (ans != -1) return ans;
    if (s[i] == t[j]) ans = give_lcs(i + 1, j + 1) + 1;
    else ans = max(give_lcs(i + 1, j), give_lcs(i, j + 1));
    return ans;
}
void trace_back(int i, int j) {
    if (i == n || j == m) return;
    if (s[i] == t[j]) res += s[i], trace_back(i + 1, j + 1);
    else {
        if (give_lcs(i + 1, j) == give_lcs(i, j)) trace_back(i + 1, j);
        else trace_back(i, j + 1);
    }
}

// Find the length of the longest directed path in G. 
// Here, the length of a directed path is the number of edges in it.
const int N = 1e5 + 1;
vector<int> gr[N];
int memo[N];
int dp(int cur) {
    int &ans = memo[cur];
    if (ans != -1) return ans;
    ans = 0;
    for (auto x : gr[cur]) {
        ans = max(ans, dp(x) + 1);
    }
    return ans;
}
int32_t main() {
    // input graph
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int i = 1; i <= n; i++) {ans = max(ans, dp(i));}
    cout << ans;
}

// Knapsack 1
const int N = 100;
int v[N], w[N], W, n, memo[N][100001];
// it returns the maximum value total value
int knapsack(int index, int weight) {
    if (index >= n) return 0;
    // memoissatioon part
    int &ans = memo[index][weight];
    if (ans != -1) return ans;
    // do not take the item
    ans = knapsack(index + 1, weight);
    // take the item at index
    if (w[index] + weight <= W) {
        ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));
    }
    return ans;
}
int32_t main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];  // v[i]<=10^9, w[i]<=10^5
    }
    memset(memo, -1, sizeof(memo));
    cout << knapsack(0, 0);

}

// Knapsack 2 : N=100 w=10^9 v=10^3
const int N = 101;
int v[N], w[N], W, n, mW[N][100001], dp[N][100001];
int32_t main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int val = 0; val < 100001; val++) {
            mW[i][val] = 1e13;
        }
    }
    dp[0][0] = 1;
    mW[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int val = 0; val < 100001; val++) {
            // not taking
            if (dp[i - 1][val]) {
                dp[i][val] = 1;
                mW[i][val] = min(mW[i][val], mW[i - 1][val]);
            }
            // taking item
            if (val - v[i] >= 0 && dp[i - 1][val - v[i]]
                    && mW[i - 1][val - v[i]] + w[i] <= W) {
                dp[i][val] = 1;
                mW[i][val] = min(mW[i][val], mW[i - 1][val - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int val = 0; val < 100001; val++) {
        if (dp[n][val]) ans = val;
    }
}

// Digit Dp (digit sum atcoder)
// Question : Find the number of integers between 1 and K (inclusive) satisfying the 
//following condition, modulo 10^9 +7:  The sum of the digits in base ten is a multiple of D.
const int N = 1e4;
string k;
int d, mod = 1e9 + 7;
int memo[N][2][100];
int dp(int i, bool last, int mod) {
    if (i == k.size()) {
        return (mod == 0);
    }
    int &ans = memo[i][last][mod];
    if (ans != -1) return ans;
    ans = 0;
    int till = last ? (k[i] - '0') : 9;
    for (int digits = 0; digits <= till; digits++) {
        ans += dp(i + 1, last && (digits == till), (mod + digits) % d);
        ans %= mod;
    }
    return ans;
}
int32_t main() {cin >> k >> d;
    memset(memo, -1, sizeof(memo));
    cout << (dp(0, 1, 0) - 1 + apaar) % apaar;
}

/*dp on trees : Question : Print n integers: for each node 1,2,...,n, 
the maximum distance to another node.*/
int n;
vector<vector<int>> gr;
vector<int> g; // max len path in subtree of cur Node
vector<int> f; // for each node the maximum distance to another node
void init(int n) {
    gr.resize(n + 1);
    g.resize(n + 1, 0);
    f.resize(n + 1, 0);
}
void dfs_g(int cur, int par) {
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs_g(x, cur);
            g[cur] = max(g[cur], g[x] + 1);
        }
    }
    f[cur] = g[cur]; // handled the subtree
}
void dfs_f(int cur, int par, int dis_par) {
    int mx1 = 0, mx2 = 0;
    for (auto x : gr[cur]) {
        if (x != par) {
            if (g[x] + 1 > mx1) {
                mx2 = mx1;
                mx1 = g[x] + 1;
            }
            else if (g[x] + 1 > mx2) {
                mx2 = g[x] + 1;
            }
        }
    }
    for (auto x : gr[cur]) {
        if (x != par) {
            int dis_par_new;
            (mx1 == g[x] + 1) ? dis_par_new = mx2 : dis_par_new = mx1;
            dis_par_new = max(dis_par_new, dis_par);
            dfs_f(x, cur, dis_par_new + 1);
        }
        f[cur] = max(f[cur], dis_par); // handled the supertree
    }
}
void solution()
{   // input graph
    dfs_g(1, -1);
    dfs_f(1, -1, -1);
    for (int i = 1; i <= n; i++) {cout << f[i] << " ";} cout << endl;
}


// NCR Code
const int N = 110;
ll fact[N];
ll inverse[N];
void computeFactorial() {
    fact[0] = 1;    inverse[0] = 1;
    for (ll i = 1; i < N - 1; i++) {
        fact[i] = mod_mul(fact[i - 1], i);
        inverse[i] = inv(fact[i]);
        //inverse[i] = pwr(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r) {
    if (n < 0 or r<0 or r>n) return 0;
    return mod_mul(mod_mul(fact[n], inverse[r]), inverse[n - r]);
}