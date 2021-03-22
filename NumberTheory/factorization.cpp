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
