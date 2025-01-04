#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    private:
    Node* head=NULL,*temp=NULL;
    public:
    void insert()
    {
        int data=0;
        cout<<"enter node data:";
        cin>>data;

        Node* newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        temp = head;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        return;
    }

    int modularNode()
    {
        int k=0;
        cout<<"Enter k:";
        cin>>k;
        if((head == NULL || head->next==NULL) && k<=0)
        {
            return 1;
        }
        if((head == NULL || head->next==NULL) && k>1)
        {
            return -1;
        }

        temp = head;
        int index=1;
        Node* lastModularNode=head;
        while(temp)
        {
            if(index%k==0)
            {
                lastModularNode = temp;
            }
            index++;
            temp = temp->next;
        }
        return lastModularNode->data;
    }

    int getLength()
    {
        temp = head;
        int length=0;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }

    void printList()
    {
        temp = head;

        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in linked list" << endl;
    cout << "Press 2 to last modular node" << endl;
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
            int lastModularNode = ll->modularNode();
            cout<<"Modular Node:"<<lastModularNode<<endl;
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

