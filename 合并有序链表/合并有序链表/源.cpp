#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node *next;
};
// 合并有序链表
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2){
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	Node *rHead = NULL; // 结果链表
	Node *last = NULL;  // 记录 rHead 的最后一个结点
	Node *c1 = l1;  // 遍历 l1 链表
	Node *c2 = l2;  // 遍历 l2 链表

	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node *next = c1->next;
			// 把 c1 尾插到 rHead
			c1->next = NULL;
			if (rHead == NULL) {
				rHead = c1;
			}
			else {
				last->next = c1;
			}
			last = c1;

			c1 = next;
		}
		else {
			Node *next = c2->next;
			// 把 c2 尾插到 rHead
			c2->next = NULL;
			if (rHead == NULL) {
				rHead = c2;
			}
			else {
				last->next = c2;
			}
			last = c2;

			c2 = next;
		}
	}

	// 只是一个链表的结点被处理完了
	// 剩余的结点一定至少比 last 结点中值要大
	// last 是现在 rHead 中的最后一个结点
	if (c1 != NULL) {
		last->next = c1;
	}
	else {
		last->next = c2;
	}

	return rHead;
}
int main(){
	
	return 0;
}