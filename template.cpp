#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;

constexpr bool is_debug = true;
[[maybe_unused]]
static int ok = 0;

namespace mytools { // vectorのオーバーロード
#define rep(i, n) for (ll i = 0; i < ((ll)n); i++)
#define repi(n) for (ll i = 0; i < ((ll)n); i++)
#define repj(n) for (ll j = 0; j < ((ll)n); j++)
#define rep2(i, begin, end) for (ll i = begin; i < end; i++)
#define debug(x)                                                                                   \
    if (is_debug) {                                                                                \
        cerr << #x << ": " << (x) << endl;                                                         \
    }
#define check()                                                                                    \
    if (is_debug) {                                                                                \
        cerr << "OK" << ok << endl;                                                                \
    }
#define getll(x)                                                                                   \
    ll x;                                                                                          \
    cin >> x;
#define getllv(v, n)                                                                               \
    llv v(n);                                                                                      \
    cin >> v;

    using ll = long long;
    using llv = vector<ll>;
    using Graph = vector<vector<ll>>;
    using Matrix = vector<vector<char>>;
    using Point = pair<int, int>;
    constexpr int dx4[4] = {-1, 0, 1, 0};
    constexpr int dy4[4] = {0, 1, 0, -1};
    constexpr Point dxy4[4] = {
        {dx4[0], dy4[0]},
        {dx4[1], dy4[1]},
        {dx4[2], dy4[2]},
        {dx4[3], dy4[3]},
    };
    constexpr char URDL[4] = {'U', 'R', 'D', 'L'};

    constexpr int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    constexpr int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    constexpr Point dxy8[8] = {
        {dx8[0], dy8[0]}, {dx8[1], dy8[1]}, {dx8[2], dy8[2]}, {dx8[3], dy8[3]},
        {dx8[4], dy8[4]}, {dx8[5], dy8[5]}, {dx8[6], dy8[6]}, {dx8[7], dy8[7]},
    };

    // pairの四則演算
    template <typename T> pair<T, T> operator+(pair<T, T> lhs, pair<T, T> rhs);
    template <typename T> pair<T, T> operator-(pair<T, T> lhs, pair<T, T> rhs);
    template <typename T> pair<T, T> operator+=(pair<T, T> &lhs, pair<T, T> rhs);
    template <typename T> pair<T, T> operator-=(pair<T, T> &lhs, pair<T, T> rhs);

    // vectorの入出力
    template <typename T> istream &operator>>(istream &is, vector<T> &v);
    template <> istream &operator>> <char>(istream &is, vector<char> &v);
    template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
    template <> ostream &operator<< <char>(ostream &os, const vector<char> &v);

    // vector<vector<>>
    template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v);
    template <> ostream &operator<< <char>(ostream &os, const vector<vector<char>> &v);

    template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v);
    template <> ostream &operator<< <char>(ostream &os, const vector<vector<char>> &v);

    constexpr bool is_in(int x, int left, int right);

    template <typename T> pair<T, T> operator+(pair<T, T> lhs, pair<T, T> rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
    template <typename T> pair<T, T> operator-(pair<T, T> lhs, pair<T, T> rhs) {
        lhs.first -= rhs.first;
        lhs.second -= rhs.second;
        return lhs;
    }
    template <typename T> pair<T, T> operator+=(pair<T, T> &lhs, pair<T, T> rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
    template <typename T> pair<T, T> operator-=(pair<T, T> &lhs, pair<T, T> rhs) {
        lhs.first -= rhs.first;
        lhs.second -= rhs.second;
        return lhs;
    }

    template <typename T> istream &operator>>(istream &is, vector<T> &v) {
        for (T &in : v)
            is >> in;
        return is;
    }
    template <> istream &operator>> <char>(istream &is, vector<char> &v) {
        string temp;
        cin >> temp;
        v.assign(temp.size(), ' ');
        rep (i, temp.size())
            v[i] = temp[i];
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
    constexpr int64_t mypow(int64_t x, int64_t n) {
        if (n == 0)
            return 1;
        int64_t val = mypow(x, n / 2);
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
    void yes_or_no(bool ans) {
        cout << (ans ? "Yes" : "No") << endl;
    }

    // 最小値を比較して更新
    template <typename T, typename U> bool chmin(T &a, const U &b) {
        if (a > b) {
            a = b;
            return true;
        }
        return false;
    }
    // 最大値を比較して更新
    template <typename T, typename U> bool chmax(T &a, const U &b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
} // namespace mytools
using namespace mytools;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}