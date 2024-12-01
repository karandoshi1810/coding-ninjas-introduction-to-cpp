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
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertNodeAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }
    void insertNodeAtMid(int value, int pos)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else
        {
            int k = 1;
            Node *leader = head, *follower = head;
            while (k < pos && leader!=NULL)
            {
                k++;
                follower = leader;
                leader = leader->next;
            }
            follower->next = newNode;
            newNode->next = leader;
        }
        return;
    }
    void insertNodeAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    void deleteNodeFromBeginning()
    {
        if(head==NULL)
        {
            cout<<"You opted to delete node from beginning. However the list is already empty!!"<<endl;
            return;
        }
        Node *temp = head;
        head=head->next;
        free(temp);
        return;
    }
    void deleteNodeFromMid(int pos)
    {
        if(head==NULL)
        {
            cout<<"You opted to delete node from beginning. However the list is already empty!!"<<endl;
            return;
        }
        if(pos==1)
        {
            Node* temp=head;
            head=head->next;
            free(temp);
            return;
        }
        int k=1;
        Node *leader=head,*follower=head;
        while(k<pos && leader!=NULL)
        {
            k++;
            follower=leader;
            leader = leader->next;
        }
        if(leader==NULL)
        {
            cout<<"Position does not exist"<<endl;
            return;
        }
        else
        {
            follower->next=leader->next;
            free(leader);
        }
        return;
    }
    void deleteNodeFromEnd()
    {
        if(head==NULL)
        {
            cout<<"You opted to delete node from beginning. However the list is already empty!!"<<endl;
            return;
        }
        Node *leader=head,*follower=head;
        while(leader->next!=NULL)
        {
            follower=leader;
            leader=leader->next;
        }
        follower->next=NULL;
        free(leader);
    }
    void printLL(int x)
    {
        cout << "-------------------------------------" << x << endl;
        cout << "Printing linked list" << endl;
        Node *temp = head;
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
    LinkedList *ll = new LinkedList();
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
                cout<<"Please enter next input"<<endl;
                cin >> input;
            }
            break;

            case 2:
            {
                cout << "Please enter node data and position at which you want to insert the node:" << endl;
                cin >>nodeData>> position;
                ll->insertNodeAtMid(nodeData, position);
                ll->printLL(input);
                cout<<"Please enter next input"<<endl;
                cin >> input;
            }
            break;

            case 3:
            {
                cout << "Please enter nodeData:" << endl;
                cin >> nodeData;
                ll->insertNodeAtEnd(nodeData);
                ll->printLL(input);
                cout<<"Please enter next input"<<endl;
                cin >> input;
            }
            break;

            case 4:
            {
                ll->deleteNodeFromBeginning();
                ll->printLL(input);
                cout<<"Please enter next input"<<endl;
                cin >> input;
                break;
            }

            case 5:
            {
                cout<<"Please enter position of node to be deleted"<<endl;
                cin>>position;
                ll->deleteNodeFromMid(position);
                ll->printLL(input);
                cout<<"Please enter next input"<<endl;
                cin >> input;
                break;
            }

            case 6:
            {
                ll->deleteNodeFromEnd();
                ll->printLL(input);
                cout<<"Please enter next input"<<endl;
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
    return 0;
}
