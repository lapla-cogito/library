vector<ll> factori(ll n) {
	vector<ll>res;
	ll mon = 2;
	while (n >= mon * mon) {
		if (n % mon == 0) {
			res.push_back(mon);
			n /= mon;
		}
		else { ++mon; }
	}
	res.push_back(n);
	return res;
}

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
int main() {
	ll n;
	cin >> n;
	cout << n << ": ";
	outp(factori(n));
	cout << endl;
}
*/