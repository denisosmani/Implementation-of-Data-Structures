#include <iostream>
using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTree() {
        cout << "Destorying the tree!" << endl;
        delete this->left;
        delete this->right;
    }

    void add(int value) {
        if (value < this->value) {
            if (this->left == NULL) {
                this->left = new BinaryTree(value);
            }
            else {
                this->left->add(value);
            }
        }
        else if (value > this->value) {
            if (this->right == NULL) {
                this->right = new BinaryTree(value);
            }
            else {
                this->right->add(value);
            }

        }
    }

    void inorder() {
        if (this->left != NULL) {
            this->left->inorder();
        }

        cout << " " << this->value;

        if (this->right != NULL) {
            this->right->inorder();
        }
    }

    void preorder() {
        cout << " " << this->value;

        if (this->left != NULL) {
            this->left->preorder();
        }

        if (this->right != NULL) {
            this->right->preorder();
        }
    }

    void postorder() {
        if (this->left != NULL) {
            this->left->postorder();
        }

        if (this->right != NULL) {
            this->right->postorder();
        }

        cout << " " << this->value;
    }

    //sum of elements
    int sum(BinaryTree* tree) {
        if (tree == NULL) {
            return 0;
        }
        else {
            return tree->value + sum(tree->left) + sum(tree->right);
        }
    }

    //number of elements
    int size(BinaryTree* tree) {
        if (tree == NULL) {
            return 0;
        }
        else {
            return 1 + size(tree->left) + size(tree->right);
        }
    }


};


int main()
{
    BinaryTree* root = new BinaryTree(5);
    root->add(3);
    root->add(7);
    root->add(1);
    root->add(4);
    root->add(6);
    root->add(9);

    cout << "Inorder:  ";
    root->inorder();
    cout << endl;

    cout << "Preorder: ";
    root->preorder();
    cout << endl;

    cout << "postorder:";
    root->postorder();
    cout << endl;

    cout << "\nSum of elements: " << root->sum(root) << endl;
    cout << "Number of elements: " << root->size(root) << endl;

    return 0;
}