#include <iostream>
using namespace std;

// Basic linked list implementation

struct node
{
    int data;
    struct node *next;

    node(int d)
    { // Constructor
        data = d;
        next = NULL;
    }
};

struct node *first = NULL;

void insertafter(int val, int x)
{
    struct node *pnode = new node(x);

    if (first == NULL)
    {
        first = pnode;
        return;
    }
    else
    {
        struct node *p = first;
        while (p != NULL)
        {
            if (p->data == val)
            {
                break;
            }
            else
            {
                p = p->next;
            }
        }
        if (p != NULL)
        {
            pnode->next = p->next;
            p->next = pnode;
        }
        else
        {
            cout << "Value " << val << " not found in the list" << endl;
            delete pnode;
        }
    }
}

void insertbefore(int val, int x)
{
    struct node *pnode = new node(x);
    struct node *p = first;
    struct node *follow = NULL;

    if (first == NULL)
    {
        first = pnode;
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == val)
            {
                break;
            }
            else
            {
                follow = p;
                p = p->next;
            }
        }
        if (p == NULL)
        {
            // Value not found in the list, so insert at the end
            struct node *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = pnode;
        }
        else
        {
            if (follow != NULL)
            {
                follow->next = pnode;
            }
            else
            {
                first = pnode;
            }
            pnode->next = p;
        }
    }
}

int deletenode(int x)
{
    struct node *p = first;
    struct node *follow = NULL;

    while (p != NULL)
    {
        if (p->data == x)
        {
            break;
        }
        else
        {
            follow = p;
            p = p->next;
        }
    }

    // p is the node to be deleted now
    if (p == first)
    {
        first = first->next;
        int info = p->data;
        delete (p);
        return info;
    }

    follow->next = p->next;
    int info = p->data;
    delete (p);
    return info;
}

void traversal()
{
    struct node *p = first;
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

void create(int x)
{
    cout << "Enter number of nodes" << endl;
    int n;
    cin >> n;
    cout << "Enter data values of each node" << endl;

    int val;
    cin >> val;
    first = new node(val);

    struct node *p = first;

    for (int i = 1; i < n; i++)
    {
        cin >> val;
        p->next = new node(val);
        p = p->next;
    }
}

int main()
{
    cout << "Enter what you want to do" << endl;
    int ch;

    do
    {
        cout << "1.Create list\n2.Insert after an element\n3.Insert before an element\n4.Delete\n5.Traverse\n6.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int x;
            cout << "Enter first value to create list" << endl;
            cin >> x;
            create(x);
            break;
        }

        case 2:
        {
            int x, val;
            cout << "Enter element to be inserted and after which node" << endl;
            cin >> val >> x;
            insertafter(val, x);
            break;
        }

        case 3:
        {
            int x, val;
            cout << "Enter element to be inserted and before which node" << endl;
            cin >> val >> x;
            insertbefore(val, x);
            break;
        }

        case 4:
        {
            int x;
            cout << "Enter element to be deleted" << endl;
            cin >> x;
            deletenode(x);
            break;
        }

        case 5:
            traversal();
            break;

        case 6:
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (ch != 6);

    return 0;
}
