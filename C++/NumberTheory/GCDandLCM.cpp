ll gcd(ll a, ll b) {
	if (!b) { return a; }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}