#include <iostream>
#include "RBtree.hpp"
int main()
{
    bbst<int> _bst;

    for(int i = 0; i < 10e8; i++)
        _bst.insert(i);
    // std::cout << _bst.find(15) << std::endl;
    return 0;
}