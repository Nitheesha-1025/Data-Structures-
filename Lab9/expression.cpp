#include <iostream>
#include <stack>
using namespace std;

class Tree 
{
private:
    struct Node 
    {
        char data;
        struct Node *left, *right;
    } *root;

public:
    Tree() 
    {
        root = NULL;
    }
    void insert(char);
    void constructExpressionTree(string postfix);
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    void displayPreorder() { preorder(root); }
    void displayInorder() { inorder(root); }
    void displayPostorder() { postorder(root); }
};

//Function to insert a character variable in an expression
void Tree::insert(char val) 
{
    struct Node *newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    if (root == NULL) 
    {
        root = newNode;
        return;
    }
    
    struct Node *current = root, *parent = NULL;
    while (current != NULL) 
    {
        parent = current;
        if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

//Function to construct an expression tree
void Tree::constructExpressionTree(string postfix) 
{
    stack<Node*> s;
    for (char ch : postfix) {
        Node *newNode = new Node();
        newNode->data = ch;
        newNode->left = newNode->right = NULL;

        if (isalnum(ch)) 
        {
            s.push(newNode);
        } 
        else
        {
            newNode->right = s.top(); s.pop();
            newNode->left = s.top(); s.pop();
            s.push(newNode);
        }
    }
    root = s.top();
}

//Function to display preorder traversal
void Tree::preorder(Node *node) 
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

//Function to display inorder traversal
void Tree::inorder(Node *node) 
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

//Function to display postorder traversal
void Tree::postorder(Node *node) 
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

//Main function to implement expression tree
int main() 
{
    Tree expTree;
    int choice;
    string postfix;

    do 
    {
        cout << "\nExpression Tree Menu:\n";
        cout << "1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                expTree.constructExpressionTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                expTree.displayPreorder();
                cout << "\n";
                break;
            case 4:
                cout << "Inorder Traversal: ";
                expTree.displayInorder();
                cout << "\n";
                break;
            case 5:
                cout << "Postorder Traversal: ";
                expTree.displayPostorder();
                cout << "\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}