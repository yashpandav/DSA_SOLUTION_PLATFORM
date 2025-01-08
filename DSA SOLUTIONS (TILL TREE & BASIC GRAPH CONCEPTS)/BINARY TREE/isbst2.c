#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isbst(struct node* root) {
    static struct node* prev = NULL;

    if (root != NULL) {
        if (!isbst(root->left)) {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }

        prev = root;
        return isbst(root->right);
    }
    return 1;
}

void resetIsBst() {
    // Reset the static variable
    isbst(NULL);
}

int main() {
    struct node* p = createnode(4);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(5);
    struct node* p3 = createnode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;

    preorder(p);
    printf("\n");

    postorder(p);
    printf("\n");

    inorder(p);
    printf("\n");

    resetIsBst(); // Reset the static variable
    printf("%d  ", isbst(p));

    resetIsBst(); // Reset the static variable again
    if (isbst(p) == 1) {
        printf("yes its a bst");
    } else {
        printf("its not a bst");
    }

    return 0;
}
