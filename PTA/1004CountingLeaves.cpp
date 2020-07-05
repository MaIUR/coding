//
// Created by lenovo on 2020/6/29.
//

/*
 * A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
 *
 * Input Specification:
 * Each input file contains one test case. Each case starts with a line containing 0<N<100, the number of nodes in a tree
 * and M (<N), the number of non-leaf nodes. Then M lines follow, each in the format:
 * ID K ID[1] ID[2] ... ID[K], where ID is a two-digit number representing a given non-leaf node,
 * K is the number of its children, followed by a sequence of two-digit ID's of its children.
 * For the sake of simplicity, let us fix the root ID to be 01.
 * The input ends with N being 0. That case must NOT be processed.
 *
 * Output Specification:
 * For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root.
 * The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
 */

#include <bits/stdc++.h>

using namespace std;

//struct Node{
//    int id, depth;
//    bool leaf;
//    Node(int _id, int _depth)
//};
struct Node {
    int id, nchild;
    vector<int> child;

    Node(int _id, int _nchild) : id(_id), nchild(_nchild) {}
};

unordered_map<int, pair<int, bool>> mp; //<depth,isLeaf>
queue<Node> q;
int leaf[100]; //之前用了vector，没有memset，可能会使一个文件中多个用例leaf叠加，没有清零
int N, M, dt = 0; //dt 树的深度
int parent, child, d, tmp;

int main() {
    while (cin >> N) {
        if (N == 0) break;
        memset(leaf, 0, sizeof(leaf));
        cin >> M;
        while (M-- > 0) {
            cin >> parent >> child;
            if (parent == 1) {
                mp[parent] = pair<int, bool>(0, child != 0);
                d = 0;
                dt = child != 0 ? 1 : 0;
            } else {
                if (mp.find(parent) == mp.end()) {
                    Node n = Node(parent, child);
                    for (int i = 0; i < child; ++i) {
                        cin >> tmp;
                        n.child.push_back(tmp);
                    }
                    q.push(n);
                    continue;
                }
                mp[parent].second = true; //parent一定是非叶子节点，不然不会列出来
                d = mp[parent].first;
                dt = max(dt, d + 1);
            }
            for (int i = 0; i < child; ++i) {
                cin >> tmp;
                mp[tmp] = pair<int, bool>(d + 1, false);
            }
        }
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            if (mp.find(n.id) == mp.end()) {
                q.push(n);
                continue;
            }
            mp[n.id].second = true;
            d = mp[n.id].first;
            dt = max(dt, d + 1);
            for (int i = 0; i < n.nchild; ++i) {
                mp[n.child[i]] = pair<int, bool>(d + 1, false);
            }
        }
        for (auto e : mp) {
            if (!e.second.second) {
                leaf[e.second.first]++;
            }
        }
        cout << leaf[0];
        for (int i = 1; i <= dt; ++i) {
            cout << " " << leaf[i];
        }
        cout << endl;
    }
    return 0;
}