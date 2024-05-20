#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  int     long long

#define    all(v)         (v).begin(),(v).end()
#define    all1(v)        (v).begin()+1,(v).end()
#define    sort0(v)       sort(all(v))
#define    pb             emplace_back
#define    ppb            pop_back
#define    mkp            make_pair

#define    for0(i,n)      for (int i = 0; i < n; i++)
#define    forr(i,a,b)    for(i=a;i<=b;i++)

#define    yes            cout << "YES" << endl;
#define    no             cout << "NO" << endl;
#define    endl           "\n"
#define    infinity       9999999999999

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


void solution()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.pb(x);
    }
    segmenttree tree;
    tree.init(n);
	tree.build(arr);

    int allGcd = tree.query(0, n - 1);
    if(allGcd!=1){
        cout << -1 << endl;
        return;
    }

    auto possible = [&](int m) -> bool
    {
        int Gcd = tree.query(0, m - 1);
        if(Gcd==1ll){
            return true;
        }

        for (int i = 1; i + m <= n; i++){
            int cur_gcd = tree.query(i, i + m - 1);
            if(cur_gcd==1ll){
                return true;
            }
        }
        return false;
    };

    int l = 0, r = n;
    while((r-l)>1){
        int m = (r + l)/2;
        possible(m) ? r = m : l = m;
    }

    cout << r << endl;
}

int32_t main()
{
    Sezar;
    // tc(t) solution();
    solution();
}