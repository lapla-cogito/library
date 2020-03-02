//geometry(2D)

//length between two points
D len(P a, P b) {
	return (D)sqrt((real(a) - real(b)) * (real(a) - real(b)) + (imag(a) - imag(b)) * (imag(a) - imag(b)));
}

//dot product
D dot(P a, P b) {
	return (conj(a) * b).X;
}
//cross product
D cross(P a, P b) {
	return (conj(a) * b).Y;
}

//line
struct L : public vector<P> {
	L(const P& a, const P& b) {
		push_back(a); push_back(b);
	}
};

//circle
struct C {
	P p; double r;
	C(const P& p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
	b -= a;  c -= a;
	if (cross(b, c) > EPS) return +1;  // counter clockwise
	if (cross(b, c) < -EPS) return -1;  // clockwise
	if (dot(b, c) < -EPS) return +2;  // c--a--b on line
	if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
	return 0;                          // a--c--b on line or a==c or b==c
}

//a line and a point
bool isecLP(P a1, P a2, P b) {
	return abs(ccw(a1, a2, b)) != 1;  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

//two lines
bool isecLL(P a1, P a2, P b1, P b2) {
	return !isecLP(a2 - a1, b2 - b1, 0) || isecLP(a1, b1, b2);
}

//a line and a segment
bool isecLS(P a1, P a2, P b1, P b2) {
	return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS;
}

//two segments
bool isecSS(P a1, P a2, P b1, P b2) {
	return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
		ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
}

//a segment and a point
bool isecSP(P a1, P a2, P b) {
	return !ccw(a1, a2, b);
}

//2直線の交点
P crosspointLL(P a1, P a2, P b1, P b2) {
	D d1 = cross(b2 - b1, b1 - a1);
	D d2 = cross(b2 - b1, a2 - a1);
	if (EQ(d1, 0) && EQ(d2, 0)) { return a1; } //同一直線上
	if (EQ(d2, 0)) { throw  "no crosspoint"; } //交点なし
	return a1 + d1 / d2 * (a2 - a1);
}

//2円の交点
Q crosspointCC(P a, D ar, P b, D br) {
	Q ps;
	P ab = b - a;
	D d = abs(ab);
	D crL = (norm(ab) + ar * ar - br * br) / (2 * d);
	if (EQ(d, 0) || ar < abs(crL)) { return ps; }

	P abN = ab * P(0, sqrt(ar * ar - crL * crL) / d);
	P cp = a + crL / d * ab;
	ps.push_back(cp + abN);
	if (!EQ(norm(abN), 0)) { ps.push_back(cp - abN); }
	return ps;
}

//半径rでaとbを通る円の中心
Q circlesPointsRadius(P a, P b, D r) {
	Q cs;
	P abH = (b - a) * 0.5;
	D d = abs(abH);
	if (d == 0 || d > r) { return cs; }  // 必要なら !LE(d,r) として円1つになる側へ丸める
	D dN = max(0.0, sqrt(r * r - d * d));
	P n = abH * P(0, 1) * (dN / d);
	cs.push_back(a + abH + n);
	if (dN > 0) cs.push_back(a + abH - n);
	return cs;
}

//pからaへの接線とaとの交点
Q tangentPoints(P a, D ar, P p) {
	Q ps;
	D sin = ar / abs(p - a);
	if (!LE(sin, 1)) { return ps; }
	D t = pi / 2 - asin(min(sin, 1.0));
	ps.push_back(a + (p - a) * polar(sin, t));
	if (!EQ(sin, 1)) { ps.push_back(a + (p - a) * polar(sin, -t)); }
	return ps;
}

//三角形abcの外心
P circumcenter(P a, P b, P c) {
	a = (a - c) * 0.5;
	b = (b - c) * 0.5;
	return c + crosspointLL(a, a * P(1, 1), b, b * P(1, 1));
}


//点aと点bを通り直線lに接する円の中心
Q circlesPointsTangent(P a, P b, P l1, P l2) {
	P n = (l2 - l1) * P(0, 1);
	P m = (b - a) * P(0, 0.5);
	D rC = dot((a + b) * 0.5 - l1, n);
	D qa = norm(n) * norm(m) - dot(n, m) * dot(n, m);
	D qb = -rC * dot(n, m);
	D qc = norm(n) * norm(m) - rC * rC;
	D qd = qb * qb - qa * qc;  // qa*k^2 + 2*qb*k + qc = 0

	Q cs;
	if (qd < -EPS) { return cs; }
	if (EQ(qa, 0)) {
		if (!EQ(qb, 0)) { cs.push_back((a + b) * 0.5 - m * (qc / qb / 2)); }
		return cs;
	}
	D t = -qb / qa;
	cs.push_back((a + b) * 0.5 + m * (t + sqrt(max(qd, 0.0)) / qa));
	if (qd > EPS) { cs.push_back((a + b) * 0.5 + m * (t - sqrt(max(qd, 0.0)) / qa)); }
	return cs;
}

//点集合を含む最小の円の中心
P minEnclosingCircle(const Q& ps) {
	P c;
	double move = 0.5;
	for(int i=0;i<39;++i) {  // 2^(-39-1) \approx 0.9e-12
		for(int t=0;t<50;++t) {
			D max = 0;
			int k = 0;
			for (int j = 0; j < ps.size();++j) {
				if (max < norm(ps[j] - c)) {
					max = norm(ps[j] - c);
					k = j;
				}
			}
			c += (ps[k] - c) * move;
		}
		move /= 2;
	}
	return c;
}

//凸多角形の内部判定
//点が領域内部なら1、境界上なら2、外部なら0
int inCcwConvex(const Q& ps, P p) {
	int n = ps.size();
	P g = (ps[0] + ps[n / 3] + ps[n * 2 / 3]) / 3.0;
	if (g == p) { return 1; }
	P gp = p - g;

	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		P gl = ps[l] - g;
		P gm = ps[mid] - g;
		if (cross(gl, gm) > 0) {
			if (cross(gl, gp) >= 0 && cross(gm, gp) <= 0) { r = mid; }
			else { l = mid; }
		}
		else {
			if (cross(gl, gp) <= 0 && cross(gm, gp) >= 0) { l = mid; }
			else { r = mid; }
		}
	}
	r %= n;
	D cr = cross(ps[l] - p, ps[r] - p);
	return EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;
}

//多角形の内部判定
//返り値は上と同じ
int inPolygon(const Q& ps, P p) {
	int n = ps.size();
	bool in = false;
	for(int i=0;i<n;++i){
		P a = ps[i] - p;
		P b = ps[(i + 1) % n] - p;
		if (EQ(cross(a, b), 0) && LE(dot(a, b), 0)) { return 2; }
		if (a.Y > b.Y) { swap(a, b); }
		if ((a.Y * b.Y < 0 || (a.Y * b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) { in = !in; }
	}
	return in;
}
