vector<long long> factori(long long n) {
	vector<long long>res;
	long long mon = 2;
	while (n >= mon * mon) {
		if (n%mon == 0) {
			res.push_back(mon);
			n /= mon;
		}
		else { ++mon; }
	}
	res.push_back(n);
	return res;
}