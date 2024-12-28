/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
//Example: 1->2->3->4->5, k=2
//It is an extension of reverse in pairs
//Use similar algorithm
//Intution:
//Reverse first block of k nodes
//make the last node of original block as new head of reversed block
//call recursion on next block for linking last node of current node(1->2->reverKGroup(3))
//return the newHead
public:
    ListNode* reverseKGroup(ListNode* tempHead, int k) {
        if(tempHead== NULL || tempHead->next == NULL || k == 0)
        {
            return tempHead;
        }
        ListNode *tempHeadCopy = tempHead;
        //confirm the availability of k nodes from head to end in list
        if (!HasKNodesLeft(tempHeadCopy, k))
        {
            //if not return tempHead
            //in above example when tempHead will point to 5
            //only 1 node will be available in list, then return
            //tempHead ie 5
            return tempHead;
        }
        //if k nodes are available from head
        tempHeadCopy = tempHead;
        //get head of next block
        //skip k places and get the head of next block
        ListNode *nextBlockHead = getNextBlockHead(tempHeadCopy,k);
        tempHeadCopy = tempHead;
        //reverse the current block using recursion
        tempHead = reverseBlock(tempHeadCopy, k-1);
        cout<<"HEad of reversed block:"<<tempHead->val<<endl;
        tempHeadCopy = tempHead;
        //reach till the end of current reversed block
        while (tempHeadCopy->next)
        {
            cout<<"tempHeadCopy:"<<tempHeadCopy->val<<"->";
            tempHeadCopy = tempHeadCopy->next;
        }
        cout<<endl;
        cout<<"-------------------------------------------"<<endl;
        //next of the end of current reversed block will be returned by recursion
        tempHeadCopy->next = reverseKGroup(nextBlockHead, k); 
        //return the new head
        return tempHead;
    }

    bool HasKNodesLeft(ListNode *tempHead, int k)
    {
        ListNode *tempHeadCopy = tempHead;
        int leftCount = 0;
        while (tempHead)
        {
            leftCount++;
            tempHead = tempHead->next;
        }
        cout<<"Count of number of nodes left:"<<leftCount<<endl;
        return leftCount >= k ? true : false;
    }

    ListNode* getNextBlockHead(ListNode* tempHead,int k)
    {
        while(k)
        {
            tempHead = tempHead->next;
            k--;
        }
        //cout<<"Next block head:"<<tempHead->val<<endl;
        return tempHead;
    }

    ListNode* reverseBlock(ListNode* tempHead, int k)
    {
        if(!k)
        {
            tempHead->next = NULL;
            return tempHead;
        }
        k--;
        cout<<"k:"<<k<<" tempHead->val:"<<tempHead->val<<endl;

        ListNode* newHead = reverseBlock(tempHead->next,k);
        ListNode* front = tempHead->next;
        front->next = tempHead;
        tempHead->next = NULL;
        return newHead;
    }
};
