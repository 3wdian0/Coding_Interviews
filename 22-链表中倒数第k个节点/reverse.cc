#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL) {}
};

void _print(ListNode *pHead){
	while(pHead!=NULL){
		cout<<pHead->val<<" ";
		pHead = pHead->next;
	}
	cout<<endl;
}

void reverseK(ListNode *pHead){
	
}
int main(int argc, char * argv[]){
	ListNode * pHead = new ListNode(1);
	pHead->next      = new ListNode(2);
	pHead->next->next= new ListNode(3);
	pHead->next->next->next= new ListNode(4);
	_print(pHead);
	return 0;
}
