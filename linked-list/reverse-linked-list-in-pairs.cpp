//Reference: https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/
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

    void reverseInPairs()
    {
        Node *temp=head;
        Node *newHead = reverse(temp);
        cout<<"Updated List"<<endl;
        temp = newHead;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
        head = newHead;
    }

    //the idea is to swap the links of first pair and call recursion to handle the rest of the pairs.
    //Input:1->2->3->4->5
    //Output:2->1->4->3->5
    //First Pair:1->2
    //Store the link to 3rd node(3) in a variable called nextPairHead or remainingList
    //Store 2nd node(2) as newHead in a variable
    //Change the link such that the 2nd node(2) should point to 1st node(1)
    //the next of 1st node(1) should point to 4th node(4). This change will be handled by recursion.
    //Call the recursion with nextPairHead as its parameter

    //Simulation for 1->2->3->4->5. here tempHead is 1.
    //Final Output:2->1->4->3->5

    //nextPairHead=3
    //newHead=2
    //change link and point 2 to 1
    //2->1->reverse(nextPairHead) 
        //nextPairHead=5
        //newHead=4
        //change link and point 4 to 3
        //4->3->reverse(nextPairHead)
            //base case satisfied(5->next=NULL) return temphead
        //4->3->5
        //return the newHead i.e. 4
    //2->1->4->3->5
    //return the newHead i.e. 2
    Node* reverse(Node* tempHead)
    {
        if(tempHead==NULL || tempHead->next == NULL)
        {
            return tempHead;
        }
        //store the pointer to 3rd node from head in nextPairHead
        Node *nextPairHead = tempHead->next->next;
        //the second node will be the new head of the linked list
        //hence store it in newHead pointer and return it.
        Node *newHead = tempHead->next;
        //change the link. Next of second node will point to first node instead of second
        tempHead->next->next = tempHead;
        //the next of first node will be decided by the recursion
        tempHead->next = reverse(nextPairHead);
        //return the new head of the lined list.
        return newHead;
    }
    int findLength(Node *temp)
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
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << endl;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in first linked list" << endl;
    cout << "Press 2 to insert node in second linked list" << endl;
    cout << "Press 3 to reverse linked list in paris" << endl;
    cout << "Press 4 to get print list" << endl;
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
            ll->insertNode();
            ll->printList();
            input = menu();
            break;
        }
        case 3:
        {
            ll->reverseInPairs();
            ll->printList();
            input = menu();
            break;
        }
        case 4:
        {
            ll->printList();
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
