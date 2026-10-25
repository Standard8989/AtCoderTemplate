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
#define debug(x)                                                               \
    if (is_debug) {                                                            \
        cerr << #x << ": " << (x) << '\n';                                     \
    }
#define check()                                                                \
    if (is_debug) {                                                            \
        cerr << "OK" << ok << '\n';                                            \
    }
#define getll(x)                                                               \
    ll x;                                                                      \
    cin >> x;
#define getllv(v, n)                                                           \
    llv v(n);                                                                  \
    cin >> v;

    using ll = long long;
    using llv = vector<ll>;
    using llvv = vector<vector<ll>>;
    using Graph = vector<vector<ll>>;
    using Matrix = vector<vector<char>>;
    using Point = pair<int, int>;
    
    constexpr int dx4[4] = {-1, 0, 1, 0};
    constexpr int dy4[4] = {0, 1, 0, -1};
    constexpr Point dxy4[4] = {
        {dx4[0], dy4[0]}, {dx4[1], dy4[1]}, 
        {dx4[2], dy4[2]}, {dx4[3], dy4[3]}
    };
    constexpr char URDL[4] = {'U', 'R', 'D', 'L'};

    constexpr int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    constexpr int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    constexpr Point dxy8[8] = {
        {dx8[0], dy8[0]}, {dx8[1], dy8[1]}, {dx8[2], dy8[2]}, {dx8[3], dy8[3]},
        {dx8[4], dy8[4]}, {dx8[5], dy8[5]}, {dx8[6], dy8[6]}, {dx8[7], dy8[7]}
    };

    // pairの四則演算 (T, U で異なる型同士も計算できるように修正！)
    template <typename T, typename U> pair<T, U> operator+(pair<T, U> lhs, const pair<T, U> &rhs);
    template <typename T, typename U> pair<T, U> operator-(pair<T, U> lhs, const pair<T, U> &rhs);
    template <typename T, typename U> pair<T, U> operator+=(pair<T, U> &lhs, const pair<T, U> &rhs);
    template <typename T, typename U> pair<T, U> operator-=(pair<T, U> &lhs, const pair<T, U> &rhs);

    // vectorの入出力
    template <typename T> istream &operator>>(istream &is, vector<T> &v);
    template <> istream &operator>> <char>(istream &is, vector<char> &v);
    template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
    template <> ostream &operator<< <char>(ostream &os, const vector<char> &v);

    // vector<vector>の入出力 (重複してたプロトタイプ宣言を削除！)
    template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v);
    template <> ostream &operator<< <char>(ostream &os, const vector<vector<char>> &v);

    // mapの出力
    template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp);

    // setの出力
    template <typename T> ostream &operator<<(ostream &os, const set<T> &st);

    // multisetの出力
    template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st);

    // listの入出力
    template <typename T> istream &operator>>(istream &is, list<T> &l);
    template <typename T> ostream &operator<<(ostream &os, const list<T> &l);

    // dequeの入出力
    template <typename T> istream &operator>>(istream &is, deque<T> &dq);
    template <typename T> ostream &operator<<(ostream &os, const deque<T> &dq);

    // pairの入出力
    template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p);
    template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p); // 戻り値を ostream & に修正！

    // x^nを計算
    constexpr int64_t mypow(int64_t x, int64_t n);
    // xが[left, right)に入っているか
    constexpr bool is_in(int x, int left, int right);
    // boolを入力してYesかNoで回答
    void yes_or_no(bool ans);
    // 最小値を比較して更新
    template <typename T, typename U> bool chmin(T &a, const U &b);
    // 最大値を比較して更新
    template <typename T, typename U> bool chmax(T &a, const U &b);

    //
    // 実装
    //

    // pairの四則演算
    template <typename T, typename U> pair<T, U> operator+(pair<T, U> lhs, const pair<T, U> &rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
    template <typename T, typename U> pair<T, U> operator-(pair<T, U> lhs, const pair<T, U> &rhs) {
        lhs.first -= rhs.first;
        lhs.second -= rhs.second;
        return lhs;
    }
    template <typename T, typename U> pair<T, U> operator+=(pair<T, U> &lhs, const pair<T, U> &rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
    template <typename T, typename U> pair<T, U> operator-=(pair<T, U> &lhs, const pair<T, U> &rhs) {
        lhs.first -= rhs.first;
        lhs.second -= rhs.second;
        return lhs;
    }

    // vectorの入出力
    template <typename T> istream &operator>>(istream &is, vector<T> &v) {
        for (auto &in : v) is >> in; // 範囲forに変更
        return is;
    }
    template <> istream &operator>> <char>(istream &is, vector<char> &v) {
        string temp;
        is >> temp; // cin じゃなくてちゃんと is から読み込むように修正！
        v.assign(temp.begin(), temp.end()); // 1文字ずつループせず一発コピー！
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
        bool first = true;
        for (const auto &e : v) {
            if (!first) os << " ";
            os << e;
            first = false;
        }
        return os;
    }
    template <> ostream &operator<< <char>(ostream &os, const vector<char> &v) {
        for (const auto &e : v) os << e; // 範囲forに変更
        return os;
    }

    // vector<vector>の入出力
    template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
        bool first = true;
        for (const auto &row : v) {
            if (!first) os << '\n';
            os << row;
            first = false;
        }
        return os;
    }
    template <> ostream &operator<< <char>(ostream &os, const vector<vector<char>> &v) {
        bool first = true;
        for (const auto &row : v) {
            if (!first) os << '\n';
            os << row;
            first = false;
        }
        return os;
    }

    // mapの出力
    template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp) {
        for (const auto &[key, val] : mp) {
            os << '[' << key << ": " << val << "] ";
        }
        os << '\n';
        return os;
    }

    // setの出力
    template <typename T> ostream &operator<<(ostream &os, const set<T> &st) {
        bool first = true;
        for (const auto &e : st) {
            if (!first) os << " ";
            os << e;
            first = false;
        }
        return os;
    }

    // multisetの出力
    template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st) {
        bool first = true;
        for (const auto &e : st) {
            if (!first) os << " ";
            os << e;
            first = false;
        }
        return os;
    }

    // listの入出力
    template <typename T> istream &operator>>(istream &is, list<T> &l) {
        for (auto &in : l) is >> in;
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const list<T> &l) {
        bool first = true;
        for (const auto &e : l) {
            if (!first) os << " ";
            os << e;
            first = false;
        }
        return os;
    }

    // dequeの入出力
    template <typename T> istream &operator>>(istream &is, deque<T> &dq) {
        for (auto &in : dq) is >> in;
        return is;
    }
    template <typename T> ostream &operator<<(ostream &os, const deque<T> &dq) {
        bool first = true;
        for (const auto &e : dq) {
            if (!first) os << " ";
            os << e;
            first = false;
        }
        return os;
    }

    // pairの入出力
    template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) {
        is >> p.first >> p.second;
        return is;
    }
    template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
        os << '(' << p.first << ", " << p.second << ')';
        return os;
    }

    // x^nを計算
    constexpr int64_t mypow(int64_t x, int64_t n) {
        if (n == 0) return 1;
        int64_t val = mypow(x, n / 2);
        val *= val;
        if (n % 2 == 1) val *= x;
        return val;
    }

    // xが[left, right)に入っているか
    constexpr bool is_in(int x, int left, int right) {
        return x >= left && x < right;
    }

    // boolを入力してYesかNoで回答
    void yes_or_no(bool ans) {
        cout << (ans ? "Yes\n" : "No\n");
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