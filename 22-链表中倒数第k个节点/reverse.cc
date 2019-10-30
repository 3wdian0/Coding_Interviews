#include<iostream>
#include<string>

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

// 法一
void reverseK(ListNode *pHead, int k){

    // 第一件事
    if(k<1)
        return;

    ListNode * p = pHead;
    int length = 0;
    while(p!=NULL){
        length += 1;
        p = p->next;
    }

    if(k>length){
        cout<<"k长度超过链表长度"<<endl;
        return ;
    }

    int m = length - k + 1; //顺序第m个
    length = 0;
    p = pHead;
    while(p!=NULL){
        length += 1;
        if(m==length){
            cout<<p->val<<endl;
            return;
        }
        p = p->next;
    }
}

// 法二
void reverseKv2(ListNode *pHead, int k){
    ListNode *p1 = pHead;
    ListNode *p2 = pHead;
    int i = 0;

    while(i<k && p1!=NULL){
        i += 1;
        p1 = p1->next;
    }
    if(i<k-1){
        cout<<"长度不够"<<endl;
    }
    while(p1!=NULL){
        p1 = p1->next;
        p2 = p2->next; // 因为p2落后于p1，所以该处使用p安全
    }

    if(p2!=NULL){
        // 如果不加该判断，在k=0时，输出的则是最后一个节点的next，即NULL
        // 鲁棒性：所有在使用p->val和p->next的地方都要判断 p!=NULL
        cout<<p2->val<<endl;
    }
}
int main(int argc, char * argv[]){
	ListNode * pHead = new ListNode(1);
	pHead->next      = new ListNode(2);
	pHead->next->next= new ListNode(3);
	pHead->next->next->next= new ListNode(4);
	pHead->next->next->next->next= new ListNode(5);
	_print(pHead);
    int k = 30;
    reverseK(pHead, k);
    reverseK(pHead, 0);
    reverseK(pHead, 1);
    reverseK(pHead, 2);
    reverseKv2(pHead, 0);
    reverseKv2(pHead, 1);
    reverseKv2(pHead, 2);
    reverseKv2(pHead, -2);
	return 0;
}
