#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct node {
	int data;
	node *next;

	node() {
		data = 0;
		next = NULL;
	}

	node(int _data, node *_next) {
		data = _data;
		next = _next;
	}
};


struct linkedList {
	node *head;

	void printList() {
		for (node *cur = head; cur != NULL; cur = cur->next) {
			cout << cur->data << " -> " ;
		}
		cout << '\n';
	}

	void deleteNode(int key) {
		node *curNode = head; // storing the address of current node
		node *prevNode = NULL;  //storing the address of previous node
		while (curNode && curNode->data != key) {
			prevNode = curNode;
			curNode = curNode->next;
		}
		// while loop will break for either of 2 reasons:
		//1. key not found, in this case the curNode == NULL
		//2. key found and curNode is not null but prevnode can be null if the key value is in the head node
		if (curNode) {
			if (prevNode) {
				prevNode->next = curNode->next;
				delete curNode;
			} else {
				head = curNode->next;
				delete curNode;
			}
		}
	}

	int insertNode(int index, int data) {
		if (index < 0)return 0; // when index is negative

		int curIndex = 1;
		node *curNode = head;
		while (curIndex < index && curNode) {
			curIndex++;
			curNode = curNode->next;
		}

		if (curNode == NULL)return 0;  // if the index is greater than the length of the size of linked list

		node *newNode = new node(data, NULL);
		if (index == 0) {  // inserting as a head
			newNode->next = head;
			head = newNode;
		} else {
			newNode->next = curNode->next;
			curNode->next = newNode;
		}
		return 1;
	}
};



int main() {
	linkedList a , b;
	for (int i = 1; i <= 7; i++) {
		int x;
		cin >> x;
		if (i == 1) {
			a.head = new node(x, NULL);
		} else a.head = new node(x, a.head);
	}
	a.printList();
	// a.deleteAfterNode(a.head->next->next);
	// a.printList();
	// a.deleteAfterNode(7);
	// a.printList();
	// a.deleteFirst();
	// a.printList();
	// a.deleteLast();
	// a.printList();
	// a.insertLast(100);
	// a.printList();
	// a.insertAfterNode(a.head->next->next, 50);
	// a.printList();
	// a.insertFirst(17);
	// a.printList();
	a.insertNode(3, 100);
	a.printList();
	return 0;
}