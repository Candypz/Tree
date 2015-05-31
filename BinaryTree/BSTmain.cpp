#include <iostream>
#include "BinarySearchTree.h"

int BSTmain() {
    BinarySerchTree<int> m;
    Element<int> a, b, c, d, e, f, g, h, i, j;
    a.key = 5;
    b.key = 3;
    c.key = 12;
    d.key = 3;
    e.key = 15;
    f.key = 2;
    g.key = 8;
    h.key = 22;
    i.key = 20;
    j.key = 9;

    m.insert(a);
    m.insert(b);
    m.insert(c);
    m.insert(f);
    m.display();
    BstNode<int>*ptr;
    ptr = m.search(f);
    std::cout << ptr->data.key;
    BstNode<int>*ptr2;
    ptr2 = m.search(f);
    std::cout << ptr2->data.key << std::endl;


    m.inOrder();
    std::cout << std::endl;
    m.postOrder();
    std::cout << std::endl;
    m.preOrder();
    return 0;
}