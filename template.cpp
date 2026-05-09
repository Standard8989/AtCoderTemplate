#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;

constexpr bool is_debug = true;
static int ok = 0;

namespace mytools { // vectorのオーバーロード
#define rep(i, n) for (ll i = 0; i < ((ll)n); i++)
#define repi(n) for (ll i = 0; i < ((ll)n); i++)
#define debug(x)                                                                                                                 \
    if (is_debug) {                                                                                                              \
        cerr << #x << ": " << (x) << endl;                                                                                       \
    }
#define check()                                                                                                                  \
    if (is_debug) {                                                                                                              \
        cerr << "OK" << ok << endl;                                                                                              \
    }
#define getll(x)                                                                                                                 \
    ll x;                                                                                                                        \
    cin >> x;
#define getllv(v, n)                                                                                                             \
    llv v(n);                                                                                                                    \
    cin >> v;

    using ll = long long;
    using llv = vector<ll>;
    using Graph = vector<vector<ll>>;
    using Matrix = vector<vector<char>>;
    using Pt = pair<int, int>;
    constexpr int dh4[4] = {-1, 0, 1, 0};
    constexpr int dw4[4] = {0, 1, 0, -1};
    constexpr Pt dhw4[4] = {
        {dh4[0], dw4[0]},
        {dh4[1], dw4[1]},
        {dh4[2], dw4[2]},
        {dh4[3], dw4[3]},
    };
    constexpr char URDL[4] = {'U', 'R', 'D', 'L'};

    template <typename T> istream &operator>>(istream &is, vector<T> &v) {
        for (T &in : v)
            is >> in;
        return is;
    }
    template <> istream &operator>> <char>(istream &is, vector<char> &v) {
        string temp;
        cin >> temp;
        v.assign(temp.size(), ' ');
        rep(i, temp.size()) v[i] = temp[i];
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << (i + 1 != (int)v.size() ? " " : "");
        }
        return os;
    }
    template <> ostream &operator<< <char>(ostream &os, const vector<char> &v) {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i];
        }
        return os;
    }

    // vector<vector>のオーバーロード
    template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << "\t\n";
        }
        os.flush();
        return os;
    }
    template <> ostream &operator<< <char>(ostream &os, const vector<vector<char>> &v) {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i];
            if (i + 1 != (int)v.size()) {
                os << '\n';
            }
            else {
                os << endl;
            }
        }
        return os;
    }

    // pairのオーバーロード
    template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) {
        is >> p.first >> p.second;
        return is;
    }
    template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
        os << '(' << p.first << ", " << p.second << ')';
        return os;
    }

    // mapのオーバーロード
    template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp) {
        for (auto &[key, val] : mp) {
            os << '[' << key << ": " << val << "] ";
        }
        os << endl;
        return os;
    }

    // set, multisetのオーバーロード
    template <typename T> ostream &operator<<(ostream &os, const set<T> &st) {
        auto itr = st.begin();
        for (int i = 0; i < (int)st.size(); i++) {
            os << *itr << (i + 1 != (int)st.size() ? " " : "");
            itr++;
        }
        return os;
    }
    template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st) {
        auto itr = st.begin();
        for (int i = 0; i < (int)st.size(); i++) {
            os << *itr << (i + 1 != (int)st.size() ? " " : "");
            itr++;
        }
        return os;
    }

    // listのオーバーロード
    template <typename T> istream &operator>>(istream &is, list<T> &v) {
        for (T &in : v)
            is >> in;
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const list<T> &lt) {
        auto itr = lt.begin();
        for (int i = 0; i < (int)lt.size(); i++) {
            os << *itr << (i + 1 != (int)lt.size() ? " " : "");
            itr++;
        }
        return os;
    }

    // dequeのオーバーロード
    template <typename T> istream &operator>>(istream &is, deque<T> &v) {
        for (T &in : v)
            is >> in;
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const deque<T> &dq) {
        auto itr = dq.begin();
        for (int i = 0; i < (int)dq.size(); i++) {
            os << *itr << (i + 1 != (int)dq.size() ? " " : "");
            itr++;
        }
        return os;
    }

    // 累乗
    constexpr long long mypow(long long x, long long n) {
        if (n == 0)
            return 1;
        long long val = mypow(x, n / 2);
        val *= val;
        if (n % 2 == 1)
            val *= x;
        return val;
    }

    // 範囲内にあるか
    constexpr bool is_in(int x, int left, int right) {
        return x >= left && x < right;
    }

    // 回答
    constexpr void yes_or_no(bool ans) {
        cout << (ans ? "Yes" : "No") << endl;
    }
} // namespace mytools
using namespace mytools;

int main() {

    return 0;
}