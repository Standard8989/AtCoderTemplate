#include </home/standard/.config/ackit/template.cpp>
#include <bits/stdc++.h>
using namespace std;

/************************/
/******深さ優先探索******/
/************************/
struct DFS {
    vector<bool> seen;
    const Graph &graph;
    stack<ll> task;
    void search(ll start_point) {
        task.emplace(start_point);

        while (!task.empty()) {
            start_point = task.top();
            task.pop();

            if (seen[start_point]) {
                continue;
            }

            seen[start_point] = true;

            for (ll next_point : graph[start_point]) {
                if (!seen[next_point]) {
                    task.emplace(next_point);
                }
            }
        }
    }

    DFS(size_t n, const Graph &graph) : seen(n, false), graph(graph), task() {
    }
};

struct DFS_Matrix {
    DFS_Matrix(const Matrix &matrix)
        : height(matrix.size()), width(matrix[0].size()), seen(height, vector<bool>(width, false)), matrix(matrix), task() {
    }

    size_t height, width;
    vector<vector<bool>> seen;
    const Matrix &matrix;
    stack<Point> task;
    void search(Point start_point) {
        Point looking_point;
        task.emplace(start_point);

        while (!task.empty()) {
            start_point = task.top();
            task.pop();

            if (seen[start_point.first][start_point.second]) {
                continue;
            }

            seen[start_point.first][start_point.second] = true;

            for (int i = 0; i < 4; i++) {
                looking_point = start_point + dxy4[i];

                if (is_in(looking_point.first, 0, height) && is_in(looking_point.second, 0, width) &&
                    !seen[looking_point.first][looking_point.second] &&
                    matrix[looking_point.first][looking_point.second] == '.') {
                    task.emplace(looking_point);
                }
            }
        }
    }
};

/************************/
/******深さ優先探索******/
/************************/
struct BFS {
    vector<bool> seen;
    const Graph &graph;
    queue<ll> task;

    void search(ll v) {
        task.emplace(v);

        while (!task.empty()) {
            v = task.front();
            task.pop();

            if (seen[v]) {
                continue;
            }

            seen[v] = true;

            for (auto next_v : graph[v]) {
                if (!seen[next_v]) {
                    task.emplace(next_v);
                }
            }
        }
    }

    BFS(size_t n, const Graph &graph) : seen(n, false), graph(graph), task() {
    }
};

struct BFS_Matrix {
    size_t height, width;
    vector<vector<bool>> seen;
    const Matrix &matrix;
    queue<Point> task;

    void search(Point start_point) {
        Point looking_point;
        task.emplace(start_point);

        while (!task.empty()) {
            start_point = task.front();
            task.pop();

            if (seen[start_point.first][start_point.second])
                continue;

            seen[start_point.first][start_point.second] = true;

            for (int i = 0; i < 4; i++) {
                looking_point = start_point + dxy4[i];

                if (is_in(looking_point.first, 0, height) && is_in(looking_point.second, 0, width) &&
                    !seen[looking_point.first][looking_point.second]) {
                    task.emplace(looking_point);
                }
            }
        }
    }

    BFS_Matrix(const Matrix &matrix)
        : height(matrix.size()), width(matrix[0].size()), seen(height, vector<bool>(width, false)), matrix(matrix), task() {
    }
};

/***********************/
/*******UnionFind*******/
/***********************/
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { // 最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x);      // xの根をrx
        int ry = root(y);      // yの根をry
        if (rx == ry)
            return;   // xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};