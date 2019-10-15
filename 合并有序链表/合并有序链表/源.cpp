#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node *next;
};
// �ϲ���������
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2){
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	Node *rHead = NULL; // �������
	Node *last = NULL;  // ��¼ rHead �����һ�����
	Node *c1 = l1;  // ���� l1 ����
	Node *c2 = l2;  // ���� l2 ����

	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node *next = c1->next;
			// �� c1 β�嵽 rHead
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
			// �� c2 β�嵽 rHead
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

	// ֻ��һ������Ľ�㱻��������
	// ʣ��Ľ��һ�����ٱ� last �����ֵҪ��
	// last ������ rHead �е����һ�����
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