#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head = NULL;

public:
    void insert()
    {
        int data = 0;
        cout << "Please enter data:" << endl;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }

    void oddEvenList()
    {
        Node *evenList = new Node(-1);
        Node *evenTail = evenList;

        Node *curr = head, *temp = head,*prev=head;
        int index = 1;
        while (curr)
        {
            if (index % 2 == 0)
            {
                temp = curr;
                prev->next = curr->next;
                evenTail->next = temp;
                evenTail = temp;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
            index++;
        }
        curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = evenList->next;
    }

    int getLength()
    {
        Node *temp = head;
        int length = 0;
        while (temp->next != head)
        {
            length++;
            temp = temp->next;
        }
        return length + 1;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in linked list" << endl;
    cout << "Press 2 to separate even and odd nodes" << endl;
    cout << "Press 3 to print list" << endl;
    cout << "Press -1 to exit" << endl;
    cin >> input;
    if (input < -1 || input > 3)
    {
        cout << "Please enter a valid input" << endl;
        cout << "-----------------------------------" << endl;
        return menu();
    }
    return input;
}

int main()
{
    int input = 0;
    input = menu();
    LinkedList *ll = new LinkedList();
    while (input)
    {
        switch (input)
        {
        case 1:
        {
            ll->insert();
            ll->printList();
            input = menu();
            break;
        }
        case 2:
        {
            ll->oddEvenList();
            ll->printList();
            input = menu();
            break;
        }
        case 3:
        {
            ll->printList();
            input = menu();
            break;
        }
        case -1:
        {
            break;
        }
        default:
        {
            break;
        }
        }
        // break;
    }
}
