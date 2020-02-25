//Frendy Lio

#include <stdlib.h>
#include <stdio.h>

struct Node {
    char val;
    struct Node * left;
    struct Node * right;
};

struct TempNodeStruct {
     struct Node * val;
     struct TempNodeStruct * next;
};


void display_tree(struct Node * root);
struct Node * destroy_tree(struct Node * root);
struct Node * create_tree();
void inorder(struct Node * root);
struct Node * delete(struct Node * root, char val);
struct Node * common(struct Node * root, char a, char b);
void display_node(struct Node * root);
int search(struct Node * root, struct TempNodeStruct * path, char val);

void main()
{
struct Node * root = create_tree(root);
printf("Initial tree: \n");
display_tree(root);
printf("List of nodes in order: ");
inorder(root);

struct Node * p = common(root, 'm', 'z');
printf("\n");
printf("Least Common Root of 'm' and 'z': ");
display_node(p);
printf("\n");

p = common(root, 'f', 'z');
printf("\n");
printf("Least Common Root of 'f' and 'z': ");
display_node(p);
printf("\n");

root = destroy_tree(root);
display_tree(root);
}

int search(struct Node * root, struct TempNodeStruct * path, char val)
{
     if(root == NULL) {return 0;}
     path->next = (struct TempNodeStruct *) malloc(sizeof(struct TempNodeStruct));
     path->next->val = root;
     if(root->val == val) {return 1;}

     if(search(root->left, path->next, val) || search(root->right, path->next, val)) {return 1;}

     else{
     free(path->next->val);
     return 0;
     }

}


struct Node * common(struct Node * root, char a, char b)
{
     struct TempNodeStruct * temp = (struct TempNodeStruct *) malloc(sizeof(struct TempNodeStruct)); 
     struct TempNodeStruct * temp2 = (struct TempNodeStruct *) malloc(sizeof(struct TempNodeStruct));
     search(root, temp, a);
     search(root, temp2, b);


     while(temp->next->val == temp2->next->val) {
          temp = temp->next;
          temp2 = temp2->next;
          if(temp->next == NULL || temp2->next == NULL) {break;}
     }
     return temp->val;
}

void display_node(struct Node * root)
{
if (root == NULL) {
    printf("NULL");
}
else {
    printf("%c", root->val);
}
return;
}


void destroy_node(struct Node * root)
{
if (root != NULL) free(root);
return;
}

struct Node * create_node(char val)
{
struct Node * p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

struct Node * create_tree()
{
struct Node * root = create_node('a');
root->right = create_node('h');
root->left = create_node('f');
root->left->left = create_node('e');
root->left->right = create_node('d');
root->left->left->left = create_node('m');
root->left->left->right = create_node('n');
root->left->right->left = create_node('z');
return root;
}

struct Node * destroy_tree(struct Node * root)
{
if (root == NULL) return NULL;
destroy_tree(root->left);
destroy_tree(root->right);
return NULL;
}

char display_val(struct Node * root)
{
if (root==NULL) return '/';
else return root->val;

}

void display_tree(struct Node * root)
{
if (root==NULL) return;
printf("%c -> %c, %c\n",root->val,display_val(root->left),display_val(root->right));
display_tree(root->left);
display_tree(root->right);
return;
}

void inorder(struct Node * root)
{
if (root == NULL) return;
inorder(root->left);
printf("%c ", root->val);
inorder(root->right);
return;
}

