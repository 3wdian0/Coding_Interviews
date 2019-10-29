#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL) {}
};

void _print(ListNode * pHead){
    ListNode * p = pHead;
    while(p!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

/*
 *    pHead               pHead
 *      |                   |
 *     [ ]                 [1]
 */

/*
 *    pHead               pHead
 *      |                   |
 *     [1] --> [2]         [1] --> [2] --> [3]
 */

/*
 *            pHead                       pHead
 *              |                           |
 *     [1] <-- [2]         [1] <-- [2] <-- [3]
 */


/*
 *    pHead             p       m       t
 *      |               |       |       |
 *     [1] <-- [2] <-- [3] --> [4] --> [5] --> [6] --> [7]
 *
 *    pHead                     p       m       t
 *      |                       |       |       |
 *     [1] <-- [2] <-- [3] <-- [4] --> [5] --> [6] --> [7]
 *
 *    pHead                             p       m       t
 *      |                               |       |       |
 *     [1] <-- [2] <-- [3] <-- [4] <-- [5] --> [6] --> [7]
 *
 *    pHead                                     p       m       t
 *      |                                       |       |       |
 *     [1] <-- [2] <-- [3] <-- [4] <-- [5] <-- [6] --> [7]     [ ]
 */




ListNode * reverse(ListNode * pHead){
    /*
    if(pHead==NULL){
        throw("head不存在");
    }
    */
    if(pHead==NULL|| pHead->next==NULL){
        // 链表为空
        // 链表长度为1
        return pHead;
    }
    ListNode *p=NULL;
    ListNode *m=pHead;
    ListNode *t=pHead->next;
    while(t!=NULL){
        m->next = p;
        p = m;
        m = t;
        t = t->next;
    }
    m->next = p;
    return m;
}

int main(int argc, char * argv[]){
    ListNode * pHead = new ListNode(1);
    pHead->next      = new ListNode(2);
    pHead->next->next= new ListNode(3);
    pHead->next->next->next= new ListNode(4);
    _print(pHead);
    pHead = reverse(pHead);
    _print(pHead);
    return 0;
}
