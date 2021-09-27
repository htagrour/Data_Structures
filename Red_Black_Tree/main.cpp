#include <iostream>
#include "RBtree.hpp"
int main()
{
    bbst<int> _bst;

    for(int i = 0; i < 11; i++)
        _bst.insert(i);
    _bst.PrintTree();
    // std::cout << _bst.find(15) << std::endl;
    return 0;
}