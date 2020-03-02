bool isprime(ll n) {
	for (ll i = 2; i * i <= n; ++i) {
		if (x % i == 0) { return false; }
	}
	return true;
}
