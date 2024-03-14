#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

class BigInt {
public:
	static const int SZ = 256;
	int v[SZ];
	int len;

	BigInt() { clear(); }
	BigInt(string bin) {
		memset(this, 0, sizeof(BigInt));
		BigInt b;
		for (int i = 0; i < bin.size(); i++) {
			if (bin[i] == '1') {
				b.clear();
				b.set(binpow(2, bin.size() - i - 1));
				add(b);
			}
		}
	}

	void clear() {
		len = 0;
		memset(v, 0, sizeof(v));
	}

	void set(long long num) {
		len = 0;
		while (num != 0) {
			v[SZ - (++len)] = num % 10;
			num /= 10;
		}
	}

	void bin() {
		stringstream ss;
		for (int i = SZ - len; i < SZ; ++i)
			ss << v[i];
		bitset<SZ> b(atoi(ss.str().c_str()));
		string s = b.to_string();
		for (int i = 0; i < SZ; ++i) {
			if (s[i] == '1') {
				cout << s.substr(i, SZ - i);
				return;
			}
		}
		cout << 0;
	}
	void dec() {
		for (int i = SZ-len; i < SZ; ++i) {
				cout << v[i];
			}
	}
	void hex() {

	}
	void add(BigInt &b) {
		int carry = 0;
		if (len < b.len)
			len = b.len;
		for (int i = SZ - 1; i >= 0; --i) {
			v[i] += b.v[i] + carry;
			if (v[i] > 9) {
				carry = 1;
				v[i] %= 10;
			}
			else carry = 0;
		}
		if (v[SZ - 1 - len])
			len++;
	}
	void mul(BigInt &b) {
		BigInt result;
		for (int i = 0; i < SZ - 1; ++i) {
			// 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
			// 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
			// 这样做的效果和直接进行上图的运算最后求和是一样的，只是更加简短的一种实现方式
			for (int j = 0; j <= i; ++j) result.v[i] += v[j] * b.v[i - j];

			if (result.v[i] >= 10) {
				result.v[i + 1] += result.v[i] / 10;
				result.v[i] %= 10;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "numeric_limits<long long>().max(): " << endl << numeric_limits<long long>().max() << endl;

	cout << "BigInt Add:" << endl;
	BigInt b("1110");
	BigInt b2("11");
	b.add(b2);
	cout << "len = " << b.len << endl;
	b.dec();
	cout << endl;

	return 0;
}
