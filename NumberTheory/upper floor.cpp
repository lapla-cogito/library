long long upperfloor(long long n) {
	long long ans = 1;
	while (n) {
		ans *= n;
		--n;
	}
	return ans;
}

//ex
int main() {
	cout << upperfloor(3) << endl;
}