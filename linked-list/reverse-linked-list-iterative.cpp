#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

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
    void insertNode(int val)
    {
        Node *node = new Node(val);

        if (head == NULL)
        {
            head = node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        return;
    }
    void reverseList()
    {
        Node *prev = NULL, *next = NULL,*tempHead=head;
        //three pointer approach
        //Idea is to change link of every node in linked list to its previous node using prev,current and next pointers.
        //Initially prev points to NULL,
        //currnt(temphead) points to NULL
        //and next points to current(tempHead)->next;
        //while we do not reach the end of the list:
            //point next to tempHead->next, to next node of the current node
            //update current's(tempHead's) link(next pointer) to point to prev
            //update prev to point to current(tempHead)
            //update current(tempHead) to next, we move to next node from this step and change its link(next) to point to current(tempHead)
        while (tempHead)
        {
            next = tempHead->next;
            tempHead->next = prev;
            prev = tempHead;
            tempHead = next;
        }
        //assign head to prev which is points to the new head(last node of the original list)
        //because tempHead will be pointing to NULL based on condition of while loop;
        head = prev;
        return;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty... Please add some nodes" << endl;

            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
};

int main()
{
    cout << "Press 1 to insert node" << endl;
    cout << "Press 2 to reverse existing ll" << endl;
    cout << "Press -1 to end" << endl;
    int input = 0;
    cin >> input;
    LinkedList *ll = new LinkedList();
    while (input != -1)
    {
        switch (input)
        {
        case 1:
        {
            int value = 0;
            cout << "Please enter nod value:" << endl;
            cin >> value;
            ll->insertNode(value);
            ll->printList();
            cout << "Press 1 to insert node" << endl;
            cout << "Press 2 to reverse existing ll" << endl;
            cout << "Press -1 to end" << endl;
            cin >> input;
            break;
        }
        case 2:
        {
            ll->reverseList();
            ll->printList();
            cout << "Press 1 to insert node" << endl;
            cout << "Press 2 to reverse existing ll" << endl;
            cout << "Press -1 to end" << endl;
            cin >> input;
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
    }
}
