#include "BinaryTree.h"

int main() {
    BinaryTree<char> tree;
    TreeNode<char> add, sub, mul, div, a, b, c, d, e;

    add.data = '+';
    sub.data = '-';
    mul.data = '*';
    div.data = '/';
    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    e.data = 'E';

    tree.root = &add;
    add.leftChild = &sub;
    add.rightChild = &e;
    sub.leftChild = &mul;
    sub.rightChild = &d;
    mul.leftChild = &div;
    mul.rightChild = &c;
    div.leftChild = &a;
    div.rightChild = &b;

    
    tree.inOrder();
    std::cout << "中序遍历" << std::endl;

    
    tree.preOrder();
    std::cout << "前序遍历" << std::endl;


    tree.postOrder();
    std::cout << "后续遍历" << std::endl;


    tree.levelOrder();
    std::cout << "层序遍历" << std::endl;

    return 0;
}