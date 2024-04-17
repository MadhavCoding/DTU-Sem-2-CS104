#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst* left;
    struct bst* right;
};

void Insert (struct bst** root, int x)
{
    struct bst* q = (struct bst*)malloc(sizeof(struct bst));
    q->data = x;
    q->left = q->right = NULL;
    if(*root == NULL)
    {
        *root = q;
        return;
    }
    struct bst* p = *root;
    while (1)
    {
        if(x < p->data)
        {
            if(p->left != NULL) p = p->left;
            else break;
        }
        else
        {
            if(p->right != NULL) p = p->right;
            else break;
        }
    }
    if (x < p->data) p->left = q;
    else p->right = q;
}

int largest (struct bst* root)
{
    if(root == NULL) return -1;
    while(root->right != NULL) root = root->right;
    return root->data;
}

struct bst* Delete (struct bst* root, int x)
{
    if(root == NULL) return NULL;
    struct bst* p = root;
    struct bst* q = NULL;
    while (p != NULL && p->data != x)
    {
        if(x < p->data)
        {
            q = p;
            p = p->left;
        }
        else
        {
            q = p;
            p = p->right;
        }
    }
    if(p == NULL) return NULL;
    if(p->left == NULL && p->right == NULL)
    {
        // Case 1
        if(q == NULL)
        {
            root = NULL;
            free(p);
        }
        else 
        {
            if(q->left == p) q->left = NULL;
            else q->right = NULL;
            free(p);
        }
    }
    else if(p->left == NULL || p->right == NULL)
    {
        // Case 2
        struct bst* r = NULL;
        if(p->left != NULL) r = p->left;
        else r = p->right;
        if(q == NULL) root = r;
        else if(q->left == p) q->left = r;
        else q->right = r;
        free(p);
    }
    else
    {
        // Case 3
        int y = largest(p->left);
        p->data = y;
        p->left = Delete(p->left, y);
    }
    return root;
}

int Search (struct bst* root, int x)
{
    if(root == NULL) return 0;
    while (root != NULL)
    {
        if(root->data == x) return 1;
        else if(root->data < x) root = root->right;
        else root = root->left;
    }
    return 0;
}

void Inorder (struct bst* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder (struct bst* root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder (struct bst* root)
{
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void Insert1(struct bst** root)
{
    int x;
    printf("Enter the element to be inserted: ");
    scanf("%d", &x);
    Insert(root, x);
    printf("Element has been inserted\n");
}

void Delete1(struct bst** root)
{
    int x;
    printf("Enter the element to be deleted: ");
    scanf("%d", &x);
    struct bst* del = Delete(*root, x);
    if(del == NULL) printf("Element not found in the Tree\n");
    else printf("Element has been deleted\n");
    *root = del;
}

void Search1(struct bst* root)
{
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    int found = Search(root, x);
    if(found) printf("Element is present in the Tree\n");
    else printf("Element is not present in the Tree\n");
}

void Inorder1(struct bst* root)
{
    printf("Elements of the Tree in Inorder are:- \n");
    Inorder(root);
    printf("\n");
}

void Preorder1(struct bst* root)
{
    printf("Elements of the Tree in Prerder are:- \n");
    Preorder(root);
    printf("\n");
}

void Postorder1(struct bst* root)
{
    printf("Elements of the Tree in Postrder are:- \n");
    Postorder(root);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct bst* root = NULL;
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Insert1(&root);
        else if(choice==2) Delete1(&root);
        else if(choice==3) Search1(root);
        else if(choice==4) Inorder1(root);
        else if(choice==5) Preorder1(root);
        else if(choice==6) Postorder1(root);
        else if(choice==7) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    return 0;
}