#include <iostream>
using namespace std;
struct Node
{
    int data = 0;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class CircularLL
{
private:
    Node *head = NULL;

public:
    void insertAtBeginning()
    {
        int data;
        cout << "Please enter data:";
        cin >> data;
        Node *newNode = new Node(data);
        newNode->next = newNode;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        if (head->next == head)
        {
            newNode->next = head;
            head->next = newNode;
            head = newNode;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
        return;
    }
    void insertAtEnd()
    {
        int data = 0;
        cout << "Please enter data:";
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            // head = newNode;
            return;
        }
    }
    void insertAtMid()
    {
        int data = 0, position = 0;
        // int length = getLinkedListLength();
        cout << "Please enter position of insertion:";
        cin >> position;
        if (position == 1)
        {
            insertAtBeginning();
            return;
        }
        // if(position==length+1)
        // {
        //     insertAtEnd();
        //     return;
        // }
        cout << "Please enter data:";
        cin >> data;
        Node *newNode = new Node(data);
        int iterator = 1;
        Node *leader = head, *follower = head;
        while (iterator < position - 1 && leader->next != head)
        {
            iterator++;
            follower = leader;
            leader = leader->next;
            cout << "Iterator:" << iterator << endl;
        }
        if (iterator == position - 1 && leader->next == head)
        {
            cout << "Leader==head" << endl;
            leader->next = newNode;
            newNode->next = head;
            return;
            // head=newNode;
        }
        else if (iterator != position - 1)
        {
            cout << "Position does not exits" << endl;
            return;
        }
        else
        {
            newNode->next = leader->next;
            leader->next = newNode;
            if (leader == head)
            {
                cout << "Leader data:" << leader->data << " Head data:" << head->data << endl;
                head = newNode;
            }
        }
    }
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "List is already empty... You can choose to add some data" << endl;
            return;
        }
        if (head->next == head)
        {
            cout << "Deleting the last remaining node of the ll..." << endl;
            Node *temp = head;
            free(temp);
            head = NULL;
            cout << "The last node of the ll is deleted." << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                cout << "Temp Data:" << temp->data << endl;
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp=head;
            head=head->next;
            free(temp);
            return;
        }
    }
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is already empty... You can choose to add some data.";
        }
        if (head->next == head)
        {
            cout << "Deleting the last remaining node of the ll..." << endl;
            Node *temp = head;
            free(temp);
            head = NULL;
            cout << "The last node of the ll is deleted." << endl;
            return;
        }
        else
        {
            Node *temp = head,*temp2=head;
            while (temp->next != head)
            {
                temp2=temp;
                temp = temp->next;
            }
            temp2 = temp->next;
            free(temp2);
            return;
        }
    }
    void deleteFromMid()
    {
        if (head == NULL)
        {
            cout << "List is already empty... You can choose to add some data.";
        }
        if (head->next == head)
        {
            cout << "Deleting the last remaining node of the ll..." << endl;
            Node *temp = head;
            free(temp);
            head = NULL;
            cout << "The last node of the ll is deleted." << endl;
            return;
        }
        else
        {
            int position=1;
            cout<<"Please enter position of deletion"<<endl;
            cin>>position;
            Node *temp=head,*temp2=head;
            int pos=1;
           while(pos<position && temp->next!=head)
            {
                pos++;
                temp2=temp;
                temp = temp->next;
            }
            if(pos==position-1 && temp->next==head)
            {
                temp2->next=temp->next;
                free(temp);
            }
            else if(pos!=position)
            {
                cout<<"Position does not exist..."<<endl;
            }
            else
            {
                temp->next=temp->next;
                free(temp);
                return;
            }
        }
    }
    void printLL()
    {
        if (head == NULL)
        {
            cout << "List is already empty...";
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
        return;
    }
    int getLinkedListLength()
    {
        if (head == NULL)
        {
            cout << "List is already empty...";
            return 0;
        }
        Node *temp = head;
        int length = 0;
        while (temp != head)
        {
            cout << temp->data << " ";
            length++;
            temp = temp->next;
        }
        return length;
    }
};
int displayMenu()
{
    int input = 0;
    cout << "Please select the operation." << endl;
    cout << "------------------------------------" << endl;
    cout << "Please enter 1 to insert element to the beginning of the linked list" << endl;
    cout << "Please enter 2 to insert element to the middle of the linked list" << endl;
    cout << "Please enter 3 to insert element to the end of the linked list" << endl;
    cout << "Please enter 4 to delete element from the beginning of the linked list" << endl;
    cout << "Please enter 5 to delete element from the middle of the linked list" << endl;
    cout << "Please enter 6 to delete element from the end of the linked list" << endl;
    cout << "Please enter 7 print linked list" << endl;
    cin >> input;
    return input;
}
int main()
{
    int input = displayMenu();
    CircularLL *ll = new CircularLL();
    while (input != -1)
    {
        switch (input)
        {
        case 1:
        {
            ll->insertAtBeginning();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 2:
        {
            ll->insertAtMid();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 3:
        {
            ll->insertAtEnd();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 4:
        {
            ll->deleteFromBeginning();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 5:
        {
            ll->deleteFromMid();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 6:
        {
            ll->deleteFromEnd();
            ll->printLL();
            input = displayMenu();
            break;
        }
        case 7:
        {
            ll->printLL();
            input = displayMenu();
            break;
        }
        case -1:
        {
            break;
        }
        }
    }
    return 0;
}