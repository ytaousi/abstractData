#ifndef TREE_HPP
#define TREE_HPP

#include "../utility/less.hpp"
#include <iostream>
namespace ft
{

    typedef enum colors 
    {
        RED = 0,
        BLACK = 1
    }   t_colors;

//
//    Red/Black Property: Every node is colored, either red or black.

//    Root Property: The root node always black.

//    Leaf Property: Every leaf (NIL) is black.

//    Red Property: If a red node has children then, the children are always black.

//    Depth Property: For each node, any simple path from this node to any of its descendant leaf has the same black-depth (the number of black nodes).

//    NULL nodes are considered black nodes.

//    No two consecutive red nodes are allowed, but two consecutive black nodes are allowed.

//    IF BLACK AUNTI : rotate and/or coloring      , AFTER ROTATION : the node is colored black abd the childs are colored red
            //  IF Node is a right child,  Perform a left rotation on the parent
            // IF Node is a left child,  Perform a right rotation on the GranDparent
//    IF RED AUNTI : recolor        , AFTER RECOLORING : the node should be RED and the childs should be BLACK


//
template <typename K>
class tree
{
    public:
        class Node {
            public:
                K key; //this will store the data

                Node* left;
                Node* right;
                Node* parent;
                Node* uncle;
                int isBlack;
                int isLeftChild;  // 1 if left child, 0 if right child
                t_colors color; // 0 for black, 1 for red
        
            public:
                Node(K t_key)
                {
                    key = t_key;
                    left = nullptr;
                    right = nullptr;
                    parent = nullptr;
                    color = ft::RED;
                    isLeftChild = 0;
                }
                ~Node() {};
        };

    public:
        Node* root;
        Node* TNULL;
        std::size_t _size;

        Node* getRoot() {
            return this->root;
        }
        void checkColor(Node* node) {
            if (node == this->root)
                return;
            if (node->color != ft::BLACK && node->parent->color != ft::BLACK)
                balanceTree(node);
            return checkColor(node->parent);
        }
        // void flipColor(Node* node) {
        //     node->color == ft::BLACK ? ft::RED : ft::BLACK;
        // }
        // void fixColor(Node* node) {};
        // void fixInsertion(Node* node) {};
        // void fixDeletion(Node* node) {};
        // void fixRotation(Node* node) {
        //     if (node->isLeftChild == 1) {
        //         if (node->parent->isLeftChild == 1) {
        //             RightRotate(node->parent->parent);
        //         }
        //         RightLeftRotate(node->parent->parent);
        //     }
        //     else{
        //         if (node->parent->isLeftChild == 0) {
        //             LeftRotate(node->parent->parent);
        //         }
        //         LeftRightRotate(node->parent->parent);
        //     }     
        // }
        // if imbalance is in the left subtree of the left child  we do a right rotation
        // if imbalance is in the right subtree of the right child we do a left rotation
        // if imbalance is in the left subtre of the right child 
        // if imbalance is in the right subtree of the left child
        void LeftRotate(Node* x) {
            Node* y = x->right;
            x->right = y->left;
            if (y->left != NULL) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
            
        }
        void RightRotate(Node* x) {
            Node* y = x->left;
            x->left = y->right;
            if (y->right != NULL) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->right) {
                x->parent->right = y;
            }
            else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }
        void LeftRightRotate(Node* node) {
            LeftRotate(node->left);
            RightRotate(node);
        }
        void RightLeftRotate(Node* node) {
            RightRotate(node->right);
            LeftRotate(node);
        }
        // void balanceTree(Node* node) {
        //     // if ANTI is BLACK
        //     // do rotation
        //     // if ANTI is RED
        //     // do recoloring
        // }
        tree() {
            this->TNULL = new Node(0, 0);
            this->TNULL->color = ft::BLACK;
            this->TNULL->left = this->TNULL->right = TNULL;
            this->_size = 0;
            this->root = this->TNULL;
        };
        ~tree() {};
        int height() {
            if (this->root == NULL) {
                return 0;
            }
            return height(this->root) - 1;
        }
        int height(Node* node) {
            if (node == NULL) {
                return 0;
            }
            int leftHeight = height(node->left) + 1;
            int rightHeight = height(node->right) + 1;
            if (leftHeight > rightHeight) {
                return leftHeight;
            }
            return rightHeight;
        }
        int insertNode(Node* parent , Node* node)
        {
           ;
        }
        // void removeNode(Node*parent, Node*node) {
        //     ;
        // }
        void PreorderTraversal(Node* node) {//(current, left, right) 
            if (node != TNULL) {
                std::cout << node->value << " ";
                PreorderTraversal(node->left);
                PreorderTraversal(node->right);
            }
        }
        // void InorderTraversal(Node* node) {//(left, current, right)
        //     if (node != TNULL) {
        //         InorderTraversal(node->left);
        //         std::cout << node->value << " ";
        //         InorderTraversal(node->right);
        //     }
        // }
        // void PostorderTraversal(Node* node) {// (left, right, current);
        //     if (node != TNULL) {
        //         PostorderTraversal(node->left);
        //         PostorderTraversal(node->right);
        //         std::cout << node->value << " ";
        //     }
        // }
};
}

#endif // TREE_HPP