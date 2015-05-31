#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include <queue>

template<class T>
class TreeNode {
public:
    TreeNode() {
        leftChild = NULL;
        rightChild = NULL;
    }
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template<class T>
class BinaryTree {
public:
    void inOrder();//中序遍历
    void inOrder(TreeNode<T>*currentNode);
    void preOrder();//前序遍历
    void preOrder(TreeNode<T>*currntNode);
    void postOrder();//后续遍历
    void postOrder(TreeNode<T>*currntNode);
    void levelOrder();//层序遍历
    void visit(TreeNode<T>*currentNode);
public:
    TreeNode<T> *root;
};

template<class T>
void BinaryTree<T>::visit(TreeNode<T> *currentNode) {
    std::cout << currentNode->data;
}

template<class T>
void BinaryTree<T>::inOrder() {
    inOrder(root);
}

template<class T>
void BinaryTree<T>::inOrder(TreeNode<T>*currentNode) {
    if (currentNode) {
        inOrder(currentNode->leftChild);
        visit(currentNode);//显示
        inOrder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::preOrder() {
    preOrder(root);
}

template<class T>
void BinaryTree<T>::preOrder(TreeNode<T>*currntNode) {
    if (currntNode) {
        visit(currntNode);
        preOrder(currntNode->leftChild);
        preOrder(currntNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::postOrder() {
    postOrder(root);
}

template<class T>
void BinaryTree<T>::postOrder(TreeNode<T>*currntNode) {
    if (currntNode) {
        postOrder(currntNode->leftChild);
        postOrder(currntNode->rightChild);
        visit(currntNode);
    }
}

template<class T>
void BinaryTree<T>::levelOrder() {
    std::queue<TreeNode<T>*>q;
    TreeNode<T>*currectNode = root;
    while (currectNode) {
        visit(currectNode);
        if (currectNode->leftChild) {
            q.push(currectNode->leftChild);
        }
        if (currectNode->rightChild) {
            q.push(currectNode->rightChild);
        }
        if (q.empty()) {
            return;
        }
        currectNode = q.front();
        q.pop();
    }
}

#endif