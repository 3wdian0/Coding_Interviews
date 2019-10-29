#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) :val(x),next(NULL){}
};
void _print(ListNode *pHead){
    ListNode * p = pHead;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

void PrintListReversingly_Recursively(ListNode *pHead){
    if(pHead!=NULL){
        // 把链表看成一课只有左孩子的二叉树
        //cout 前序遍历???
        PrintListReversingly_Recursively(pHead->next);
        //cout 后序遍历???
        cout<<pHead->val<<" ";
    }else{
        return ;
    }
}
void PrintListReversingly_Iteratively(ListNode *pHead){
    stack<ListNode *> s;
    ListNode * p = pHead;
    while(p!=NULL){
        s.push(p);
        p = p->next;
    }
    while(!s.empty()){
        p = s.top();
        cout<<p->val<<" ";
        s.pop();
    }

}
int main(int argc, char * argv[]){
    ListNode * pHead = new ListNode(1);
    pHead->next      = new ListNode(2);
    pHead->next->next= new ListNode(3);
    _print(pHead);
    PrintListReversingly_Recursively(pHead); cout<<endl;
    //_print(pHead);
    PrintListReversingly_Iteratively(pHead); cout<<endl;
    return 0;
}
