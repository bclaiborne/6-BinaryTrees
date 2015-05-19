typedef struct Node{
    struct Node *left;
    struct Node *right;
    int val;
} Node;
typedef struct Tree{
    Node *root;
    int size;
} Tree;

Tree *create();
Node *build(int val);
void addNode(Tree *tree, Node *parent, Node *node);
int preOrder(Node *current);
int inOrder(Node *current);
int postOrder(Node *current);
int visit(Node *node);
