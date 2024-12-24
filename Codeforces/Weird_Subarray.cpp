
#include<bits/stdc++.h>

using namespace std;


#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long
#define  int     long long
#define  ld     long double


// summation
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = __gcd(st[node * 2 + 1] , st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return __gcd(q1 , q2);
    }

    
    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

};


// summation with lazy propagation
struct segmenttreelazy {
    int n;
    vector<int> st, lazy;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1] , st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return INT_MIN;
        }

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {
            // pending updates
            // update the segment tree node
            st[node] = max(st[node],lazy[node]);
            if (start != ending) {
                // propagate the updated value
                lazy[2 * node + 1] = max(lazy[node],lazy[2*node+1]);
                lazy[2 * node + 2] = max(lazy[node],lazy[2*node+2]);
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1 , q2);
    }

    void update(int start, int ending, int node, int l, int r, int value) {
        // non overlapping case
        if (start > r || ending < l) {
            return ;
        }

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {
            // pending updates
            // update the segment tree node
            st[node] = max(st[node],lazy[node]);
            if (start != ending) {
                // propagate the updated value
                lazy[2 * node + 1] = max(lazy[node],lazy[2*node+1]);
                lazy[2 * node + 2] = max(lazy[node],lazy[2*node+2]);
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            st[node] = max(st[node],value);
            if (start != ending) {
                lazy[2 * node + 1] = max(value,lazy[2*node+1]);
                lazy[2 * node + 2] = max(value,lazy[2*node+2]);
            }
            return;
        }

        // partial case
        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);

        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = max(st[node * 2 + 1] , st[node * 2 + 2]);

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x) {
        update(0, n - 1, 0, l, r, x);
    }
};



void solution()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    segmenttree tree;
    tree.init(n);
    tree.build(arr);

    vector<int> temp(n, INT_MIN);
    segmenttreelazy lazy;
    lazy.init(n);
    lazy.build(temp);

    int i = 0, j = 0;
    vector<int> ans(n);
    while(j<n){
        if(tree.query(i, j)==1){
            break;
        }
        j++;
    }

    lazy.update(i, j, (j - i));

    for (int k = 0; k < n; k++){
        ans[k] = lazy.query(k,k);
        while(i<k){
            ans[k] = max(ans[k], (j - i));
            if(tree.query(i,j)==1){
                i++;
            }else{
                break;
            }
        }

        while(j<n and tree.query(i,j)!=1){
            j++;
        }

        ans[k] = max(ans[k], (j - i));

        lazy.update(i, j, (j - i));

        //cout << i << " " << j << "-->" << tree.query(i, j) << endl;
    }

    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    Sezar;
    // tc(t) solution();
    solution();
}