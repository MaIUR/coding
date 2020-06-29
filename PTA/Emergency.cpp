//
// Created by lenovo on 2020/6/18.
//

/*
 * As an emergency rescue team leader of a city, you are given a special map of your country.
 * The map shows several scattered cities connected by some roads.
 * Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map.
 * When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible,
 * and at the mean time, call up as many hands on the way as possible.
 *
 * Input Specification:
 * Each input file contains one test case.
 * For each test case, the first line contains 4 positive integers:
 * N (≤500) - the number of cities (and the cities are numbered from 0 to N−1),
 * M - the number of roads,
 * C1 and C2 - the cities that you are currently in and that you must save, respectively.
 * The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city.
 * Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively.
 * It is guaranteed that there exists at least one path from C1 to C2.
 *
 * Output Specification:
 * For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2,
 * and the maximum amount of rescue teams you can possibly gather.
 * All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, C1, C2, shortest = INT_MAX, maximum = 0, num = 0;
vector<int> teams;

struct Node {
    int city, len, te;
    vector<bool> vis;

    Node(int _city, int _len, int _te) : city(_city), len(_len), te(_te) {
        vis = vector<bool>(500, false);
    }
};

int main() {
    cin >> N >> M >> C1 >> C2;
    //<vector<int>> roads(N, vector<int>(N, INT_MAX)); //不要邻接矩阵，节点太多路太少浪费空间时间
    vector<vector<pair<int, int>>> roads(N, vector<pair<int, int>>());
    queue<Node> q;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        teams.push_back(tmp);
    }
    for (int i = 0; i < M; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        //roads[x][y] = roads[y][x] = l;
        roads[x].push_back(pair<int, int>(y, l));
        roads[y].push_back(pair<int, int>(x, l));
    }
    q.push(Node(C1, 0, teams[C1]));

    while (!q.empty()) {
        int count = q.size();
        //cout << "count: " << count;
        while (count-- > 0) {
            //int cur_city = q.front().city, cur_len = q.front().len, cur_te = q.front().te;
            Node cur = q.front();
            q.pop();
            if (cur.city == C2) {
                if (cur.len < shortest) {
                    shortest = cur.len;
                    maximum = cur.te;
                    num = 1;
                } else if (cur.len == shortest){
                    maximum = max(maximum, cur.te);
                    num++;
                }
                continue;
            }
            for (int i = 0; i < roads[cur.city].size(); ++i) {
                int next_city = roads[cur.city][i].first, next_len = cur.len + roads[cur.city][i].second;
                if (!cur.vis[next_city] && next_len <= shortest) {
                    Node tmp = Node(next_city, next_len, cur.te + teams[next_city]);
                    tmp.vis = cur.vis;
                    tmp.vis[cur.city] = true;
                    q.push(tmp);
                }
            }

        }

    }
    cout << num << " " << maximum << endl;
    return 0;
}