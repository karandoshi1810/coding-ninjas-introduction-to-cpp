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
    Node* head=NULL,*leftListHead=NULL,*rightListHead=NULL;
    Node* temp = head;
    Node* preservedLinkForJoiningLists=NULL;
    public:
    void insert()
    {
        int data=0;
        cout<<"Please enter node data:"<<endl;
        cin>>data;
        Node* newNode = new Node(data);
        newNode->next=newNode;
        if(head == NULL)
        {
            cout<<"head is NULL"<<endl;
            head = newNode;
            return;
        }
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
        return;
    }

    //using Floyd's cycle detection algorithm, we will find the middle node
    //we need to contain both list with even and odd number of nodes, hence we will check the condition
    //fast->next!=head && fast->next->next!=head
    //once slow points at mid. will create two lists called:
    //leftList whose head will be pointing to original list's head and end will be slow(mid)
    //rightList whose head will be mid->next and end will be original list's end.
    void splitList()
    {
        Node* fast=head,*slow=head;
        while(fast->next!=head && fast->next->next!=head)
        {
            fast = fast->next->next;
            cout<<"fast->data after moving:"<<fast->data<<endl;
            if(fast->next!=head || fast->next->next!=head)
            {
                cout<<"Fast & Fast->next != head"<<endl;
                slow=slow->next;
            }
        }
        cout<<"Slow node:"<<slow->data<<endl;
        //preserve the link of original link, in case we need original list back
        preservedLinkForJoiningLists = slow->next;
        leftListHead=head;
        rightListHead=slow->next;
        //slow is last node of leftList, hence its last node should point to null.
        slow->next = NULL;
        //we need to point the rightList's end back to its head, making it a circular list.
        //for list with odd number of nodes:
        //fast->next will already pointing to the end of the rightList i.e. last node of the original circular list.
        //this last node will be practically rightList's last node also. So I will use "fast" to point it back to 
        //rightListHead insetad of iterating it completely from beginning using "rightListHead" pointer.
        //before split:1->2->3->4->5
        //after split:1->2->3  4->5
        //           llH    s rlh f 
        //where s=slow,
        //      f=fast   
        //      llh=leftListHead
        //      rlh=rigthListHead

        //for list with even number of nodes:
        //fast->next->next will already pointing to the end of the rightList i.e. last node of the original circular list.
        //this last node will be practically rightList's last node also. So I will use "fast" to point it back to 
        //rightListHead insetad of iterating it completely from beginning using "rightListHead" pointer.
        if(fast->next == head)
        {
            fast->next = rightListHead;
        }
        if(fast->next->next == head)
        {
            fast->next->next = rightListHead;
        }
        cout<<"Lists separated..."<<endl;
        return;
    }

    void printSeparatedList()
    {
        Node* leftListTemp = leftListHead;
        Node* rightListTemp = rightListHead;
        cout<<"Left list..."<<endl;
        if(leftListHead == NULL && rightListHead == NULL)
        {
            cout<<"No split detected. Please consider creating a split."<<endl;
            return;
        }
        while(leftListTemp)
        {
            cout<<leftListTemp->data<<"->";
            leftListTemp=leftListTemp->next;
        }
        cout<<"NULL"<<endl;

        cout<<"Right list..."<<endl;
        while(rightListTemp->next!=rightListHead)
        {
            cout<<rightListTemp->data<<"->";
            rightListTemp=rightListTemp->next;
        }
        cout<<rightListTemp->data<<endl;
        return;
    }

        void rejoinList()
    {
        Node* leftListTemp = leftListHead;
        Node* rightListTemp = rightListHead;
        rejoin(leftListTemp,rightListTemp);
        return;
    }

    void rejoin(Node *leftListTemp,Node* rightListTemp)
    {
        //if we reached at the end of left list then use preserved link to join both
        //the lists. Empty the leftList and riggtList pointers
        if(leftListTemp->next == NULL)
        {
            leftListTemp->next = preservedLinkForJoiningLists;
            while(rightListTemp->next != rightListHead)
            {
                rightListTemp = rightListTemp->next;
            }
            rightListTemp->next = head;
            leftListHead = NULL;
            rightListHead = NULL;
            return;
        }
        //if we haven't reached at the end of left list, call the function
        //for next node of left list. move one step ahead, and when we reach
        //at the end of left list, merge both left and right lists.
        rejoin(leftListTemp->next,rightListTemp);
        return;
    }

    void printList(Node* tempHead)
    {
        Node* dummy = tempHead;
        while(dummy)
        {
            cout<<dummy->data<<"->";
            dummy = dummy->next;
        }
        cout<<"NULL"<<endl;
    }

    void printList()
    {
        if(head==NULL)
        {
            cout<<"List is empty... Please consider adding some data"<<endl;
            return;
        }
        temp = head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        return;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in linked list" << endl;
    cout << "Press 2 to split linked list in two halves" << endl;
    cout << "Press 3 to rejoin lists back to its original condition" << endl;
    cout << "Press 4 to print list" << endl;
    cout << "Press -1 to exit" << endl;
    cin >> input;
    if (input < -1 || input > 4)
    {
        cout << "Please enter a valid input" << endl;
        cout << "-----------------------------------" << endl;
        return menu();
    }
    return input;
}

int main()
{
    int input=0;
    input = menu();
    LinkedList *ll = new LinkedList();
    while(input)
    {
        switch(input)
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
                ll->splitList();
                ll->printSeparatedList();
                input = menu();
                break;
            }
            case 3:
            {
                ll->rejoinList();
                ll->printList();
                ll->printSeparatedList();
                input = menu();
                break;
            }
            case 4:
            {
                ll->printList();
                ll->printSeparatedList();
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
        //break;
    }
}
