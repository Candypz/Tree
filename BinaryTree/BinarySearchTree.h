#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>


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
    void display(int i);//��ʾ��ǰ�ڵ�
};

template<class T>
class BinarySerchTree {
public:
    BinarySerchTree(BstNode<T> *init = 0) {
        root = init;
    }
    bool insert(const Element<T>&x);
    BstNode<T> *search(const Element<T>&x);//����
    BstNode<T> *search(BstNode<T>*treeNode, const Element<T>&x);
    BstNode<T> *iterSearch(const Element<T>&x);//��������
    bool deleteNode(const Element<T>&x);
    void display();

    void visit(BstNode<T>*currentNode);
    void inOrder();//�������
    void inOrder(BstNode<T>*currentNode);
    void preOrder();//ǰ�����
    void preOrder(BstNode<T>*currntNode);
    void postOrder();//��������
    void postOrder(BstNode<T>*currntNode);
    void levelOrder();//�������
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
        std::cout << "����" << std::endl;
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
    BstNode<T> *q = 0;//ָ��p�ĸ��ڵ�
    //����ǰ�Ȳ���
    while (p) {
        q = p;
        if (x.key == p->data.key) {
            return false;//�ظ���ʧ��
        }
        if (x.key < p->data.key) {//���
            p = p->leftChild;
        }
        else {//�ұ�
            p = p->rightChild;
        }
    }
    //�ҵ���λ�þ���q
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
bool BinarySerchTree<T>::deleteNode(const Element<T>&x) {
    if (!search(x)) {
        return false;
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
}//��������

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
}//�������

template<class T>
void BinarySerchTree<T>::visit(BstNode<T>*currentNode) {
    std::cout <<"  "<<currentNode->data.key;
}
#endif