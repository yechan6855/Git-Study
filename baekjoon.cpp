#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class BigInteger {
private:
    vector<long long> digits;
    static const long long BASE = 100000000000000LL; // 10^14

public:
    BigInteger(long long i = 0) {
        digits.push_back(i);
    }

    void multiply(int n) {
        long long carry = 0;
        for (size_t i = 0; i < digits.size() || carry > 0; ++i) {
            if (i == digits.size()) {
                digits.push_back(0);
            }
            long long cur = digits[i] * (long long)n + carry;
            digits[i] = cur % BASE;
            carry = cur / BASE;
        }
    }

    void print() {
        cout << (digits.empty() ? 0 : digits.back());
        for (int i = (int)digits.size() - 2; i >= 0; --i) {
            cout << setw(14) << setfill('0') << digits[i];
        }
        cout << endl;
    }
};

void factorial(int n) {
    BigInteger result(1);
    for (int i = 2; i <= n; ++i) {
        result.multiply(i);
    }
    result.print();
}

int main() {
    int n;
    cin>>n;
    factorial(n);
    return 0;
}