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
// Extended Euclid's Algorithm ax + by = gcd(a,b)
vector<int> extendedGCD(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    vector<int> result = extendedGCD(b, a % b);
    int smallX = result[0];
    int smallY = result[1];
    int gcd = result[2];
    int x = smallY;
    int y = smallX - (a / b) * smallY;
    return {x, y, gcd};
}

// Code for MMI
int modInverse(int a, int m)
{
    vector<int> result = extendedGCD(a, m);
    int x = result[0];
    int gcd = result[2];
    if (gcd != 1)
    {
        cout << "Multiplicative Modulo Inverse doesn't exist";
        return -1;
    }
    int ans = (x % m + m) % m; // x can be negative also, {1,2,3....m-1}
    return ans;
}

// Matrix Exponentiation
const int mod = 1e9 + 7;
const int sz = 2;
struct Mat
{
    int m[sz][sz];
    Mat() { memset(m, 0, sizeof(m)); }
    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;
        }
    }
    Mat operator*(Mat a)
    {
        Mat res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
int Fib(int n)
{
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    if (n <= 2)
        return 1;
    n -= 2;
    while (n)
    {
        if (n & 1)
            res = res * T;
        T = T * T;
        n /= 2;
    }
    return (res.m[0][0] + res.m[0][1]) % mod;
}

// Totient
const int N = 1e5;
void calculate_totient()
{
    vector<bool> pr(N, true);
    vector<int> tot(N);
    for (int i = 2; i < N; i++)
    {
        for (int j = i * i; j < N; j += i)
        {
            pr[j] = false;
        }
    }
    iota(tot.begin(), tot.end(), 0);
    for (int i = 2; i < N; i++)
    {
        if (pr[i] == true)
        {
            for (int j = i; j < N; j += i)
            {
                tot[j] /= i;
                tot[j] *= (i - 1);
            }
        }
    }
}

// Big number Addition
char digitToChar(int digit) { return digit + '0'; }
int charToDigit(char ch) { return ch - '0'; }
string addNumbers(string n1, string n2)
{
    // Make sure N2 is larger
    if (n1.length() > n2.length())
    {
        swap(n1, n2);
    }
    string result = "";
    // Reverse
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    // Add digit upto a n1.length()
    int carry = 0;
    for (int i = 0; i < n1.length(); i++)
    {
        int d1 = charToDigit(n1[i]);
        int d2 = charToDigit(n2[i]);
        int sum = d1 + d2 + carry;
        int output_digit = sum % 10;
        carry = sum / 10;
        result.push_back(digitToChar(output_digit));
    }
    for (int i = n1.length(); i < n2.length(); i++)
    {
        int d2 = charToDigit(n2[i]);
        int sum = d2 + carry;
        int output_digit = sum % 10;
        carry = sum / 10;
        result.push_back(digitToChar(output_digit));
    }
    // Finally if a carrry is generated
    if (carry)
    {
        result.push_back('1');
    }
    // Reverse the final result
    reverse(result.begin(), result.end());
    return result;
}

// Factorials of Big numbers
void multiply(vector<int> &a, int no, int &size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int product = a[i] * no + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        a[size] = carry % 10;
        carry = carry / 10;
        size = size + 1;
    }
}
void bigFactorial(int n)
{
    vector<int> a(1000, 0);
    a[0] = 1;
    int size = 1;
    for (int i = 2; i <= n; i++)
    {
        multiply(a, i, size);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
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

// Miller Rabin 
// (a x b) % n
int moduler_multiplication(int a, int b, int n) {
	int res = 0;
	while (b) {
		if (b & 1ll) {res += a;}
		a *= 2;
		b >>= 1;
		res %= n;
		a %= n;
	}
	return res;
}

// (a^b)%n
int moduler_exponentiation(int a, int b, int n) {
	int res = 1;
	while (b) {
		if (b & 1ll) {
			res = moduler_multiplication(res, a, n);
		}
		a = moduler_multiplication(a, a, n);
		res %= n;
		a %= n;
		b >>= 1;
	}
	return res;
}

// Miller Rabin Primality Testing till number less than 3825123056546413051 (3X10^18)
bool miller_rabin(int n) {
	if (n == 1) {return false;}
	if (n == 2) {return true;}
	if (n % 2 == 0) {return false;}
	// now n is >=3 and odd
	int d = n - 1, s = 0;
	while (d % 2 == 0) {
		s++;
		d /= 2;
	}
	// d is odd and n-1 = d*pow(2,s)
	vector<int> a({2, 3, 5, 7, 11, 13, 17, 19, 23});

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > n - 2) {continue;}//since 2<=a[i]<=n-2

		int ad = moduler_exponentiation(a[i], d, n); // ad -> a^d
		if (ad % n == 1) {continue;} // n might be a prime , check for other a[i]

		bool prime = false;
		for (int r = 0; r <= s - 1; r++) {
			int _2r = moduler_exponentiation(2, r, n); // _2r -> (2^r)%n
			int ad_2r = moduler_exponentiation(ad, _2r, n); // ad_2r -> {(a^d)^(2^r)}%n
			if (ad_2r % n == n - 1) {
				prime = true;
				break;
			}
		}
		if (prime == false) {return false;}
	}
	return true;
}

// Meet in the middle
vector<int> subsetsums(vector<int> a)
{
    int n = a.size();
    vector<int> result;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                sum += a[j];
        }
        result.push_back(sum);
    }
    return result;
}

int32_t main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> left, right;
    for (int i = 0; i < n; i++)
    {
        if (i <= n / 2)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    vector<int> left_sums = subsetsums(left);
    vector<int> right_sums = subsetsums(right);
    sort(right_sums.begin(), right_sums.end());
    int ans = 0;
    for (auto x : left_sums)
    {
        ans += upper_bound(right_sums.begin(), right_sums.end(), b - x) -
               lower_bound(right_sums.begin(), right_sums.end(), a - x);
    }
    cout << ans;
    return 0;
}

// sqrt Decomposition
int main()
{
    int n, m;
    cin >> n;
    m = sqrt(n) + 1;
    int a[n], b[m];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i / m] += a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, ans = 0;
        cin >> l >> r;
        for (int i = l; i <= r;)
        {
            if (i % m == 0 && i + m - 1 <= r)
            { // lies completely inside the [l...r]
                ans += b[i / m];
                i += m;
            }
            else
            {
                ans += a[i];
                i++;
            }
        }
        cout << ans << '\n';
    }
}

// Mo's Algorithm
const int N = 2e5;
int a[N], cnt[N * 10], distinct;
struct query
{
    int l, r, id, block, ans;
    bool operator<(query P) const
    {
        return make_pair(this->block, r) < make_pair(P.block, P.r);
    }
} q[N];
bool comp(query a, query b) { return a.id < b.id; }
void add(int val)
{
    cnt[val]++;
    if (cnt[val] == 1)
        distinct++;
}
void remove(int val)
{
    cnt[val]--;
    if (cnt[val] == 0)
        distinct--;
}
int main()
{
    int n, m, queries;
    cin >> n;
    m = sqrt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].id = i, q[i].block = q[i].l / m;
    }
    sort(q, q + queries);
    int x = 0, y = 0;
    for (int i = 0; i < queries; i++)
    {
        // adding y
        while (y <= q[i].r)
        {
            add(a[y]);
            y++;
        }
        // removing y
        while (y > q[i].r + 1)
        {
            y--;
            remove(a[y]);
        }
        // removing x
        while (x < q[i].l)
        {
            remove(a[x]);
            x++;
        }
        // adding x
        while (x > q[i].l)
        {
            x--;
            add(a[x]);
        }
        // distinct indicated the answer
        q[i].ans = distinct;
    }
    sort(q, q + queries, comp);
    for (int i = 0; i < queries; i++)
    {
        cout << q[i].ans << '\n';
    }
}


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
vector<int> compute_lps_better(string s) {
	int n = s.size();
	vector<int> lps(n);
	lps[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = lps[i - 1];
		while (j > 0 and s[i] != s[j]) {
			j = lps[j - 1];
		}
		if (s[i] == s[j]) {j++;}
		lps[i] = j;
	}
	return lps;
}

vector<int> kmp(string text, string pattern) {
	int n = text.size(), m = pattern.size();
	vector<int> lps = compute_lps_better(pattern);
	vector<int> occurences;
	int i = 0, j = 0;
	while (i < n) {
		if (text[i] == pattern[j]) {
			i++; j++;
		}
		else {
			(j == 0) ? i++ : j = lps[j - 1];
		}
		if (j == m) { // Occurences found
			occurences.push_back(i - m);
			j = lps[j - 1];
		}
	}
	return occurences;
}

vector<int> string_matching(string text, string pattern) {
	string good = pattern + "&" + text;
	vector<int> lps = compute_lps_better(good);
	vector<int> occurences;
	for (int i = pattern.size() + 1; i < good.size(); i++) {
		if (lps[i] == pattern.size()) { // Occurences found
			// int index = (i - pattern.size() + 1) - (pattern.size() + 1);
			int index = i - (2 * pattern.size());
			occurences.push_back(index);
		}
	}
	return occurences;
}

void solution()
{
	string s,t;
	cin >> s >> t;
	vi occurences = kmp(s, t);
	output(occurences);

}

// Z-Algorithm
vector<int> z_best(string s) {
	int n = s.size();
	vector<int> z(n, 0);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i <= R) {
			z[i] = min(z[i - L], R - i + 1);
		}
		while (i + z[i] < n and s[z[i]] == s[z[i] + i]) {
			z[i]++;
		}
		if (i + z[i] - 1 > R) {
			L = i; R = i + z[i] - 1;
		}
	}
	return z;
}

// Find All the occurences of a string
vector<int> match_string(string text, string pattern) {
	string good = pattern + "$" + text;
	vector<int> z = z_best(good);
	vector<int> occurences;
	for (int i = pattern.size() + 1; i < good.size(); i++) {
		if (z[i] == pattern.size()) {
			occurences.pb(i - (pattern.size() + 1));
		}
	}
	return occurences;
}

// Longest Palindromic Prefix
int longest_palindromic_prefix(string s) {
	int n = s.size();
	string good = s + "%";
	reverse(s.begin(), s.end());
	good += s;

	vector<int> z = z_best(good);

	cout << good << endl;
	int ans = INT_MIN;
	for (int i = 0; i < good.size(); i++) {
		if (i + z[i] == good.size()) {
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
// Manacher's Algorithm O(n)  // Longest Palindromic Substring O(n*n)
string transform(string &s) {
	string temp = "#";
	for (auto ch : s) {
		temp += ch;
		temp += '#';
	}
	return temp;
}

string manachers_algo(string &s) {
	string t = transform(s);
	int n = t.size(), mxLen = 0, centre; // centre-> mid point of lps
	int l = 0; 	// to track the left boundary of the right most plaindrome
	int r = 0;	// to track the left boundary of the right most plaindrome
	vector<int> p(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		int k;
		if (i > r) {
			k = 0;
		} else {
			int j = l + (r - i);
			if (j - p[j] > l) {
				p[i] = p[j];
				continue;
			} else {
				k = r - i;
			}
		}
		while (i - k >= 0 and i + k < n and t[i - k] == t[i + k]) {
			k++;
		}
		k--;
		p[i] = k;
		if (p[i] > mxLen) {
			mxLen = p[i];
			centre = i / 2;
		}
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	return s.substr(centre - (mxLen / 2), mxLen);
}


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
