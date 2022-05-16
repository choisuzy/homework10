#include <stdio.h>
#include <stdlib.h>

typedef struct node { /* struct Node에 타입이 다른 데이터들을 그룹화 */
	int key; /* key를 int형으로 선언 */
	struct node *left; /* 구조체 Node포인터 left를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
	struct node *right; /* 구조체 Node포인터 right를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
} Node; /* 구조체 호출용 이름 */                                                                  

/* for stack */
#define MAX_STACK_SIZE 20 /* MAX_STACK_SIZE를 20으로 정의 */
Node* stack[MAX_STACK_SIZE]; /* Node 포인터 stack을 선언 */
int top = -1; /* 정수형 top을 -1로 선언 */

Node* pop(); /* Node 포인터 pop함수 선언 */
void push(Node* aNode); /* push함수 선언 */

/* for queue */
#define MAX_QUEUE_SIZE 20 /* MAX_STACK_SIZE를 20으로 정의 */
Node* queue[MAX_QUEUE_SIZE]; /* Node 포인터 queue를 선언 */
int front = -1; /* 정수형 front를 -1로 선언 */
int rear = -1; /* 정수형 rear을 -1로 선언 */

Node* deQueue(); /* Node 포인터 deQueue함수 선언 */
void enQueue(Node* aNode); /* enQueue함수 선언 */


int initializeBST(Node** h); /* initializeBST함수 선언 */

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


void printStack(); /* stack을 print하는 함수 선언 */



int main()
{
	char command; /* command를 char형으로 선언 */
	int key; /* key를 int형으로 선언 */
	Node* head = NULL; /* Node포인터 head를 빈공간으로 지정 */

    printf("[----- [Choi Suzy]  [2021024135] -----]\n");

	do{
		printf("\n\n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */
		printf("                   Binary Search Tree #2                        \n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */
		printf(" Initialize BST       = z      printStack                   = p \n"); /* print */
		printf(" Insert Node          = i      Delete Node                  = d \n"); /* print */
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n"); /* print */
		printf(" Level Order (Queue)  = l      Quit                         = q \n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */

		printf("Command = "); /* print */
		scanf(" %c", &command); /* char형 command를 입력자에게 입력받음 */

		switch(command) { /* command가 ~이면 조건문 */
		case 'z': case 'Z': /* command가 z나 Z면 */
			initializeBST(&head); /* initializeBST 함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 'q': case 'Q': /* command가 q나 Q이면 */
			freeBST(head); /* freeBST 함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 'i': case 'I': /* command가 i나 I면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insert(head, key); /* insert 함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 'd': case 'D': /* command가 d나 D면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			deleteNode(head, key); /* deleteNode 함수 실행 */
			break; /* 조건식을 빠져나옴 */

		case 'r': case 'R': /* command가 r이나 R이면 */
			recursiveInorder(head->left); /* recursiveInorder 함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 't': case 'T': /* command가 t나 T면 */
			iterativeInorder(head->left); /* iterativeInorder 함수 실행 */
			break; /* 조건식을 빠져나옴 */

		case 'l': case 'L': /* command가 l이나 L이면 */
			levelOrder(head->left); /* levelOrder 함수 실행 */
			break; /* 조건식을 빠져나옴 */

		case 'p': case 'P': /* command가 p나 P면 */
			printStack(); /* printStack 함수 실행 */
			break; /* 조건식을 빠져나옴 */

		default: /* 위의 알파벳이 다 아니면 */
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); /* print */
			break; /* 조건식을 빠져나옴 */
		}

	}while(command != 'q' && command != 'Q'); /* command가 q가 아니고 Q가 아니라면 do루프 계속 돎 */

	return 1; /* 1을 반환함 */
}

int initializeBST(Node** h) { /* 이중포인터를 매개변수로 하여 binary-search-tree를 초기화하는 함수 정의 */

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) /* 포인터 headNode가 NULL이 아니면 */
		freeBST(*h); /* 할당된 메모리를 모두 해제시키는 freeBST 함수 호출 */

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); /* Node크기만큼을 동적할당한 Node포인터를 포인터h에 넣음 */
	(*h)->left = NULL;	/* root */ /* 포인터h의 left부분을 빈공간으로 만듦 */
	(*h)->right = *h; /* 포인터h의 right부분에 포인터h를 넣음 */
	(*h)->key = -9999; /* 포인터h의 key부분에 -9999를 넣음 */

	top = -1; /* top을 -1로 지정 */

	front = rear = -1; /* front와 rear을 -1로 지정 */

	return 1; /* 1를 반환함 */
}



void recursiveInorder(Node* ptr) /* recursive방식으로 반복적 중위 순회하는 함수 */
{
	if(ptr) { /* ptr이 ~라면 */
		recursiveInorder(ptr->left); /* recursiveInorder 함수 실행 */
		printf(" [%d] ", ptr->key); /* print */
		recursiveInorder(ptr->right); /* recursiveInorder 함수 실행 */
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node) /* iterative방식으로 반복적 중위 순회하는 함수 */
{
	for(;;) /* for문 반복 */
	{
		for(; node; node = node->left) /* node가 node의 left부분과 같다면 for문 반복 */
			push(node); /* node를 push함 */ /* 스택에 삽입 */
		node = pop(); /* node에 pop함수를 넣음 */

		if(!node) break; /* 공백 스택 *//* node가 아니라면 조건식 빠져나옴 */
		printf(" [%d] ", node->key); /* print */

		node = node->right; /* node에 node의 right부분을 넣음 */
	}
}

/**
 * textbook: p 225 
 */
void levelOrder(Node* ptr) /* 레벨 순서 조회하는 함수 */
{
	// int front = rear = -1;

	if(!ptr) return; /* empty tree */

	enQueue(ptr); /* enQueue 함수 실행 */

	for(;;) /* for문 반복 */
	{
		ptr = deQueue(); /* ptr에 deQueue함수를 넣음 */
		if(ptr) { /* ptr이라면 */
			printf(" [%d] ", ptr->key); /* print */

			if(ptr->left) /* ptr의 left부분이라면 */
				enQueue(ptr->left); /* enQueue 함수 실행 */
			if(ptr->right) /* ptr의 right부분이라면 */
				enQueue(ptr->right); /* enQueue 함수 실행 */
		}
		else /* ptr이 아니라면 */
			break; /* 조건식을 빠져나옴 */

	}

}


int insert(Node* head, int key) /* 트리에 노드를 삽입하는 함수 정의 */
{
	Node* newNode = (Node*)malloc(sizeof(Node)); /* Node크기만큼을 동적할당한 Node포인터를 Node포인터 newNode에 넣음 */
	newNode->key = key; /* newNode의 key부분에 key값을 넣음 */
	newNode->left = NULL;  /* newNode의 left부분을 빈공간으로 만듦 */
	newNode->right = NULL; /* newNode의 right부분을 빈공간으로 만듦 */

	if (head->left == NULL) { /* head의 left부분이 빈공간이라면 */
		head->left = newNode; /* newNode를 head의 left부분에 넣음 */
		return 1; /* 1을 반환함 */
	}

	/* head->left is the root */
	Node* ptr = head->left; /* head의 left부분을 Node포인터 ptr에 넣음 */

	Node* parentNode = NULL; /* Node포인터 parentNode를 빈공간으로 만듦 */
	while(ptr != NULL) { /* ptr이 null이 아니라면 */

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1; /* ptr의 key부분이 key라면 1을 반환함 */

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr; /* parentNode에 ptr을 넣음 */

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key) /* ptr의 key부분이 key보다 작다면 */
			ptr = ptr->right; /* ptr에 ptr의 right부분을 넣음 */
		else /* ptr의 key부분이 key보다 작지 않다면 */
			ptr = ptr->left; /* ptr에 ptr의 left부분을 넣음 */
	}

	/* linking the new node to the parent */
	if(parentNode->key > key) /* parentNode의 key부분이 key보다 크다면 */
		parentNode->left = newNode; /* parentNode의 left부분에 newNode를 넣음 */
	else /* ptr의 key부분이 key보다 크지 않다면 */
		parentNode->right = newNode; /* parentNode의 right부분에 newNode를 넣음 */
	return 1; /* 1을 반환함 */
}


int deleteNode(Node* head, int key) /* 트리에 노드를 삭제하는 함수 정의 */
{
	if (head == NULL) { /* head가 빈공간이라면 */
		printf("\n Nothing to delete!!\n"); /* print */
		return -1; /* -1을 반환함 */
	}

	if (head->left == NULL) { /* head의 left부분이 빈공간이라면 */
		printf("\n Nothing to delete!!\n"); /* print */
		return -1; /* -1을 반환함 */
	}

	/* head->left is the root */
	Node* root = head->left; /* Node포인터 root에 head의 left부분을 넣음 */



	Node* parent = NULL; /* Node포인터 parent를 빈공간으로 만듦 */
	Node* ptr = root; /* Node포인터 ptr에 root를 넣음 */

	while((ptr != NULL)&&(ptr->key != key)) { /* ptr이 빈공간이 아니고 ptr의 key부분이 key가 아니라면 */
		if(ptr->key != key) { /* ptr의 key부분이 key가 아니라면 */

			parent = ptr;	/* save the parent */

			if(ptr->key > key) /* ptr의 key부분이 key보다 크다면 */
				ptr = ptr->left;  /* ptr에 ptr의 left부분을 넣음 */
			else /* ptr의 key부분이 key보다 크지 않다면 */
				ptr = ptr->right; /* ptr에 ptr의 right부분을 넣음 */
		}
	}

	/* there is no node for the key */
	if(ptr == NULL) /* ptr이 빈공간이라면 */
	{
		printf("No node for key [%d]\n ", key); /* print */
		return -1; /* -1을 반환함 */
	}

	/*
	 * case 1: the node which has to be removed is a leaf node
	 */
	if(ptr->left == NULL && ptr->right == NULL) /* ptr의 left부분이 빈공간이면서 ptr의 right부분이 빈공간이라면*/
	{
		if(parent != NULL) { /* parent exists, parent's left and right links are adjusted */
			if(parent->left == ptr) /* parent의 left부분이 ptr이라면 */
				parent->left = NULL; /* parent의 left부분을 빈공간으로 만듦 */
			else /* parent의 left부분이 ptr이 아니라면 */
				parent->right = NULL; /* parent의 right부분을 빈공간으로 만듦 */
		} else { /* parent가 빈공간이라면 */
			/* parent is null, which means the node to be deleted is the root */
			head->left = NULL; /* head의 left부분을 빈공간으로 만듦 */

		}

		free(ptr); /* ptr을 free시킴 */
		return 1; /* 1을 반환함 */
	}

	/**
	 * case 2: if the node to be deleted has one child
	 */
	if ((ptr->left == NULL || ptr->right == NULL)) /* ptr의 left부분이 빈공간이거나 ptr의 right부분이 빈공간이라면*/
	{
		Node* child; /* Node포인터 child 선언 */
		if (ptr->left != NULL)  /* ptr의 left부분이 빈공간이 아니라면 */
			child = ptr->left; /* child에 ptr의 left부분을 넣음 */
		else /* ptr의 left부분이 빈공간이라면 */
			child = ptr->right;  /* child에 ptr의 right부분을 넣음 */

		if(parent != NULL) /* parent가 빈공간이 아니라면 */
		{
			if(parent->left == ptr) /* parent의 left부분이 ptr이라면 */
				parent->left = child; /* parent의 left부분에 child를 넣음 */
			else /* parent의 left부분이 ptr이 아니라면 */
				parent->right = child; /* parent의 right부분에 child를 넣음 */
		} else { /* parent가 빈공간이라면 */
			/* parent is null, which means the node to be deleted is the root
			 * and the root has one child. Therefore, the child should be the root
			 */
			root = child; /* root에 child를 넣음 */
		}

		free(ptr); /* ptr을 free시킴 */
		return 1; /* 1을 반환함 */
	}

	/**
	 * case 3: the node (ptr) has two children
	 *
	 * we have to find either the biggest descendant node in the left subtree of the ptr
	 * or the smallest descendant in the right subtree of the ptr.
	 *
	 * we will find the smallest descendant from the right subtree of the ptr.
	 *
	 */

	Node* candidate; /* Node포인터 candidate 선언 */
	parent = ptr; /* parent에 ptr을 넣음 */


	candidate = ptr->right; /* candidate에 ptr의 right부분을 넣음 */

	/* the smallest node is left deepest node in the right subtree of the ptr */
	while(candidate->left != NULL) /* candidate의 left부분이 빈공간이 아니라면 */
	{
		parent = candidate; /* parent에 candidate를 넣음 */
		candidate = candidate->left; /* candidate에 candidate의 left부분을 넣음 */
	}

	/* the candidate node is the right node which has to be deleted.
	 * note that candidate's left is null
	 */
	if (parent->right == candidate) /* parent의 right부분이 candidate라면 */
		parent->right = candidate->right; /* parent의 right부분에 candidate의 right부분을 넣음 */
	else  /* parent의 right부분이 candidate이 아니라면 */
		parent->left = candidate->right; /* parent의 left부분에 candidate의 right부분을 넣음 */

	/* instead of removing ptr, we just change the key of ptr
	 * with the key of candidate node and remove the candidate node
	 */

	ptr->key = candidate->key; /* ptr의 key부분에 candidate의 key부분을 넣음 */

	free(candidate); /* candidate을 free시킴 */
	return 1; /* 1을 반환함 */
}


void freeNode(Node* ptr) /* 노드를 해제하는 함수 정의 */
{
	if(ptr) { /* ptr이 ~라면 */
		freeNode(ptr->left); /* freeNode 함수 실행 */
		freeNode(ptr->right); /* freeNode 함수 실행 */
		free(ptr); /* ptr을 free시킴 */
	}
}

int freeBST(Node* head) /* 트리에 할당된 모든 메모리를 해제하는 함수 정의 */
{

	if(head->left == head) /* head의 left 부분이 head라면 */
	{
		free(head); /* head를 free시킴 */
		return 1; /* 1을 반환함 */
	}

	Node* p = head->left; /* head의 left부분을 Node포인터 p에 넣음 */

	freeNode(p); /* freeNode 함수 실행 */

	free(head);  /* head를 free시킴 */
	return 1; /* 1을 반환함 */
}



Node* pop() /* Node 포인터 pop함수 */
{
	if (top < 0) return NULL; /* top이 0보다 작다면 빈공간을 반환함 */
	return stack[top--]; /* stack[top--]를 반환함 */
}

void push(Node* aNode) /* push함수 */
{
	stack[++top] = aNode; /* stack[++top]에 aNode를 넣음 */
}


void printStack() /* 스택을 print하는 함수 */
{
	int i = 0; /* 정수형 i를 0으로 지정 */
	printf("--- stack ---\n"); /* print */
	while(i <= top) /* i가 top보다 작거나 같다면 */
	{
		printf("stack[%d] = %d\n", i, stack[i]->key); /* print */
	}
}


Node* deQueue() /* Node 포인터 deQueue함수 */
{
	if (front == rear) { /* front와 rear이 같다면 */
		// printf("\n....Now Queue is empty!!\n" );
		return NULL; /* 빈공간을 반환함 */
	}

	front = (front + 1) % MAX_QUEUE_SIZE; /* front를 front+1만큼 MAXqueue사이즈 지정 */
	return queue[front]; /* queue[front]를 반환함 */

}

void enQueue(Node* aNode) /*enQueue함수 */
{
	rear = (rear + 1) % MAX_QUEUE_SIZE; /* rear를 rear+1만큼 MAXqueue사이즈 지정 */
	if (front == rear) { /* front와 rear이 같다면 */
		// printf("\n....Now Queue is full!!\n");
		return; /* 반환함 */
	}

	queue[rear] = aNode; /* queue[rear]에 aNode를 넣음 */
}