#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int nax = 1005;
char grid[nax][nax];

void test_case() {
	int h, w;
	scanf("%d%d", &h, &w);
	for(int row = h - 1; row >= 0; --row) {
		scanf("%s", grid[row]);
	}
	string s;
	vector<bool> taken(26);
	for(int rep = 0; rep < 26; ++rep) {
		vector<bool> ok(26);
		for(int row = 0; row < h; ++row) {
			for(int col = 0; col < w; ++col) {
				if(!taken[grid[row][col]-'A']) {
					ok[grid[row][col]-'A'] = true;
				}
			}
		}
		// for(int i = 0; i < 26; ++i) {
			// ok[i] = !taken[i];
		// }
		for(int col = 0; col < w; ++col) {
			int row = 0;
			while(row < h && taken[grid[row][col]-'A']) {
				row++;
			}
			if(row == h) {
				continue;
			}
			// char candidate = grid[row][col];
			while(row + 1 < h && grid[row][col] == grid[row+1][col]) {
				row++;
			}
			for(int i = row + 1; i < h; ++i) {
				ok[grid[i][col]-'A'] = false;
			}
		}
		for(int i = 0; i < 26; ++i) {
			if(ok[i]) {
				s += char('A' + i);
				taken[i] = true;
			}
		}
	}
	bool ok = true;
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			if(!taken[grid[row][col]-'A']) {
				ok = false;
			}
		}
	}
	if(ok) {
		printf("%s\n", s.c_str());
	}
	else {
		puts("-1");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
