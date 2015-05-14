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
int clearNode(Node *target);
void addNode(Tree *tree, Node *parent, Node *node);
void *newChild(Tree *tree, Node *parent, int val, char *side);
int preOrder(Node *current);
int inOrder(Node *current);
int postOrder(Node *current);
int visit(Node *node);
int leftSide(Node *node);
int rightSide(Node *node);