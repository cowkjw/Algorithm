#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

struct Node
{
	int data;
	Node* prev;
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
	node[nodeCnt].prev = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		node[i].data = 0;
		node[i].next = nullptr;
		node[i].prev = nullptr;
	}
	nodeCnt = 0;
	head = nullptr;
}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
		newNode->next->prev = newNode;
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
				newNode->prev = ptr;
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
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
			newNode->next->prev = newNode;
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
		if (ptr->next == nullptr)
		{
			ptr->next = newNode;
			newNode->prev = ptr;
		}
		else
		{

			newNode->next = ptr->next;
			ptr->next = newNode;
			newNode->prev = ptr;
			newNode->next->prev = newNode;
		}
	}

}

int findNode(int data)
{
	Node* find = head;
	int cnt = 1;
	while (find != nullptr)
	{
		if (find->data == data)
			return cnt;
		find = find->next;
		cnt++;

	}
	return 0;
}

void removeNode(int data)
{
	Node* prev = head;
	Node* cur = head;

	if (head->data == data)
	{
		head = head->next;

	}
	else
	{
		while (cur != nullptr)
		{
			if (cur->data == data)
			{
				prev->next = cur->next;
				if(prev->next != nullptr)
					prev->next->prev=prev;
				cur->data = 0;
				cur->next = nullptr;
				cur->prev = nullptr;
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

int getReversedList(int output[MAX_NODE])
{

	Node* ptr = head;
	int idx = 0;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}

	while (ptr != nullptr)
	{
		output[idx] = ptr->data;
		ptr = ptr->prev;

		idx++;
	}

	return idx;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			printf("출력:");
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			printf("리버스 출력:");
			while (cnt--)
				printf("%d ", output[i++]);
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

