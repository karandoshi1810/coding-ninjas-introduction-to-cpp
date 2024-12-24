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

    Node *getTail(Node *tempHead)
    {
        while (tempHead && tempHead->next)
        {
            tempHead = tempHead->next;
        }
        return tempHead;
    }

    // void quickSortHelper(Node *tempHead, Node *tail)
    // {
    //     if (tempHead == NULL || tempHead == tail)
    //     {
    //         return;
    //     }
    //     Node *pivot = tempHead;
    //     Node *curr = tempHead;
    //     while (curr)
    //     {
    //         if (pivot->data > curr->data)
    //         {
    //             swap(curr->data,tempHead->data);
    //             pivot = curr;
    //             curr = curr->next;
    //             continue;

    //         }
    //         curr = curr->next;
    //     }
    //     quickSortHelper(tempHead,pivot);
    //     quickSortHelper(pivot->next,tail);
    // }
    void quickSortHelper(Node *tempHead, Node *tail)
    {
        if (tempHead == NULL || tempHead == tail)
        {
            return;
        }
        Node *pivot = tempHead;
        cout<<"Pivot:"<<pivot->data<<" tempHead->data"<<tempHead->data<<endl;
        Node *curr = tempHead;
        Node *listOfNumbersSmallerThanPivot=tempHead;
        while (curr!=tail->next)
        {
            cout<<"Curr->data:"<<curr->data<<" listOfNumbersSmallerThanPivot->data:"<<listOfNumbersSmallerThanPivot->data<<endl;
            if (pivot->data > curr->data)
            {
                cout<<"Condition satisifed. listOfNumbersSmallerThanPivot->next->data:"<<listOfNumbersSmallerThanPivot->next->data<<endl;
                swap(curr->data,listOfNumbersSmallerThanPivot->next->data);
                listOfNumbersSmallerThanPivot=listOfNumbersSmallerThanPivot->next;
            }
            curr = curr->next;
        }
        curr=tempHead;
        swap(pivot->data,listOfNumbersSmallerThanPivot->data);
                while(curr)
        {
            cout<<curr->data<<"->";
            curr = curr->next;
        }
        cout<<endl;
        quickSortHelper(tempHead,listOfNumbersSmallerThanPivot);
        cout<<"Calling for right sub-list. listOfNumbersSmallerThanPivot->next->data:"<<listOfNumbersSmallerThanPivot->next->data<<" listOfNumbersSmallerThanPivot->data:"<<listOfNumbersSmallerThanPivot->data<<" tail->data:"<<tail->data<<endl;
        quickSortHelper(listOfNumbersSmallerThanPivot->next,tail);
    }
    // input: 10->30->20->5
    // Case: 10->5->20->30
    void quickSort()
    {
        Node *temp = head;
        Node *tail = getTail(temp);
        temp = head;
        quickSortHelper(head, tail);
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
            cout << "Linked list is empty" << endl;
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
    cout << "Press 2 to sort linked list using quick sort" << endl;
    cout << "Press 3 to get print list" << endl;
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
            ll->insertNode();
            ll->printList();
            input = menu();
            break;
        }
        case 2:
        {
            ll->quickSort();
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
