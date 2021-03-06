#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <stdio.h>

template<class T>
class Element {
public:
    T key;
};

template<class T>class BinarySerchTree;

template<class T>
class BstNode {
public:
    friend class BinarySerchTree < T > ;
public:
    Element<T> data;
    BstNode<T> *leftChild;
    BstNode<T> *rightChild;
    void display(int i);//显示当前节点
};

template<class T>
class BinarySerchTree {
public:
    BinarySerchTree(BstNode<T> *init = 0) {
        root = init;
    }
    bool insert(const Element<T>&x);
    BstNode<T> *search(const Element<T>&x);//查找
    BstNode<T> *search(BstNode<T>*treeNode, const Element<T>&x);
    BstNode<T> *iterSearch(const Element<T>&x);//迭代查找

    bool deleteNode(BstNode<T>*currentNode);
    bool deleteBST(const Element<T>&x);
    bool deleteBST(BstNode<T>*currentNode, const Element<T>&x);

    void display();

    void visit(BstNode<T>*currentNode);
    void inOrder();//中序遍历
    void inOrder(BstNode<T>*currentNode);
    void preOrder();//前序遍历
    void preOrder(BstNode<T>*currntNode);
    void postOrder();//后续遍历
    void postOrder(BstNode<T>*currntNode);
    void levelOrder();//层序遍历
private:
    BstNode<T> *root;
};

template<class T>
void BinarySerchTree<T>::display() {
    std::cout << "\n";
    if (root) {
        root->display(1);
    }
    else {
        std::cout << "空树" << std::endl;
    }
}

template<class T>
void BstNode<T>::display(int i) {
    std::cout << "Position:" << i << "  data.key=" << data.key << "\n";
    if (leftChild) {
        leftChild->display(2 * i);
    }
    if (rightChild) {
        rightChild->display(2 * i + 1);
    }
}

template<class T>
bool BinarySerchTree<T>::insert(const Element<T>&x) {
    BstNode<T> *p = root;
    BstNode<T> *q = NULL;//指向p的父节点
    //插入前先查找
    while (p) {
        q = p;
        if (x.key == p->data.key) {
            return false;//重复，失败
        }
        if (x.key < p->data.key) {//左边
            p = p->leftChild;
        }
        else {//右边
            p = p->rightChild;
        }
    }
    //找到的位置就是q
    p = new BstNode < T > ;
    p->leftChild = p->rightChild = 0;
    p->data = x;

    if (!root) {
        root = p;
    }
    else if (x.key < q->data.key) {
        q->leftChild = p;
    }
    else {
        q->rightChild = p;
    }

    return true;
}

template<class T>
BstNode<T> *BinarySerchTree<T>::search(const Element<T>&x) {
    return search(root, x);
}

template<class T>
BstNode<T> *BinarySerchTree<T>::search(BstNode<T>*treeNode, const Element<T>&x) {
    if (!treeNode) {
        return 0;
    }
    if (x.key == treeNode->data.key) {
        return treeNode;
    }
    if (x.key < treeNode->data.key) {
        return search(treeNode->leftChild, x);
    }
    return search(treeNode->rightChild, x);
}

template<class T>
BstNode<T> *BinarySerchTree<T>::iterSearch(const Element<T>&x) {
    for (BstNode<T>*t = root; t;) {
        if (x.key == t->data.key) {
            return t;
        }
        if (x.key < t->data.key) {
            t = t->leftChild;
        }
        else {
            t = t->rightChild;
        }
    }
    return 0;
}

template<class T>
bool BinarySerchTree<T>::deleteNode(BstNode<T>*currecntNode) {
    BstNode<T>*q, *s;
    if (currecntNode->rightChild == NULL) {//右子树为空重新连接他的左子树
        q = currecntNode;
        currecntNode = currecntNode->leftChild;
        delete q;
        q = NULL;
    }
    else if (currecntNode->leftChild == NULL) {//连接他的右子树
        q = currecntNode;
        currecntNode = currecntNode->rightChild;
        delete q;
        q = NULL;
    }
    else {
        q = currecntNode;
        s = currecntNode->leftChild;
        while (s->rightChild) {//转左，然后向右到尽头（找待删结点的前驱）
            q = s;
            s = s->rightChild;
        }
        currecntNode->data = s->data;//s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值
        if (q != currecntNode) {
            q->rightChild = s->leftChild;//重连q的右子树
        }
        else {
            q->leftChild = s->leftChild;//重连q的左子树
        }
        delete s;
        s = NULL;
    }
    return true;
}

template<class T>
bool BinarySerchTree<T>::deleteBST(const Element<T>&x) {
    return deleteBST(root,x);
}

template<class T>
bool BinarySerchTree<T>::deleteBST(BstNode<T>*currentNode, const Element<T>&x) {
    if (!currentNode) {
        return false;
    }
    else {
        if (x.key == currentNode->data.key) {
            return deleteNode(currentNode);
        }
        else if (x.key < currentNode->data.key) {
            return deleteBST(currentNode->leftChild, x);
        }
        else {
            return deleteBST(currentNode->rightChild, x);
        }
    }
}


template<class T>
void BinarySerchTree<T>::inOrder() {
    inOrder(root);
}

template<class T>
void BinarySerchTree<T>::inOrder(BstNode<T>*currentNode) {
    if (currentNode) {
        inOrder(currentNode->leftChild);
        visit(currentNode);
        inOrder(currentNode->rightChild);
    }
}

template<class T>
void BinarySerchTree<T>::preOrder() {
    preOrder(root);
}

template<class T>
void BinarySerchTree<T>::preOrder(BstNode<T>*currntNode) {
    if (currntNode) {
        visit(currntNode);
        preOrder(currntNode->leftChild);
        preOrder(currntNode->rightChild);
    }
}

template<class T>
void BinarySerchTree<T>::postOrder() {
    postOrder(root);
}//后续遍历

template<class T>
void BinarySerchTree<T>::postOrder(BstNode<T>*currntNode) {
    if (currntNode) {
        postOrder(currntNode->leftChild);
        postOrder(currntNode->rightChild);
        visit(currntNode);
    }
}
template<class T>
void BinarySerchTree<T>::levelOrder() {
    std::queue<BstNode<T>*>q;
    BstNode<T>*currectNode = root;
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
}//层序遍历

template<class T>
void BinarySerchTree<T>::visit(BstNode<T>*currentNode) {
    std::cout << "  " << currentNode->data.key;
}
#endif