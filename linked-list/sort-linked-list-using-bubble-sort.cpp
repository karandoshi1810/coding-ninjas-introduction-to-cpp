#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head = NULL;

public:
    void insertNode()
    {
        int nodeData = 0;
        cout << "Please enter node data" << endl;
        cin >> nodeData;
        Node *newNode = new Node(nodeData);

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

    // input: 10->30->20->5
    // Case: 10->5->20->30
    void bubbleSort()
    {
        Node *temp = head;
        int length = getLength(temp);
        cout<<"Length:"<<length<<endl;
        int itr = 0;
        while (itr < length)
        {
            Node *tempHead = head;
            Node *prevNode = head;
            while (tempHead->next)
            {
                Node *nextNode = tempHead->next;
                if (tempHead->data > nextNode->data)
                {
                    cout<<"TempHead>NextNode"<<endl;
                    if (tempHead == head)
                    {
                        cout<<"----------------------------------------------------------------------------------------------"<<endl;
                        cout<<"If matched"<<endl;
                        cout<<"PrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data"<<nextNode->data<<endl;
                        tempHead->next = nextNode->next;
                        nextNode->next = tempHead;
                        cout<<"Before PrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data"<<nextNode->data<<endl;
                        prevNode = nextNode;
                        head = prevNode;
                        cout<<"AfterPrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data"<<nextNode->data<<endl;
                        cout<<"----------------------------------------------------------------------------------------------"<<endl;
                    }
                    else
                    {
                        cout<<"Else matched"<<endl;
                        cout<<"PrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data:"<<nextNode->data<<endl;
                        printList();
                        tempHead->next = nextNode->next;
                        nextNode->next = tempHead;
                        cout<<"Before PrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data"<<nextNode->data<<endl;
                        printList();
                        //"prevNode"(10) will be still pointing to "tempHead"(30)
                        //we need to point it to "nextNode"(20) because of
                        //the swap in the previous step.
                        prevNode->next = nextNode;
                        //after the swap we need to keep prevNode on the previous node of the tempHead
                        //other wise we cannot use swap if required in the next iteration.
                        //Before swap: prevNode->tempHead->next
                        //After swap: prevnode->next->tempHead
                        //but we require: x->prevNode/nextNode->tempHead
                        //prevNode should be on the previous node of the tempHead
                        //hence we update the prevNode(10) pointer to point to nextNode(20)
                        prevNode = nextNode;
                        cout<<"After PrevNode:"<<prevNode->data<<" TempHead->data"<<tempHead->data<<" NextNode->data"<<nextNode->data<<endl;
                        printList();
                    }
                    continue;
                }
                //move to next node if tempHead->data < nextNode->data
                //as no swap is required in this case.
                prevNode = tempHead;
                tempHead = tempHead->next;
            }
            itr++;
        }
        // cout<<"Sorted List:"<<endl;
        // while(temp)
        // {
        //     cout<<temp->data<<"->";
        //     temp=temp->next;
        // }
        // cout<<endl;
        return;
    }

    int getLength(Node *temp)
    {
        Node *tempHead = temp;
        int length = 0;
        while (tempHead != NULL)
        {
            length++;
            tempHead = tempHead->next;
        }
        return length;
    }

    void printList()
    {

        if (head == NULL)
        {
            cout << "Linked list 1 is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in first linked list" << endl;
    cout << "Press 2 to sort linked list using bubble sort" << endl;
    cout << "Press 3 to get print list" << endl;
    cout << "Press -1 to exit" << endl;
    cin >> input;
    if (input < -1 || input > 7)
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
            ll->insertNode();
            ll->printList();
            input = menu();
            break;
        }
        case 2:
        {
            ll->bubbleSort();
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
    }
}
