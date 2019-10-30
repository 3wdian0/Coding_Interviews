#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL){}
};

void _print(ListNode *pHead){
	while(pHead!=NULL){
		cout<<pHead->val<<" ";
		pHead = pHead->next;
	}
	cout<<endl;
}
/*
*
*
*               p1
*               |
*              [2] --> [4] --> [1] --> [8]
* 
*               p2 
*               |
*              [4] --> [1] --> [1] --> [5] --> [3]
* 
*               p 
*               |
*    pHead --> [ ] 
* 
* 
*/
ListNode * merge(ListNode * p1, ListNode * p2){

    // 如果有链表为空返回 另一个 链表
	if(p1==NULL){
		return p2;
	}
	if(p2==NULL){
		return p1;
	}

    // 初始化合并的链表 
	ListNode *pHead, *p;
	if(p1->val < p2->val){
		pHead = p1;
		p1 = p1->next;
	}else{
		pHead = p2;
		p2 = p2->next;
	}
	p = pHead;

    // 开始合并
	while(p1!=NULL && p2!=NULL){
		if(p1->val < p2->val){
			p->next = p1;
			p1 = p1->next;			
		}else{
			p->next = p2;
			p2 = p2->next;
		}
		p = p->next;
	}

    // 结尾处理
	if(p1==NULL)
		p->next = p2;
	if(p2==NULL)
		p->next = p1;
	return pHead;
			
}

int main(int argc, char *argv []){
	ListNode * p1 = new ListNode(1);
	p1->next      = new ListNode(2);
	p1->next->next= new ListNode(4);
	p1->next->next->next = new ListNode(8);

    ListNode * p2 = new ListNode(1);
    p2->next      = new ListNode(1);
    p2->next->next= new ListNode(3);
    p2->next->next->next       = new ListNode(4);
    p2->next->next->next->next = new ListNode(5);


	_print(p1);
	_print(p2);
	ListNode * pHead = merge(p1,p2);
	_print(pHead);
	return 0;
}
