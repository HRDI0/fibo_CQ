#include <stdio.h>
#include <stdlib.h>

//============원형 큐 코드 시작
#define MAX_SIZE 10

typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;

}Qtype;

//오류 출력
void error(char* messege) {
	fprintf(stderr, "%s\n", messege);
	exit(1);
}
//공백상태로 초기화
void init_queue(Qtype* q) {
	q->front = q->rear = 0;
}

//공백상태 검사
int is_empty(Qtype* q) {
	return(q->front == q->rear);
}
//포화 상태 검사
int is_full(Qtype * q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}
//원형 큐 출력
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

//삽입 함수
void enq(Qtype * q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");

	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

//삭제 함수
element deq(Qtype * q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//피보나치 입력 함수
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

//===========원형 큐 코드 끝

int main() {
	Qtype the_Q;
	int num = 0;
	init_queue(&the_Q);
	enq(&the_Q, 0);
	enq(&the_Q, 1);
	printf("몇번째 피보나치 수를 원하는가? : ");
	scanf_s("%d",&num);
	printf("%d",pibo(&the_Q,(num-1)));
}