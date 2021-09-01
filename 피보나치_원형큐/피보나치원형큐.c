#include <stdio.h>
#include <stdlib.h>

//============���� ť �ڵ� ����
#define MAX_SIZE 10

typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;

}Qtype;

//���� ���
void error(char* messege) {
	fprintf(stderr, "%s\n", messege);
	exit(1);
}
//������·� �ʱ�ȭ
void init_queue(Qtype* q) {
	q->front = q->rear = 0;
}

//������� �˻�
int is_empty(Qtype* q) {
	return(q->front == q->rear);
}
//��ȭ ���� �˻�
int is_full(Qtype * q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}
//���� ť ���
void queue_print(Qtype * q) {
	printf("Queue(fornt = %d rear = %d)\n", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_SIZE;
			printf(" %d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

//���� �Լ�
void enq(Qtype * q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");

	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

//���� �Լ�
element deq(Qtype * q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//�Ǻ���ġ �Է� �Լ�
element pibo(Qtype* q, int num) {
	int i = 0;
	element pibo_num;
	element pibo_num2 = 1;
	if (num == 0 || num == 1) {
		return 1;
	}
	for (i = 0; i < num; i++) {
		pibo_num = deq(q);
		enq(q, (pibo_num + pibo_num2));
		pibo_num2 = (pibo_num + pibo_num2);
	}
	return q->data[q->rear];
}

//===========���� ť �ڵ� ��

int main() {
	Qtype the_Q;
	int num = 0;
	init_queue(&the_Q);
	enq(&the_Q, 0);
	enq(&the_Q, 1);
	printf("���° �Ǻ���ġ ���� ���ϴ°�? : ");
	scanf_s("%d",&num);
	printf("%d",pibo(&the_Q,(num-1)));
}