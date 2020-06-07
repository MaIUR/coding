//
// Created by lenovo on 2020/6/4.
//
#include<bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    bool flag = true;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            if (flag)flag = false;
            else return false;
        }
    }
    return true;
}

void setGraph(vector<vector<int>> &graph, vector<string> &wordList) {
    for (int i = 0; i < wordList.size() - 1; ++i) {
        for (int j = i + 1; j < wordList.size(); ++j) {
            if (cmp(wordList[i], wordList[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, int> m;
    bool flag = false;
    for (int i = 0; i < wordList.size(); ++i) {
        m[wordList[i]] = i;
        if (endWord == wordList[i]) {
            flag = true;
        }
    }
    if (!flag)return {};
    queue<vector<string>> q;
    vector<vector<string>> ans;
    if (m.find(beginWord) == m.end()) {
        wordList.push_back(beginWord);
        m[beginWord] = wordList.size() - 1;
    }
    vector<vector<int>> graph(wordList.size(), vector<int>());
    setGraph(graph, wordList);
    vector<string> init(1, beginWord);
    q.push(init);
    while (!q.empty()) {
        vector<string> tmp = q.front();
        q.pop();
        string cur = tmp.back();
        if (ans.size() == 0 || ans[0].size() >= tmp.size()) {
            if (cur == endWord) {
                ans.push_back(tmp);
                continue;
            }
            for (int i = 0; i < graph[m[cur]].size(); ++i) {
                tmp.push_back(wordList[graph[m[cur]][i]]);
                q.push(tmp);
                tmp.pop_back();
            }
        } else break;
    }
    return ans;
}

int main() {
    string begin, end;
    vector<string> list;
    while (cin >> begin >> end) {
        int n;
        cin >> n;
        while (n-- > 0) {
            string s;
            cin >> s;
            list.push_back(s);
        }
        vector<vector<string>> ans = findLadders(begin, end, list);
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
