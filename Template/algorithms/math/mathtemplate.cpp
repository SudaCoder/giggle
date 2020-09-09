#include <bits/stdc++.h>
using namespace std;

namespace Math {
	typedef long long ll;
	typedef long long LL;
	typedef unsigned long long ull;
	typedef unsigned long long ULL;
	const int MOD = 1000000007;

	/* Set this value to 0 to cancel these values. */
	#define USEFACTORIAL 1

	#if USEFACTORIAL
	const int MAXN = 200000;
	LL inv[MAXN + 4];
	LL fac[MAXN + 4]; 
	LL invfac[MAXN + 4];
	#endif

	/* 	Issues:
		1) 	make sure that sz <= MAXN;
		2)	make sure that mod is prime. 
	*/
	void init(int sz = MAXN, int mod = Math::MOD) {

	#if USEFACTORIAL
		inv[1] = 1;
		fac[0] = invfac[0] = fac[1] = invfac[1] = 1;
		for (int i = 2; i <= sz; ++i) {
			inv[i] = (mod - mod / i) * inv[mod % i] % mod;
			fac[i] = fac[i - 1] * i % mod;
			invfac[i] = invfac[i - 1] * inv[i] % mod;
		}
	#endif

	}
	
	/* 	Issues:
		1)	would overflow when a >= INT_MAX, so get a modded in advance;
		2)	would got wrong answer when b = 0 and a >= mod, so check it carefully!
	*/
	LL qp(LL a, LL b, int mod = Math::MOD) {
		int ret = 1;
		while (b) {
			if (b & 1)
				ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		//	To solve Issue 2), append "% mod" here.
		return ret;
	}

	/*	Issues:
		1)	only works when mod is prime and a % mod > 0.
	*/
	LL getInv(LL a, int mod = Math::MOD) {
		return qp(a, mod - 2, mod);
	}

	LL gcd(LL a, LL b) {
		return b?gcd(b, a%b):a;
	}

	LL lcm(LL a, LL b) {
		return a / gcd(a, b) * b;
	}

	#if USEFACTORIAL
	/*	Caculate number of permutations: 
		number of ways to select b balls from a balls (pairwise distinct) to form an array.

		Issues:
		1)	make sure that you have initialized the array first (Math::init(size, mod));
		2)	make sure that b <= a <= size;
		3)	make sure that mod is equal to the mod when you init the array.
	*/
	LL Perm(int a, int b, int mod = Math::MOD) {
		return fac[a] * invfac[a - b] % mod;
	}

	/*	Caculate number of combinations: 
		number of ways to select b balls from a balls (pairwise distinct) to form a set.

		Issues:
		1)	make sure that you have initialized the array first (Math::init(size, mod));
		2)	make sure that b <= a <= size;
		3)	make sure that mod is equal to the mod when you init the array.
	*/
	LL Comb(int a, int b, int mod = Math::MOD) {
		return fac[a] * invfac[b] % mod * invfac[a - b] % mod;
	}
	#endif

	/*	Caculate number of combinations in O(b log(mod)) or O(b).
		only use it when a is too large and b is small.

		Issues:
		1)	make sure that b <= a <= INT_MAX.
	*/
	LL CombSmall(LL a, int b, int mod = Math::MOD) {
		LL ret = 1;
		for (int i = 0; i < b; ++i) {
			/* 	If USEFACTORIAL == 1 and b <= MAXN, you could replace 
				getInv(i + 1) with inv[i + 1] (make sure mod == Math::MOD).
			*/
			ret = ret * (a - i + mod) % mod * getInv(i + 1) % mod;
		}
		return ret;
	}
	
};