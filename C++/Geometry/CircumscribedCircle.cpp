pair<pair<double, double>, double>CircCir(double a, double b, double c, double d, double e, double f) {
	double px, py = ((e - a) * (a * a + b * b - c * c - d * d) - (c - a) * (a * a + b * b - e * e - f * f)) / (2 * ((e - a) * (b - d) - (c - a) * (b - f)));
	if (a == c) { px = (2 * (b - f) * py - a * a - b * b + e * e + f * f) / (2 * (e - a)); }
	else { px = (2 * (b - d) * py - a * a - b * b + c * c + d * d) / (2 * (c - a)); }
	return make_pair(make_pair(px, py), sqrt((px - a) * (px - a) + (py - b) * (py - b)));
}

/*verify: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C
int main() {
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	auto res = CircCir(a, b, c, d, e, f);
	cout << setprecision(20) << res.first.first << " " << res.first.second << " " << res.second << endl;
}
*/