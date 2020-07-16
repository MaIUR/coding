//
// Created by lenovo on 2020/7/16.
//

#include <bits/stdc++.h>

using namespace std;

void siftdown(vector<int> &nums, int root, int size) {
    /**
     * 构造大顶堆的下浮操作
     */
    while (2 * root + 1 < size) { // 当p存在孩子时
        int c1 = 2 * root + 1; // p节点的左孩子
        int c2 = 2 * root + 2; // p节点的右孩子
        int c = (c2 < size && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点
        if (nums[c] > nums[root]) { // 若孩子节点大于父亲节点,交换位置
            swap(nums[c], nums[root]);
        } else {
            break; // 该点满足堆条件,又因为下方已经成堆,所以不必向下建堆
        }
        /**
         * 若此时节点不是最大值,则有可能也小于
         * <以该节点为根的下一个子堆>的孩子节点
         * 所以需要将该节点也进行一次下沉操作
         */
        root = c;
    }
}

void heapSort(vector<int> &nums) {
    // 构建大顶堆,从第一个非叶子节点开始,向左依次进行下沉操作
    for (int i = nums.size() / 2; i >= 0; --i) {
        siftdown(nums, i, nums.size());
    }
    // 进行出堆操作,相当于pop()
    for (int i = nums.size() - 1; i > 0; --i) {
        swap(nums[0], nums[i]); // 出堆(将最大值放置数组尾,堆size - 1)
        siftdown(nums, 0, i); // 将根执行下沉操作
    }
}


struct Node {
    int val;
    bool left;
    Node *lchild;
    Node *rchild;
    Node *parent;

    Node(int _val) : val(_val) { left = true; }
};
//
//Node* root;
//
//void heapSort(vector<int> &nums) {
//
//}

Node *f(vector<int> &nums, int l, int r) {

    Node *cur;
    if (r - l == 2) {
        cur = new Node(nums[(l + r) / 2]);
        cur->lchild = new Node(nums[l]);
        cur->rchild = new Node(nums[r]);
    } else if (r - l == 1) {
        cur = new Node(nums[r]);
        cur->lchild = new Node(nums[l]);
    } else if (r == l) {
        cur = new Node(nums[l]);
    } else {
        int len = r - l + 1, mid =
                len % 2 == 0 ? l + len / 2 : l + (len + 1) / 2;//mid = (l + r) % 2 == 0 ? (l + r) / 2 : (l + r) / 2 + 1;
        cout << "l:" << l << " mid:" << mid << " r:" << r << endl;
        cur = new Node(nums[mid]);
        cur->lchild = f(nums, l, mid - 1);
        cur->rchild = f(nums, mid + 1, r);
    }
    return cur;
}

void leftRoll(Node *root) {
    if (root->left && root->parent != nullptr) {
        root->parent->lchild = root->rchild;
        root->rchild->left = true;
    } else if(!root->left && root->parent != nullptr) {
        root->parent->rchild = root->rchild;
    }
    root->rchild->parent = root->parent;
    Node* tmp = nullptr;
    if (root->rchild->lchild != nullptr) {
        tmp = root->rchild->lchild;
        root->rchild->rchild->left = false;
    }
    root->rchild->lchild = root;
    root->left = true;
    root->parent = root->rchild;
    root->rchild = tmp;
}

void rightRoll(Node* root) {
    if (root->left && root->parent != nullptr) {
        root->parent->lchild = root->lchild;
        root->lchild->left = true;
    } else if(!root->left && root->parent != nullptr) {
        root->parent->rchild = root->lchild;
    }
    root->lchild->parent = root->parent;

    root->lchild->rchild = root;
    root->left = false;
    root->parent = root->lchild;
    root->lchild = nullptr;
}

int adjest(Node *root) {
    if (root == nullptr)return 0;
    int dl = adjest(root->lchild), dr = adjest(root->rchild);
    if (dr > dl) {
        leftRoll(root);
    } else if (dl - dr > 1) {
        rightRoll(root);
    }
    return 1 + max(adjest(root->lchild), adjest(root->rchild));
}

void build(Node *root, int n) {
    Node *cur = root, *p;
    bool left = true;
    while (cur != nullptr) {
        if (n >= cur->val) {
            p = cur;
            cur = cur->rchild;
            left = false;
        } else {
            p = cur;
            cur = cur->lchild;
            left = true;
        }
    }
    cur = new Node(n);
    cur->parent = p;
    cur->left = left;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    heapSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    //Node *root = f(nums, 0, nums.size() - 1);
    Node *root = new Node(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        build(root, nums[i]);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        if (tmp->lchild != NULL) {
            q.push(tmp->lchild);
        }
        if (tmp->rchild != NULL) {
            q.push(tmp->rchild);
        }
    }
    cout << endl;
    return 0;
}

