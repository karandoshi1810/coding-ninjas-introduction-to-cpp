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
    Node *head = NULL, *temp = NULL;

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
    // Idea:
    /*
        Get the middle	of the	linked	list.
        Reverse	the	second	half	of	the	linked	list.
        Compare	the	first	half	and	second	half.
        Construct	the	original	linked	list	by	reversing	the	second	half	again	and
        attaching	it	back	to	the	first	half.
        
        Input: 1->0->1->0->NULL
     */
    bool checkPalindrome()
    {
        if (head == NULL)
        {
            cout << "List is empty..." << endl;
            return false;
        }
        Node *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            if (fast)
            {
                slow = slow->next;
            }
        }
        cout << "Slow->data:" << slow->data << endl;
        // separate the original list into 2 sub lists:
        // 1) head to slow
        // 2) slow->next to end of original list
        Node *rightListHead = slow->next;
        slow->next = NULL;
        //function which will reverse the list
        Node *reversedHeadFromMid = reverseFromMidOfLinkedList(rightListHead);
        //save the copy of reversed list head
        Node *reversedHeadFromMidCopy = reversedHeadFromMid;
        cout << "Printing left list after reversal" << endl;
        printList();
        cout << "Printing right list after reversal." << endl;
        while (reversedHeadFromMidCopy)
        {
            cout << reversedHeadFromMidCopy->data << "->";
            reversedHeadFromMidCopy = reversedHeadFromMidCopy->next;
        }
        cout << endl;
        temp = head;
        reversedHeadFromMidCopy = reversedHeadFromMid;
        //call function which will validate if the ll is palindrome or not
        //pass both left and right list.
        bool isPalindrome = validate(temp, reversedHeadFromMidCopy);
        cout << "Is palindrome:" << isPalindrome << endl;
        //rejoin both the left and right list
        //iterate left list till its next point to null
        temp = head;
        while (temp->next)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        reversedHeadFromMidCopy = reversedHeadFromMid;
        //reverse the reversed list(right) again and it will return the 
        //second half of original list.
        //point the left list's next to the node returned by the function after reversal.
        //It will create the original link back.
        temp->next = reverseFromMidOfLinkedList(reversedHeadFromMidCopy);
        printList();
        return isPalindrome;
    }
    bool validate(Node *headFromBeginning, Node *reversedHeadFromMid)
    {
        //if either of the list is null return true.
        //why true, because if we have reached this condition
        //that means the data of prevuious nodes were matching
        //hence the list was palindrome till here.
        if (headFromBeginning->next == NULL || reversedHeadFromMid->next == NULL)
        {
            return true;
        }
        //if current data of both lists is same then call recursion for
        //next nodes of both lists. Calling it will give rise to 2 possibilities
        //if the data of both the next nodes is not same it would return false and ultimately the function will return false
        //if either of them is NULL then the base condition will return true and eventually the function will return true.
        if (headFromBeginning->data == reversedHeadFromMid->data)
        {
            cout << "headFromBeginning->data == reversedHeadFromMid->data" << endl;
            return true && validate(headFromBeginning->next, reversedHeadFromMid->next);
        }
        else
        {
            return false;
        }
        return false;
    }
    Node *reverseFromMidOfLinkedList(Node *tempHead)
    {
        if (tempHead == NULL || tempHead->next == NULL)
        {
            return tempHead;
        }
        Node *newHead = reverseFromMidOfLinkedList(tempHead->next);
        Node *front = tempHead->next;
        front->next = tempHead;
        tempHead->next = NULL;
        return newHead;
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty... Please consider adding some data" << endl;
            return;
        }
        temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        return;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in linked list" << endl;
    cout << "Press 2 to check if list is palindrome or not" << endl;
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
            ll->checkPalindrome();
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
