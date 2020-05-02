#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 405, mod = 20170408;
inline int mul(int x, int y) { return (int)(1ll * x * y % (ll)mod); }

int r[N], n, m, p, len = 1, tot = 0;
ll A[N], B[N], C[N], ans[N], a[N], b[N], c[N], d[N];

const int P[3] = {469762049, 998244353, 167772161}, G = 3, Gi[3] = {P[0] / G + 1, P[1] / G + 1, P[2] / G + 1};

ll fpow(ll x, ll y, ll p) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        y >>= 1; x = x * x % p;
    }
    return ans;
}

void NTT(ll *a, int tp, int t) {
    for(int i = 1; i < len; i++) if(i < r[i]) swap(a[i], a[r[i]]);
    for(int mid = 1; mid < len; mid <<= 1) {
        ll wn = fpow(tp == 1 ? G : Gi[t], (P[t] - 1) / (mid << 1), P[t]);
        for(int i = 0; i < len; i += (mid << 1)) {
            ll w = 1;
            for(int j = 0; j < mid; j++, w = w * wn % P[t]) {
                ll x = a[i + j], y = a[i + j + mid] * w % P[t];
                a[i + j] = (x + y) % P[t]; a[i + j + mid] = (x - y + P[t]) % P[t];
            }
        }
    }
    if(tp == -1) {
        ll inv = fpow(len, P[t] - 2, P[t]);
        for(int i = 0; i < len; i++) a[i] = a[i] * inv % P[t];
    }
}

ll inv(ll x, ll y) { return fpow(x, y - 2, y); }

ll times(ll x, ll y, ll p) {
    ll ans = 0;
    while(y) {
        if(y & 1) ans = (ans + x) % p;
        y >>= 1; x = (x + x) % p;
    }
    return ans;
}

void mul(ll *A, ll *B, ll *ans) {
    for(int i = 1; i <= p; i++) A[i - 1] = A[i], B[i - 1] = B[i]; A[p] = B[p] = 0;
    len = 1; tot = 0;
    while(len <= (p << 1)) len <<= 1, tot++;
    for(int i = 1; i < len; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (tot - 1));
    memcpy(a, A, sizeof(a)); memcpy(b, A, sizeof(b)); memcpy(c, A, sizeof(c));
    memcpy(d, B, sizeof(d)); NTT(a, 1, 0); NTT(d, 1, 0); for(int i = 0; i < len; i++) a[i] = a[i] * d[i] % P[0]; NTT(a, -1, 0);
    memcpy(d, B, sizeof(d)); NTT(b, 1, 1); NTT(d, 1, 1); for(int i = 0; i < len; i++) b[i] = b[i] * d[i] % P[1]; NTT(b, -1, 1);
    memcpy(d, B, sizeof(d)); NTT(c, 1, 2); NTT(d, 1, 2); for(int i = 0; i < len; i++) c[i] = c[i] * d[i] % P[2]; NTT(c, -1, 2);
    for(int i = 0; i <= (p << 1); i++) {
        ll p = 1ll * P[0] * P[1];
        ll s = times(a[i], times(P[1], inv(P[1], P[0]), p), p) + times(b[i], times(P[0], inv(P[0], P[1]), p), p); s %= p;
        ll k = (c[i] % P[2] - s % P[2] + P[2]) % P[2] * inv(p % P[2], P[2]) % P[2];
        ll Ans = (s + (k * P[0] % mod * P[1] % mod)) % mod;
        ans[i + 1] = Ans;
    }
    for(int i = 1; i <= p; i++) ans[i] = (ans[i] + ans[i + p]) % mod, ans[i + p] = 0;
    for(int i = p; i >= 1; i--) A[i] = A[i - 1], B[i] = B[i - 1]; A[0] = B[0] = 0;
}

int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int pri[5000000], plen;
bool isp[20000005];

void init_pri(int n, ll *a) {
    isp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isp[i]) { pri[++plen] = i; }
        for(int j = 1; j <= plen && i * pri[j] <= n; j++) {
            isp[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    for(int i = 1; i <= p; i++) a[i] = 0;
    for(int i = 1; i <= n; i++) if(isp[i]) ++a[i % p + 1];
}

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    read(n); read(m); read(p); init_pri(m, A); int t = n;
    ans[1] = 1;
    while(n) {
        if(n & 1) {
            memcpy(B, ans, sizeof(B));
            mul(A, B, ans);
        }
        n >>= 1;
        memcpy(B, A, sizeof(B));
        memcpy(C, A, sizeof(C));
        mul(B, C, A);
    }
    int fir = ans[1];
    memset(ans, 0, sizeof(ans));
    memset(A, 0, sizeof(A));
    for(int i = 1; i <= m; i++) ++A[i % p + 1];
    ans[1] = 1; n = t;
    while(n) {
        if(n & 1) {
            memcpy(B, ans, sizeof(B));
            mul(A, B, ans);
        }
        n >>= 1;
        memcpy(B, A, sizeof(B));
        memcpy(C, A, sizeof(C));
        mul(B, C, A);
    }
    cout << (ans[1] - fir + mod) % mod << endl;
    return 0;
}
