/*
练习 13.28：给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
*/

#include <string>

using namespace std;

class TreeNode {
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
    
public:
    TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode& rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode& operator= (const TreeNode& rhs)
    {
        ++*(rhs.count);

        if (--*count == 0)
        {
            if (left)
                delete left;
            if (right)
                delete right;
        }

        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;

        return *this;
    }
};

class BinStrTree {
private:
    TreeNode* root;

public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree& rhs) : root(new TreeNode(*rhs.root)) { }
    BinStrTree& operator= (const BinStrTree& rhs)
    {
        TreeNode* new_root = new TreeNode(*rhs.root);
        delete root;
        root = new_root;

        return *this;
    }
};