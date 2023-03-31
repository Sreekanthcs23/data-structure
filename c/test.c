#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} *root = NULL;
struct tree *queue[50];
int front = -1;
int rear = -1;
struct tree *dequeue()
{
    if ((rear == -1 && front == -1) || (front > rear))
    {
        return NULL;
    }
    else
    {
        return queue[front++];
    }
}
void enqueue(struct tree *temp)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = temp;
    }
    else
    {
        rear++;
        queue[rear] = temp;
    }
}
struct tree *create()
{
    int x;
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        struct tree *new = (struct tree *)malloc(sizeof(struct tree));
        new->data = x;
        printf("Enter left node of %d:", x);
        new->left = create();
        printf("Enter right node of %d:", x);
        new->right = create();
        return new;
    }
}
void preorder(struct tree *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct tree *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}
void inorder(struct tree *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}
void insert()
{
    struct tree *temp = root;
    front = -1;
    rear = -1;
    struct tree *new = (struct tree *)malloc(sizeof(struct tree));
    printf("\nENTER THE ELEMENT TO INSERT\n");
    scanf("%d", &new->data);
    new->left = NULL;
    new->right = NULL;
    if (root == NULL)
    {
        root = new;
    }
    else
    {
        while (front <= rear)
        {
            if (temp->left == NULL)
            {
                temp->left = new;
                return;
            }
            else if (temp->right == NULL)
            {
                temp->right = new;
                return;
            }
            else
            {
                enqueue(temp->left);
                enqueue(temp->right);
            }
            temp = dequeue();
        }
    }
}
void delete ()
{
    int x;
    front = -1;
    rear = -1;
    printf("Enter the element to delete\n");
    scanf("%d", &x);
    struct tree *temp = root;
    struct tree *key = NULL;
    struct tree *flag = NULL;
    if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
    }
    else
    {
        while (front <= rear)
        {
            if (temp->data == x)
            {
                key = temp;
            }
            if (temp->left != NULL)
            {
                flag = temp;
                enqueue(temp->left);
            }
            if (temp->right != NULL)
            {
                flag = temp;
                enqueue(temp->right);
            }
            temp = dequeue();
        }
        if (temp->data == x)
        {
            if (flag->left == temp)
                flag->left = NULL;
            else if (flag->right == temp)
                flag->right = NULL;
        }
        else
        {
            if (key == NULL)
            {
                printf("\nDELETION IS NOT POSSIBLE\n");
                return;
            }
            key->data = temp->data;
            if (flag->left == temp)
                flag->left = NULL;
            else if (flag->right == temp)
                flag->right = NULL;
        }
    }
}
void leaf()
{
    front = -1;
    rear = -1;
    int count = 0;
    struct tree *temp = root;
    while (front <= rear)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            count++;
        }
        if (temp->left != NULL)
            enqueue(temp->left);
        if (temp->right != NULL)
            enqueue(temp->right);
        temp = dequeue();
        if (temp == NULL)
        {
            break;
        }
    }
    if (temp == NULL)
    {
        printf("NO. OF LEAF NODE=%d", count);
    }
    else
    {
        printf("NO. OF LEAF NODE=%d", count + 1);
    }
}
int main()
{
    int choice;
    printf("ENTER ROOT ELEMENT:");
    root = create();
    while (1)
    {
        printf("\nEnter your choice\n 1-insert\n2-preorder\n3-postorder\n4-inorder\n5-delete\n6-exit\n7-Count of leaf node\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            delete ();
            break;
        case 6:
            return 0;
        case 7:
            leaf();
            break;
        default:
            printf("INVALID ENTRIES\n");
        }
    }
}
