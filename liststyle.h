typedef struct Node{
    struct Node *left;
    struct Node *right;
    struct Tree *tree;
    int val;
} Node;
typedef struct Tree{
    Node *root;
    int size;
} Tree;

Tree *create();
Node *build(int val);
int clearNode(Node *target);
void addNode(Tree *tree, Node *parent);
void *newChild(Tree *tree, Node *parent, int val, char *side);
int preOrder();
int inOrder();
int postOrder();