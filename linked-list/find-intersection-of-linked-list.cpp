#include <iostream>
#include <unordered_map>
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *originalListRef = NULL;

public:
    void insertNode(int listNumber)
    {
        int nodeData = 0;
        cout << "Please enter node data" << endl;
        cin >> nodeData;
        Node *newNode = new Node(nodeData);
        switch (listNumber)
        {
        case 1:
        {
            if (head1 == NULL)
            {
                head1 = newNode;
                return;
            }
            Node *temp1 = head1;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = newNode;
            break;
        }
        case 2:
        {
            if (head2 == NULL)
            {
                head2 = newNode;
                return;
            }
            else
            {
                Node *temp2 = head2;
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = newNode;
                return;
            }
            break;
        }
        default:
        {
            break;
        }
        }
        return;
    }

    void addIntersection(int sourceList, int sourceNode, int destinationNode)
    {
        if (findIntersectionUsingHashTables())
        {
            return;
        }
        else
        {
            if (sourceList == 1)
            {
                cout << "sourceList == 1" << endl;
                Node *temp1 = head1;
                Node *temp2 = head2;
                cout << "Temp1->data:" << temp1->data << " Temp2->data:" << head2->data << endl;
                int L1 = findLength(temp1);
                int L2 = findLength(temp2);
                cout << "L1:" << L1 << " L2:" << L2 << endl;
                if (sourceNode > L1 || L1 == 0)
                {
                    cout << "Source node does not exist" << endl;
                    return;
                }
                cout << "Before second condition" << endl;
                if (destinationNode > L2 || L2 == 0)
                {
                    cout << "Destination node does not exist" << L2 << " " << destinationNode << " Head2:" << head2->data << endl;
                    return;
                }
                cout << "First While loop" << endl;
                cout << "After first while loop temp1->data:" << temp1->data << " sourceNode:" << sourceNode << endl;
                while (sourceNode > 1)
                {
                    sourceNode--;
                    temp1 = temp1->next;
                }
                cout << "Second While loop" << endl;
                while (destinationNode > 1)
                {
                    destinationNode--;
                    temp2 = temp2->next;
                }
                cout << "After first while loop temp1->data:" << temp2->data << " destinationNode:" << destinationNode << endl;
                cout << "Adding an intersection" << endl;
                originalListRef = temp1->next;
                temp1->next = temp2;
                return;
            }
            else
            {
                Node *temp1 = head2;
                Node *temp2 = head1;
                int L1 = findLength(temp1); // length of ll2
                int L2 = findLength(temp2); // length of ll
                if (sourceNode > L1 || L1 == 0)
                {
                    cout << "Source node does not exist" << endl;
                    return;
                }
                cout << "Before second condition" << endl;
                if (destinationNode > L2 || L2 == 0)
                {
                    cout << "Destination node does not exist" << endl;
                    return;
                }
                cout << "First While loop" << endl;
                while (sourceNode > 1)
                {
                    sourceNode--;
                    temp1 = temp1->next;
                }
                cout << "After first while loop temp1->data:" << temp1->data << " sourceNode:" << sourceNode << endl;
                cout << "Second While loop" << endl;
                while (destinationNode > 1)
                {
                    destinationNode--;
                    temp2 = temp2->next;
                }
                cout << "After first while loop temp1->data:" << temp2->data << " destinationNode:" << destinationNode << endl;
                cout << "Adding an intersection" << endl;
                originalListRef = temp1->next;
                temp1->next = temp2;
            }
            return;
        }
        return;
    }

    bool findIntersectionUsingHashTables()
    {
        Node *temp1 = head1, *temp2 = head2, *shortListHead = NULL, *longListHead = NULL;
        unordered_map<Node *, int> table;
        int L1 = findLength(temp1);
        int L2 = findLength(temp2);

        if (L1 > L2)
        {
            shortListHead = head2;
            longListHead = head1;
        }
        else if (L2 > L1)
        {
            shortListHead = head1;
            longListHead = head2;
        }
        while (shortListHead != NULL)
        {
            table[shortListHead] = shortListHead->data;
            shortListHead = shortListHead->next;
        }
        for (auto it : table)
        {
            cout << "Key:" << it.first << " Value:" << it.second << endl;
        }
        while (longListHead != NULL)
        {
            cout << "Long List:" << longListHead << " Long List Data:" << longListHead->data << endl;
            auto it = table.find(longListHead);
            if (it != table.end())
            {
                cout << "The intersection point exists." << endl;
                cout << "The intersecting node is:" << longListHead->data << endl;
                return true;
            }
            longListHead = longListHead->next;
        }
        cout << "No intersection exists" << endl;
        return false;
    }

    bool finsIntersectionUsingOptimizedApproach()
    {
        Node *temp1 = head1, *temp2 = head2;
        int L1 = 0, L2 = 0, lengthDiff = 0;
        L1 = findLength(temp1);
        L2 = findLength(temp2);
        cout << "Length 1:" << L1 << " Length2:" << L2 << endl;
        if (L1 >= L2)
        {
            temp1 = head1;
            temp2 = head2;
            lengthDiff = L1 - L2;
        }
        else
        {
            temp1 = head2;
            temp2 = head1;
            lengthDiff = L2 - L1;
        }
        cout << "temp1:" << temp1->data << " temp2:" << temp2->data << endl;
        while (lengthDiff)
        {
            temp1 = temp1->next;
            lengthDiff--;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
            {
                cout << "The intersection point exists." << endl;
                cout << "The intersecting node is:" << temp1->data << endl;
                return true;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        cout << "Intersection does not exist" << endl;
        return false;
    }

    void removeIntersection()
    {
        Node *temp1 = head1, *temp2 = head2;
        int L1 = 0, L2 = 0, lengthDiff = 0;
        L1 = findLength(temp1);
        L2 = findLength(temp2);
        cout << "Length 1:" << L1 << " Length2:" << L2 << endl;
        if (L1 >= L2)
        {
            temp1 = head1;
            temp2 = head2;
            lengthDiff = L1 - L2;
        }
        else
        {
            temp1 = head2;
            temp2 = head1;
            lengthDiff = L2 - L1;
        }
        cout << "temp1:" << temp1->data << " temp2:" << temp2->data << endl;
        while (lengthDiff)
        {
            temp1 = temp1->next;
            lengthDiff--;
        }
        // the while loop will display the intersection node.

        // but we do not node of intersection, we need node
        // previous to it(previous node of intersecting node).

        // Because the previous node(shadowTemp) will unlink itself
        // from the intersecting node link itself back to its
        // remaining list.
        Node *shadowTemp = NULL;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
            {
                cout << "The intersection point exists." << endl;
                cout << "The intersecting node is:" << temp1->data << endl;
                shadowTemp->next = originalListRef;
                return;
            }
            shadowTemp = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        cout << "Intersection does not exist" << endl;
        return;
    }

    int findLength(Node *head)
    {
        Node *tempHead = head;
        int length = 0;
        while (tempHead != NULL)
        {
            length++;
            tempHead = tempHead->next;
        }
        return length;
    }

    void printList(int input)
    {
        switch (input)
        {
        case 1:
        {

            if (head1 == NULL)
            {
                cout << "Linked list 1 is empty" << endl;
                return;
            }
            Node *temp1 = head1;
            while (temp1 != NULL)
            {
                cout << temp1->data << "->";
                temp1 = temp1->next;
            }
            cout << endl;
            break;
        }
        case 2:
        {
            if (head2 == NULL)
            {
                cout << "Linked list2 is empty" << endl;
                return;
            }
            Node *temp2 = head2;
            while (temp2 != NULL)
            {
                cout << temp2->data << "->";
                temp2 = temp2->next;
            }
            cout << endl;
            break;
        }
        default:
        {
            break;
        }
        }
        return;
    }
};

int menu()
{
    int input = 0;
    cout << "Press 1 to insert node in first linked list" << endl;
    cout << "Press 2 to insert node in second linked list" << endl;
    cout << "Press 3 to insert an intersection" << endl;
    cout << "Press 4 to find intersection using hash tables" << endl;
    cout << "Press 5 to find intersection using optimized approach" << endl;
    cout << "Press 6 to get print list" << endl;
    cout << "Press 7 to remove intersection" << endl;
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
            ll->insertNode(input);
            ll->printList(input);
            input = menu();
            break;
        }
        case 2:
        {
            ll->insertNode(input);
            ll->printList(input);
            input = menu();
            break;
        }
        case 3:
        {
            int listNumber = 0, sourceNode = 0, destinationNode = 0;
            cout << "Please enter from which list you want to add intersection" << endl;
            cin >> listNumber;
            cout << "Please enter source node of from the linked list" << endl;
            cin >> sourceNode;
            cout << "Please enter destination node of to linked list" << endl;
            cin >> destinationNode;
            cout << "List number entered by user:" << listNumber << endl;
            ll->addIntersection(listNumber, sourceNode, destinationNode);
            ll->printList(1);
            ll->printList(2);

            input = menu();
            break;
        }
        case 4:
        {
            ll->findIntersectionUsingHashTables();
            input = menu();
            break;
        }
        case 5:
        {
            ll->finsIntersectionUsingOptimizedApproach();
            input = menu();
            break;
        }
        case 6:
        {
            ll->printList(1);
            ll->printList(2);
            input = menu();
            break;
        }
        case 7:
        {
            ll->removeIntersection();
            input=menu();
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
