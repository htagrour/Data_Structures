#ifndef RBTREE_HPP
#define RBTREE_HPP
#include <memory>
#include <iostream>

#define COUNT 5
template <typename v1>
struct vect3
{
    vect3(v1 value, bool isExist, bool toLeft):\
    value(value),isExist(isExist),toLeft(toLeft){};

    v1 value;
    bool isExist;
    bool toLeft;
};

template <typename T>
struct Node
{
    typedef T value_type;
    typedef Node<value_type>* pointer;

    Node():_data(value_type()),_left(NULL), _right(NULL),_parent(NULL), isBlack(false){};
    Node(const value_type& val):_data(val),_left(NULL), _right(NULL), _parent(NULL), isBlack(false){};

    pointer _left;
    pointer _right;
    pointer _parent;
    value_type _data;
    bool isBlack;


};

template <typename T, typename Comp = std::less<T> , typename Alloc = std::allocator<T> >
class bbst
{
    typedef T value_type;
    typedef Node<value_type>* pointer;
    typedef Comp comp_value;
    typedef typename Alloc::template rebind<Node<value_type> >::other node_alloc;

    public:
        
        bbst()
        {
            _alloc = node_alloc();
            _comp = comp_value();
            _head = NULL;
            _size = 0;
            _end = allocate_node(value_type());
        }

        void insert(const value_type& val)
        {
            pointer newNode;

            if (_size)
            {
                pointer newNode = insertToLeaf(val);
                if (newNode)
                    fixViolation(newNode);
            }
            else
                insertToHead(val);
        }

        void PrintTree() { print2DUtil(_head, 0);}
        bool find(const value_type& val) { return findHelper(_head, val).isExist;};

    private:
        void fixViolation(pointer &node)
        {
            pointer parent;
            pointer grandParent;

            if (node == _head || node->isBlack || node->_parent->isBlack)
            {
                _head->isBlack = true;
                return;
            }

            parent = node->_parent;
            grandParent = parent->_parent;
            if (parent == grandParent->_left)
                LeftChild(node, parent, grandParent);
            else
                RightChild(node, parent, grandParent);
            fixViolation(node);
        }

        void LeftChild(pointer &node, pointer parent, pointer gParent)
        {
            pointer uncle = gParent->_right;

            //color correction:
            if (uncle && !uncle->isBlack)
                fixColor(node, parent, gParent, uncle);
            else
            {
                //Left Right Rotation
                if (node == parent->_right)
                {
                    rotateLeft(parent);
                    node  = parent;
                    parent  = node->_parent;
                }
                rotateRight(gParent);
                std::swap(parent->isBlack, gParent->isBlack);
                node = parent;
            }

        }

        void RightChild(pointer &node, pointer parent, pointer gParent)
        {
            pointer uncle = gParent->_left;

            if (uncle && !uncle->isBlack)
                fixColor(node, parent, gParent,uncle);
            else
            {
                if (node == parent->_left)
                {
                    rotateRight(parent);
                    node = parent;
                    parent = node->_parent;
                }
                rotateLeft(gParent);
                std::swap(parent->isBlack, gParent->isBlack);
                node = parent;
            }
        }

        void fixColor(pointer &node, pointer parent, pointer gParent,pointer uncle)
        {
            gParent->isBlack = false;
            parent->isBlack = true;
            uncle->isBlack = true;
            node = gParent;
        }

        void rotateRight(pointer node)
        {
            pointer left = node->_left;
            
            node->_left = left->_right;
            if (node->_left)
                node->_left->_parent = node;
            left->_parent = node->_parent;
            if (!left->_parent)
                _head = left;
            else if (node == node->_parent->_left)
                node->_parent->_left = left;
            else
                node->_parent->_right = left;
            left->_right = node;
            node->_parent = left;
        }

        void rotateLeft(pointer node)
        {
            pointer right = node->_right;

            node->_right = right->_left;
            if (node->_right)
                node->_right->_parent = node;
            right->_parent = node->_parent;
            if(!node->_parent)
                _head = right;
            else
                if (node == node->_parent->_left)
                    node->_parent->_left = right;
            else
                node->_parent->_right = right;
            right->_left = node;
            node->_parent = right;
        }

        pointer Uncle(pointer node)
        {
            pointer parent = node->_parent;
            pointer grandParent = parent->_parent;
            return ((parent->_left == node) ? grandParent->_right: grandParent->_left);
        }

        pointer insertToLeaf(const value_type& val)
        {
            vect3<pointer> result = findHelper(_head,val);
            pointer newNode;
            if (result.isExist)
                return (NULL);
            newNode = allocate_node(val);
            newNode->_parent = result.value;
            if (result.toLeft)
            {
                result.value->_left = newNode;
                _begin = (result.value == _begin) ? newNode : _begin;
            }
            else
            {
                if (result.value->_right == _end)
                {
                    _end->_parent = newNode;
                    newNode->_right = _end;
                }
                result.value->_right = newNode;
            }
            _size++;
            return newNode;
        }

        void insertToHead(const value_type& val)
        {
            _head = allocate_node(val);
            _head->isBlack = true;
            _head->_right = _end;
            _end->_parent = _head;
            _begin = _head;
            _size++;
        }

        vect3<pointer> findHelper(pointer tmp,const value_type& val)
        {
            if (!_size)
                return vect3<pointer>(NULL, false,false);
            if (_begin->_data != val && _comp( val, _begin->_data))
                return vect3<pointer>(_begin, false, true);
            if (_end->_parent->_data != val && !_comp(val, _end->_parent->_data))
                return vect3<pointer>(_end->_parent, false, false);
            if (tmp->_data == val)
                return vect3<pointer>(tmp, true, false);
            if (_comp(val, tmp->_data))
            {
                if (tmp->_left)
                    return findHelper(tmp->_left, val);
                else
                    return vect3<pointer>(tmp, false, true);
            }
            else
            {
                if (tmp->_right && tmp->_right != _end)
                    return findHelper(tmp->_right, val);
                else
                    return vect3<pointer>(tmp, false, false);
            }
        }

        void print2DUtil(pointer root, int space)
        {
            // Base case
            if (root == NULL)
                return;
        
            // Increase distance between levels
            space += COUNT;
        
            // Process right child first
            print2DUtil(root->_right, space);
        
            // Print current node after space
            // count
            std::cout<<std::endl;
            for (int i = COUNT; i < space; i++)
                std::cout<<" ";
            std::cout<<root->_data<<"\n";
        
            // Process left child
            print2DUtil(root->_left, space);
        }
 
        void traversTree(pointer node)
        {
            if (!node || node == _end)
                return;
            std::cout << node->_data << std::endl;
            if (node->_right)
                traversTree(node->_right);
            else
            {
                if (node == node->_parent->_right)
                    traversTree(node->_parent->_parent);
                else
                    traversTree(node->_parent);
            }
        }

        pointer allocate_node(const value_type& val)
        {
            pointer newNode = _alloc.allocate(1);
            _alloc.construct(newNode, Node<value_type>(val));
            return newNode;
        }
    private:
        pointer _head;
        pointer _begin;
        pointer _end;
        size_t _size;
        node_alloc _alloc;
        comp_value _comp;
};
#endif