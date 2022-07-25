#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

struct Node
{
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
int output[MAX_NODE] = { 0 };
Node* getNode(int data)
{
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		node[i].data = 0;
		node[i].next = nullptr;
	}
	nodeCnt = 0;
	head = nullptr;

}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);
	if (head == nullptr)
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}

}

void addNode2Tail(int data)
{
	Node* newNode = getNode(data);
	Node* ptr = head;
	if (head == nullptr)
		head = newNode;
	else
	{

	while (ptr != nullptr)
	{
		if (ptr->next == nullptr)
		{
			ptr->next = newNode;
			break;
		}
		ptr = ptr->next;
	}
	}
}

void addNode2Num(int data, int num)
{
	Node* ptr = head;
	Node* newNode = getNode(data);
	int cnt = 1;
	if (num == 1)
	{
		if (head == nullptr)
			head = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	else
	{

		while (cnt != num)
		{
			cnt++;
			if (cnt != num)

				ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}

}

void removeNode(int data)
{
	Node* prev = head;
	Node* cur = head;

	if (head->data == data)
		head = head->next;
	else
	{
		while (cur != nullptr)
		{
			if (cur->data == data)
			{
				prev->next = cur->next;
				cur->data = 0;
				cur->next = nullptr;
				break;
			}
			prev = cur;
			cur = cur->next;
		}

	}
}

int getList(int output[MAX_NODE])
{

	Node* ptr = head;
	int idx = 0;
	while (ptr != nullptr)
	{
		output[idx] = ptr->data;
		ptr = ptr->next;
		idx++;

	}

	return idx;
}


static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);

			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			printf("¸®½ºÆ®:");
			while (cnt--)
				printf(" % d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}

