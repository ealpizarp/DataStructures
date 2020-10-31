#include <iostream>
#include "include\BSTree.h"
#include <string>

using namespace std;

int main()
{
    BSTree<int, string> tree;
    tree.insert(10, "diez");
    tree.insert(5, "cinco");
    tree.insert(15, "quince");
    tree.insert(2, "dos");
    tree.insert(17, "diecisiete");
    tree.insert(7, "siete");
    tree.insert(12, "doce");
    tree.insert(19, "diecinueve");
    tree.insert(16, "dieciseis");
    tree.insert(13, "trece");
    tree.insert(11, "once");
    tree.insert(8, "ocho");
    tree.insert(6, "seis");
    tree.insert(3, "tres");
    tree.insert(1, "uno");
    tree.inOrder();
    tree.remove(10);
    tree.remove(12);
    tree.remove(13);
    tree.inOrder();

    return 0;
}
