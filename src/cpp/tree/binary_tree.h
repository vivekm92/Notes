#ifndef __DS_BINARY_TREE__
#define __DS_BINARY_TREE__

#include <iostream>

namespace ds {

    template<typename Data>
    class BinaryTree {
        private :
            struct treeNode {
                Data data;          // data
                treeNode* left;     // left child
                treeNode* right;    // right child
            };

            treeNode* root;

            treeNode* createNode(Data data) {
                treeNode* node = new treeNode;
                node->data = data;
                node->left = nullptr;
                node->right = nullptr;

                return node;
            }

        public :
            BinaryTree(Data data) {
                this->root = createNode(data);

                return this->root;
            };

            void inOrder() {
                treeNode* curr = this->root;

                if (!curr)
                    return;

                inOrder(curr->left);
                inOrder(curr->data);
                inOrder(curr->right);


            }

    };

}

#endif
