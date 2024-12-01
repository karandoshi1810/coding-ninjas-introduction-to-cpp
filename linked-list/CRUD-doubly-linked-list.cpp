#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLL
{
private:
    Node *head = NULL;

public:
    void insertNodeAtBeginning(int value)
    {
        cout << "Inserting node at beginning..." << endl;
        Node *newNode = new Node(value);
        newNode->next = head;
        cout << "Next pointer updated" << endl;
        if (head != NULL)
        {
            cout << "HEad next exists" << endl;
            head->prev = newNode;
        }
        cout << "Updating head" << endl;
        head = newNode;
        return;
    }
    void insertNodeAtMid(int value, int pos)
    {
        cout << "Inserting node somewhere in beween starting and ending node..." << endl;
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            cout << "Head is null" << endl;
            head = newNode;
            return;
        }
        else
        {
            int k = 1;
            Node *temp = head;
            while (k < pos - 1 && temp->next != NULL)
            {
                k++;
                temp = temp->next;
            }
            if (temp->next == NULL && k == pos - 1) // Inserting at the end
            {
                temp->next = newNode;
                newNode->prev = temp;
                return;
            }
            else if (k != pos - 1)
            {
                cout << "Position does not exist" << endl;
            }
            else
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            }
        }
    }
    void deleteNodeFromBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    void deleteNodeFromMid(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            int k = 1;
            Node *temp = head, *temp2 = head;
            while (k < pos - 1 && temp->next != NULL)
            {
                k++;
                temp = temp->next;
            }
            if (k == pos - 1 && temp->next != NULL)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                    free(temp);
                    return;
                }
            }
            else if (k != pos - 1)
            {
                cout << "Position does not exist" << endl;
            }
            else
            {
                temp2 = temp->prev;
                temp2->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp2;
                }
                free(temp);
            }
        }
    }
    void printLL(int x)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Empty linked list." << x << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int input = 0, position = 0;
    cout << "Please select the operation." << endl;
    cout << "------------------------------------" << endl;
    cout << "Please enter 1 to insert element to the beginning of the linked list" << endl;
    cout << "Please enter 2 to insert element to the middle of the linked list" << endl;
    cout << "Please enter 3 to insert element to the end of the linked list" << endl;
    cout << "Please enter 4 to delete element from the beginning of the linked list" << endl;
    cout << "Please enter 5 to delete element from the middle of the linked list" << endl;
    cout << "Please enter 6 to delete element from the end of the linked list" << endl;
    cin >> input;
    DoublyLL *ll = new DoublyLL();
    int nodeData = 0;
    while (input != -1)
    {
        switch (input)
        {
        case 1:
        {
            cout << "Please enter nodeData:" << endl;
            cin >> nodeData;
            ll->insertNodeAtBeginning(nodeData);
            ll->printLL(input);
            cout << "Please enter next input" << endl;
            cin >> input;
        }
        break;

        case 2:
        {
            cout << "Please enter node data and position at which you want to insert the node:" << endl;
            cin >> nodeData >> position;
            ll->insertNodeAtMid(nodeData, position);
            ll->printLL(input);
            cout << "Please enter next input" << endl;
            cin >> input;
        }
        break;

            // case 3:
            // {
            //     cout << "Please enter nodeData:" << endl;
            //     cin >> nodeData;
            //     ll->insertNodeAtEnd(nodeData);
            //     ll->printLL(input);
            //     cout<<"Please enter next input"<<endl;
            //     cin >> input;
            // }
            // break;

        case 3:
        {
            ll->deleteNodeFromBeginning();
            ll->printLL(input);
            cout << "Please enter next input" << endl;
            cin >> input;
            break;
        }

        case 4:
        {
            cout << "Please enter position of node to be deleted" << endl;
            cin >> position;
            ll->deleteNodeFromMid(position);
            ll->printLL(input);
            cout << "Please enter next input" << endl;
            cin >> input;
            break;
        }

            // case 6:
            // {
            //     ll->deleteNodeFromEnd();
            //     ll->printLL(input);
            //     cout<<"Please enter next input"<<endl;
            //     cin >> input;
            //     break;
            // }

        case -1:
        {
            break;
        }

        default:
        {
            break;
        }
        }
    }
    return 0;
}
