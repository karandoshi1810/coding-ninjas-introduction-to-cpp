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
    Node *temp = head;

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
        temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }

    void sort()
    {
        temp = head;
        mergeSort(temp);
    }

    Node* mergeSort(Node *tempHead)
    {
        if (tempHead == nullptr || tempHead->next == nullptr)
        {
            return tempHead;
        }
        Node *secondHalf = split(tempHead);
        cout<<"secondHalf->data:"<<secondHalf->data<<" tempHead->data:"<<tempHead->data<<endl;
        tempHead = mergeSort(tempHead);
        cout<<"Calling for second half:"<<secondHalf->data<<endl;
        secondHalf = mergeSort(secondHalf);

        Node* sorted =  merge(tempHead,secondHalf);
        temp = sorted;
        cout<<"Sorted list"<<endl;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
        return sorted;
    }

    Node* merge(Node* firstHalf, Node* secondHalf)
    {
        // cout<<"Firsthalf->data:"<<firstHalf->data<<" secondhalf->data:"<<secondHalf->data<<endl;
        if(firstHalf == NULL)
        {
            // cout<<"First half is null. Returning second half. SeconfHalf->data:"<<secondHalf->data<<endl;
            return secondHalf;
        }
        if(secondHalf == NULL)
        {
            // cout<<"Second half is null. Returning first half. FirstHalf->data:"<<secondHalf->data<<endl;
            return firstHalf;
        }
        if(firstHalf->data <= secondHalf->data)
        {
             cout<<"firstHalf->data <secondHalf->data. firstHalf->data:"<<firstHalf->data<<" SecondHalf->data:"<<secondHalf->data<<endl;
             printList(firstHalf);
            // cout<<"FirstHalf->next:"<<firstHalf->next<<" FirstHalf->next->data:"<<firstHalf->next->data<<endl;
            firstHalf->next = merge(firstHalf->next,secondHalf);
            cout<<"Returning first half"<<firstHalf->data<<endl;
            return firstHalf;
        }
        else
        {
            cout<<"secondHalf->data < firstHalf->data. firstHalf->data:"<<firstHalf->data<<" SecondHalf->data:"<<secondHalf->data<<endl;
            printList(secondHalf);
            secondHalf->next = merge(firstHalf,secondHalf->next);
            cout<<"Returning second half"<<secondHalf->data<<endl;
            return secondHalf;
        }
        cout<<"No condition satisfied. Returning NULL"<<endl;
        return NULL;
    }
    Node *split(Node *tempHead)
    {
        Node *fast = tempHead, *slow = tempHead;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            if (fast)
            {
                slow = slow->next;
            }
        }
        cout<<"Slow(mid)->data:"<<slow->data<<endl;
        Node* tempSlow = slow->next;
        slow->next = NULL;
        return tempSlow;
    }

    void printList(Node* tempHead)
    {
        Node* t = tempHead;
        while(t)
        {
            cout<<t->data<<"->";
            t=t->next;
        }
        cout<<endl;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty... Please consider adding some nodes" << endl;
            return;
        }
        temp = head;
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
    cout << "Press 2 to sort linked list using merge sort" << endl;
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
                ll->sort();
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
        //break;
    }
}
