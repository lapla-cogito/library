pair<int, set<int>> nex(vector<vector<int>>v) {
	vector<set<int>>sh, sv, sb;
	for (int i = 0; i < 9; ++i) {
		set<int>tempv, temph;
		for (int j = 0; j < 9; ++j) {
			if (v[i][j]) { tempv.insert(v[i][j]); }
			if (v[j][i]) { temph.insert(v[j][i]); }
		}
		sv.push_back(tempv);
		sh.push_back(temph);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			set<int>temb;
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (v[i * 3 + k][j * 3 + l]) { temb.insert(v[i * 3 + k][j * 3 + l]); }
				}
			}
			sb.push_back(temb);
		}
	}

	int mon = -1, ind = 0;
	set<int>mons;
	for (int i = 0; i < 81; ++i) {
		if (!v[i / 9][i % 9]) {
			set<int>ss;
			for (auto j : sh[i % 9]) { ss.insert(j); }
			for (auto j : sv[i / 9]) { ss.insert(j); }
			for (auto j : sb[i / 27 * 3 + i % 9 / 3]) { ss.insert(j); }

			if (mon < (int)ss.size()) {
				mon = ss.size();
				ind = i;
				mons = ss;
			}
		}
	}

	return make_pair(ind, mons);
}

int cou = 0;

void solve(int i, vector<vector<int>>v) {
	if (i == cou) {
		for (int j = 0; j < 9; ++j) {
			for (int k = 0; k < 9; ++k) { cout << v[j][k] << " "; }
			cout << endl;
		}
	}
	else {
		auto ne = nex(v);
		int ind = ne.first;
		vector<int>inve;

		for (int j = 1; j < 10; ++j) {
			auto it = ne.second.find(j);
			if (!(it != ne.second.end())) {
				inve.push_back(j);
			}
		}

		for (auto j : inve) {
			v[ind / 9][ind % 9] = j;
			solve(i + 1, v);
			v[ind / 9][ind % 9] = 0;
		}
	}
}

void sudoku(vector<vector<int>>v) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (!v[i][j]) { ++cou; }
		}
	}
	solve(0, v);
}

/*ex:
int main() {
	vector<vector<int>>v = {
		{8,0,0,0,0,0,0,0,0},
		{0,0,3,6,0,0,0,0,0},
		{0,7,0,0,9,0,2,0,0},
		{0,5,0,0,0,7,0,0,0},
		{0,0,0,0,4,5,7,0,0},
		{0,0,0,1,0,0,0,3,0},
		{0,0,1,0,0,0,0,6,8},
		{0,0,8,5,0,0,0,1,0},
		{0,9,0,0,0,0,4,0,0}
	};

	sudoku(v);
}
*/