#include<cstdio>
#include<cstdlib>

//Class to implement tree
class tree
{
    private:
            struct node{
                int data;
                struct node* left;
                struct node* right;
            }*root;

             //Helper function to insert a node 
            int insert_func( node* &newnode,int value)
             {
                if(newnode==nullptr)
                {
                        newnode = (node*)malloc(sizeof(node));
                        newnode->data=value;
                        newnode->left=newnode->right=nullptr;
                        return 1;
                }
                if(value<newnode->data)
                {
                     insert_func(newnode->left,value);
                }
                else if(value>newnode->data)
                {
                     insert_func(newnode->right,value);
                }
                 
               
                 
                 
        }

             //Helper function to implement preorder traversal
            void preorderHelper(node* node) 
             {
                    if (!node) return;
                    printf(" %d",node->data);
                    preorderHelper(node->left);
                    preorderHelper(node->right);
            }

            //Helper function to implement postorder traversal
            void postorderHelper(node* node) 
             {
                    if (!node) return;
                    postorderHelper(node->left);
                    postorderHelper(node->right);
                    printf(" %d",node->data);
            }

            //Helper function to implement inorder traversal
            void inorderHelper(node* node) 
             {
                    if (!node) return;
                    inorderHelper(node->left);
                    printf(" %d",node->data);
                    inorderHelper(node->right);
                    
            }

            //Helper function to implement search operation
            int searchhelper(node* &node,int data)
            {
               if(!node)
               {
                return 0;
               }
               if(data==node->data)
               {
                return 1;
               }
               int check_left=searchhelper(node->left,data);
               if(check_left)
               {
                return 1;
               }
               int check_right=searchhelper(node->right,data);
               if(check_right)
               {
                return 1;
               }


            }
    public:
            tree()
            {
               root=nullptr;
            }
            int insert(int);
            void preorder();
            void postorder();
            void inorder();
            void search(int);
};

//Main function to implement Binary search tree
int main()
{
    tree t1;
    int opt;
    while(1)
    {
    printf("Enter your choice\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Search\n6.Exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
                printf("Enter the value you want to insert\n");
                char data;
                int check;
                scanf(" %d",&data);
                check=t1.insert(data);
                if(check==0)
                {
                        printf("The insertion is failed\n");
                }
                break;
        case 2:
                t1.preorder();
                break;
        case 3:
                t1.postorder();
                break;
        case 4:
                t1.inorder();
                break;
        case 5:
                char search_data;
                printf("Enter the the value to be searched\n");
                scanf(" %d",&search_data);
                t1.search(search_data);
                break;
        case 6:
                printf("Exiting program\n");
                return 0;
       
        default:
                printf("Invalid option\n");
                break;
        
    }
}
}

//Helper function to insert a node into tree
int tree::insert(int value)
{
     return insert_func(root,value);
}


// Function to implement preorder traversal  
void tree::preorder() {
        printf("preorder traversal\n");
        if(root==nullptr)
        {
                printf("The tree is empty\n");
        }
        preorderHelper(root);
        printf("\n");
    }

// Function to implement postorder traversal
void tree::postorder() {
        printf("postorder traversal\n");
        if(root==nullptr)
        {
                printf("The tree is empty\n");
        }
        postorderHelper(root);
        printf("\n");
    }

// Function to implement inorder traversal
void tree::inorder() {
        printf("inorder traversal\n");
        if(root==nullptr)
        {
                printf("The tree is empty\n");
        }
        inorderHelper(root);
        printf("\n");
    }

//Function to implement search operation
void tree::search(int value)
{
   int check;
   if(root==nullptr)
        {
                printf("The tree is empty\n");
                return;
        }
   check=searchhelper(root,value);
   if(check==1)
   {
        printf("Element found\n");
   }
   else
   {
        printf("Element not found\n");
   }

}

