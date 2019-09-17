#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
const long long INF = 9999999999999999999;
const int MOD = 1e9 + 7;
const double pi = 3.141592653589793238;
const int SIZE = 1 << 17;

template<typename T>
struct lazysegtree {
	T node[2 * SIZE], lazy[2 * SIZE], I_upd,I_qry;
	bool used[2 * SIZE];
	T(*upd_f)(T, T, int, int), (*qry_f)(T, T);
	
	lazysegtree(T(*op1)(T, T, int, int), T(*op2)(T, T), T X_upd,T X_qry) {
		upd_f = op1;
		qry_f = op2;
		I_upd=X_upd;
		I_qry=X_qry;
		fill(lazy, lazy + 2 * SIZE, I_upd);
		fill(node, node + 2 * SIZE, I_qry);
		fill(used, used + 2 * SIZE, false);
	}
	
	void init(vector<T>vec){
	    for(int i=0;i<(int)vec.size();++i){
	        node[SIZE-1+i]=vec[i];
	    }
	    for(int i=SIZE-2;i>=0;--i){
	        node[i]=qry_f(node[2*i+1],node[2*i+2]);
	    }
	}
 
	void lazy_eval(int a, int b, int c) {
		if (!used[a]) { return; }
		node[a] = upd_f(node[a], lazy[a], b, c);
		if (c - b > 1) {
			lazy[2 * a + 1] = upd_f(lazy[2 * a + 1], lazy[a], 0, 1);
			lazy[2 * a + 2] = upd_f(lazy[2 * a + 2], lazy[a], 0, 1);
			used[2 * a + 1] = used[2 * a + 2] = true;
		}
		lazy[a] = I_upd;
		used[a] = false;
	}
 
	void update(int a, int b, T val, int c = 0, int d = SIZE, int e = 0) {
		lazy_eval(e, c, d);
		if (b <= c || d <= a) { return; }
		if (a <= c && d <= b) {
			lazy[e] = upd_f(lazy[e], val, 0, 1);
			used[e] = true;
			lazy_eval(e, c, d);
		}
		else {
			int monn = (c + d) / 2;
			update(a, b, val, c, monn, 2 * e + 1);
			update(a, b, val, monn, d, 2 * e + 2);
			node[e] = qry_f(node[2 * e + 1], node[2 * e + 2]);
		}
	}
 
	T query(int a, int b, int c = 0, int d = SIZE, int e = 0) {
		lazy_eval(e, c, d);
		if (b <= c || d <= a) { return I_qry; }
		if (a <= c && d <= b) { return node[e]; }
		int monn = (c + d) / 2;
		T lmon = query(a, b, c, monn, 2 * e + 1);
		T rmon = query(a, b, monn, d, 2 * e + 2);
		return qry_f(lmon, rmon);
	}
};
 
long long upd(long long a, long long b, int c, int d) { return min(a,b); }
long long fin(long long a, long long b) { return min(a, b); }
lazysegtree<long long>seg(upd, fin, INF,INF);

//ex(DSL_2)
int main() {
	int a, b;
	cin >> a >> b;
	while (b--) {
		int n;
		cin >> n;
		if (n) {
			int c, d;
			cin >> c >> d;
			cout << seg.query(c, d + 1) << endl;
		}
		else {
			int c, d, e;
			cin >> c >> d >> e;
			seg.update(c, d + 1, e);
		}
	}
}