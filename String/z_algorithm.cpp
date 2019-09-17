vector<ll> z_algorithm(const string& s) {
	vector<ll> prefix(s.length());
	for (int i = 1, j = 0; i < s.length(); i++) {
		if (i + prefix[i - j] < j + prefix[j]) {
			prefix[i] = prefix[i - j];
		}
		else {
			ll k = max(0ll, j + prefix[j] - i);
			while (i + k < s.size() && s[k] == s[i + k]) ++k;
			prefix[i] = k;
			j = i;
		}
	}
	prefix[0] = (int)s.size();
	return prefix;
}