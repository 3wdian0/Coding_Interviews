#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x),next(NULL) {}
};

// 链表中环的入口节点
/*
 *   p-----
 *   |     |
 *  [1] -> |
 * 
 *   p------
 *   |      |
 *  [1] -> [2]
 *
 *   p-------------
 *   |             |
 *  [1] -> [2] -> [3]
 *
 *   p              ---------------------------
 *   |             |                           |
 *  [1] -> [2] -> [3] -> [4] -> [5] -> [6] -> [7]
 * 
 *   1      1
 *   2      3
 *   3      5
 *   4      7
 *   5      4
 *   6      6
 *   7      3
 *   3      5
 *   4      7
 *   5      4
 *   6      6
 *   7      3
 *   3      5
 *   4      7
 *   5      5
 */

void circle(ListNode *pHead){
    if(pHead==NULL){
        cout<<"空链表"<<endl;
        return;
    }
    if(pHead->next == pHead){
        cout<<pHead->val<<endl;
        return;
    }

    ListNode * p1 = pHead;
    ListNode * p2 = pHead;
    ListNode * node;
    // 找到环
    while(p1!=NULL){
        cout<<p1->val<<" "<<p2->val<<endl;
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1==p2){
            cout<<p1->val<<endl;
            node = p1;
        }
    }
    p1 = pHead;
    while(p1!=NULL){

        if(p1==node){
            cout<<"环入口:"<<p1->val<<endl;
            return ;
        }
        p2 = node->next;
        while(p2!=node){
            //
            if(p1==p2){
                cout<<"环入口:"<<p1->val<<endl;
                return ;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}
int main(int argc, char * argv[]){
    ListNode * pHead                    = new ListNode(1);
    pHead->next                         = new ListNode(2);
    pHead->next->next                   = new ListNode(3);
    pHead->next->next->next             = new ListNode(4);
    pHead->next->next->next->next       = new ListNode(5);
    pHead->next->next->next->next->next             = new ListNode(6);
    pHead->next->next->next->next->next->next       = new ListNode(7);
    pHead->next->next->next->next->next->next->next = pHead->next->next;
    circle(pHead);
    return 0;
}
