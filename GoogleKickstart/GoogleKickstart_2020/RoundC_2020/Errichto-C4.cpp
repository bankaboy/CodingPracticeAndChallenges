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

typedef long long ll;

struct Node {
	ll sum, sumA, size;
	void init(ll value) {
		sum = sumA = value;
		size = 1;
	}
	void merge(Node L, Node R) {
		size = L.size + R.size;
		sum = L.sum + R.sum;
		sumA = L.sumA + R.sumA + (ll) R.sum * L.size;
	}
};

void test_case() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if(i % 2) {
			a[i] *= -1;
		}
	}
	int B = 1;
	while(B <= n) {
		B *= 2;
	}
	vector<Node> tree(2 * B);
	for(int i = 0; i < B; ++i) {
		tree[B+i].init(0);
	}
	for(int i = 1; i <= n; ++i) {
		tree[B+i].init(a[i]);
	}
	for(int i = B - 1; i >= 1; --i) {
		tree[i].merge(tree[2*i], tree[2*i+1]);
	}
	
	ll total = 0;
	while(q--) {
		char type;
		scanf(" %c", &type);
		if(type == 'U') {
			int id;
			ll value;
			scanf("%d%lld", &id, &value);
			if(id % 2) value *= -1;
			tree[B+id].init(value);
			for(int i = (B + id) / 2; i >= 1; i /= 2) {
				tree[i].merge(tree[2*i], tree[2*i+1]);
			}
		}
		else {
			int L, R;
			scanf("%d%d", &L, &R);
			bool sign = L % 2;
			L += B;
			R += B;
			bool single = (L == R);
			Node left, right;
			left = tree[L];
			right = tree[R];
			while(L + 1 < R) {
				if(L % 2 == 0) {
					left.merge(left, tree[L+1]);
				}
				if(R % 2) {
					right.merge(tree[R-1], right);
				}
				L /= 2;
				R /= 2;
			}
			Node answer = left;
			if(!single) {
				answer.merge(left, right);
			}
			if(sign) {
				answer.sumA *= -1;
			}
			debug() << imie(answer.sumA);
			// printf("%lld\n", answer.sumA);
			total += answer.sumA;
		}
	}
	printf("%lld\n", total);
	
	// vector<ll> pref(n + 1), prefA(n + 1);
	// for(int i = 1; i <= n; ++i) {
		// pref[i] = pref[i-1] + a[i];
		// prefA[i] = prefA[i-1] + (long long) i * a[i];
	// }
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
