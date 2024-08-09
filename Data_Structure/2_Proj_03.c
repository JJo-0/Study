#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROB 2 // 다항식 저장 방법 선택

#if PROB == 1
// 배열을 이용한 다항식 표현 및 덧셈, 곱셈
#define MAX_TERM 101 //최대 차수 100
typedef struct polynomial {
	int degree;
	int coef[MAX_TERM];
}POLY;
void printPoly(const char *f, POLY a) {
	printf("%s = ", f);
	for (int i = a.degree; i >= 0; i--)
	{
		if (i < a.degree && a.coef[a.degree - i] > 0) printf("   +");
		else printf("   ");
		printf("%dX^%d", a.coef[a.degree - i], i);
	}
	printf("\n");
}

POLY addPoly(POLY a, POLY b) {
	POLY c;
	int A = 0, B = 0, C = 0;
	int degree_a = a.degree, degree_b = b.degree;

	if (degree_a > degree_b) c.degree = degree_a;
	else c.degree = degree_b;

	while (A <= a.degree && B <= b.degree) {
		if (degree_a > degree_b) {
			c.coef[C++] = a.coef[A++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			c.coef[C++] = a.coef[A++] + b.coef[B++];
			degree_a--; degree_b--;
		}
		else {
			c.coef[C++] = b.coef[B++];
			degree_b--;
		}
	}
	return c;
}

POLY mulPoly(POLY a, POLY b) {
	POLY c;
	
	c.degree = a.degree + b.degree;
	for (int i = 0; i <= c.degree; i++) {
		c.coef[i] = 0;
	}

	for (int i = 0; i <= a.degree; i++) {
		for (int j = 0; j <= b.degree; j++) {
			c.coef[i + j] += a.coef[i] * b.coef[j];
		}
	}

	return c;
}

int main(void) {
	POLY a = { 5, {3, 0, 4, -2, 1, 7} }; // a(x) = 3x5 + 4x3 - 2x2 + 1x + 7
	POLY b = { 3, {4, 2, -6, -3} }; // b(x) = 4x3 + 2x2 - 6x - 3
	POLY c, d; //for result
	printPoly("a(x)", a);
	printPoly("b(x)", b);
	c = addPoly(a, b);
	printPoly("c(x) = a(x) + b(x) ", c);
	d = mulPoly(a, b);
	printPoly("d(x) = a(x) x b(x) ", d);
	return 0;
}

#elif PROB == 2
#define MAX_TERM 101 //최대 차수 100
typedef struct term { int coef; int exp; } TERM;		//	계수 차수
typedef struct polynomial {
	int num_of_terms;				
	TERM terms[MAX_TERM];
}POLY;
// 여기에 필요한 함수 구현
void printPoly(const char* f, POLY a) {
	printf("%s = ", f);
	for (int i = 0; i < a.num_of_terms; i++) {
		if (i > 0 && a.terms[i].coef > 0) printf("   +");
		else printf("   ");
		printf("%dX^%d", a.terms[i].coef, a.terms[i].exp);
	}
	printf("\n");

	return;
}
char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}
void attach(POLY* a, int coef, int exp) {
	if (a->num_of_terms >= MAX_TERM) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	a->terms[a->num_of_terms].coef = coef;
	a->terms[a->num_of_terms].exp = exp;
	a->num_of_terms++;
}
POLY addPoly(POLY a, POLY b) {
	POLY c;
	c.num_of_terms = 0;
	int aPos = 0, bPos = 0;
	while (aPos < a.num_of_terms && bPos < b.num_of_terms) {
		switch (compare(a.terms[aPos].exp, b.terms[bPos].exp)) {
		case '>':
			attach(&c, a.terms[aPos].coef, a.terms[aPos].exp);
			aPos++;
			break;
		case '=':
			if (a.terms[aPos].coef + b.terms[bPos].coef != 0) {
				attach(&c, a.terms[aPos].coef + b.terms[bPos].coef, a.terms[aPos].exp);
			}
			aPos++;
			bPos++;
			break;
		case '<':
			attach(&c, b.terms[bPos].coef, b.terms[bPos].exp);
			bPos++;
			break;
		}
	}
	for (; aPos < a.num_of_terms; aPos++) {
		attach(&c, a.terms[aPos].coef, a.terms[aPos].exp);
	}
	for (; bPos < b.num_of_terms; bPos++) {
		attach(&c, b.terms[bPos].coef, b.terms[bPos].exp);
	}
	return c;
}
POLY mulPoly(POLY a, POLY b) {
	POLY c;
	c.num_of_terms = 0;

	int temp[MAX_TERM * 2] = { 0 }; 

	for (int i = 0; i < a.num_of_terms; i++) {
		for (int j = 0; j < b.num_of_terms; j++) {
			int exp = a.terms[i].exp + b.terms[j].exp; // 지수의 합
			int coef = a.terms[i].coef * b.terms[j].coef; // 계수의 곱
			temp[exp] += coef;
		}
	}

	for (int i = MAX_TERM * 2 - 1; i >= 0; i--) {
		if (temp[i] != 0) {
			attach(&c, temp[i], i);
		}
	}

	return c;
}
int main(void) {
	POLY a = { 5, {3,5, 4,3, -2,2, 1,1, 7,0} }; // a(x) = 3x5 + 4x3 - 2x2 + 1x + 7
	POLY b = { 4, {4,3, 2,2, -6,1, -3,0} }; // b(x) = 4x3 + 2x2 - 6x - 3
	POLY c, d; //for result
	printPoly("a(x)", a);
	printPoly("b(x)", b);
	c = addPoly(a, b);
	printPoly("c(x) = a(x) + b(x) ", c);
	d = mulPoly(a, b);
	printPoly("d(x) = a(x) x b(x) ", d);
	return 0;
}

#elif PROB == 3
// 0이 아닌 계수를 연결리스트로 다항식 표현
typedef struct poly {
	int coef;
	int exp;
	struct poly* link;
}POLY;
// 여기에 필요한 함수 구현
POLY* add(POLY* head, POLY* node) {
	if (head == NULL) {
		return node;
	}
	else {
		POLY* p = head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = node;
		return head;
	}
}
void printPoly(const char* name, POLY* head) {
	printf("%s = ", name);
	POLY* p = head;
	while (p != NULL) {
		if (p != NULL && p->coef >= 0) {
			printf("   +");
		}
		else printf("   ");
		printf("%dx^%d ", p->coef, p->exp);
		p = p->link;
	}
	printf("\n");
}

POLY* addPoly(POLY* a, POLY* b) {
	POLY* result = NULL, * temp, * prev = NULL;
	while (a != NULL && b != NULL) {
		temp = (POLY*)malloc(sizeof(POLY));
		if (temp == NULL) { printf("Memory Allocation Error"); exit(-1); }
		temp->link = NULL;

		if (a->exp > b->exp) {
			temp->coef = a->coef;
			temp->exp = a->exp;
			a = a->link;
		}
		else if (a->exp < b->exp) {
			temp->coef = b->coef;
			temp->exp = b->exp;
			b = b->link;
		}
		else { // a->exp == b->exp
			temp->coef = a->coef + b->coef;
			temp->exp = a->exp;
			a = a->link;
			b = b->link;
		}

		if (result == NULL) {
			result = temp;
		}
		else {
			prev->link = temp;
		}
		prev = temp;
	}

	// 남은 항 추가
	while (a != NULL) {
		temp = (POLY*)malloc(sizeof(POLY));
		if (temp == NULL) { printf("Memory Allocation Error"); exit(-1); }
		temp->coef = a->coef;
		temp->exp = a->exp;
		temp->link = NULL;
		prev->link = temp;
		prev = temp;
		a = a->link;
	}
	while (b != NULL) {
		temp = (POLY*)malloc(sizeof(POLY));
		if (temp == NULL) { printf("Memory Allocation Error"); exit(-1); }
		temp->coef = b->coef;
		temp->exp = b->exp;
		temp->link = NULL;
		prev->link = temp;
		prev = temp;
		b = b->link;
	}

	return result;
}
POLY* mulPoly(POLY* a, POLY* b) {
	POLY* result = NULL, * p, * q, * temp, * tail = NULL;
	for (p = a; p != NULL; p = p->link) {
		for (q = b; q != NULL; q = q->link) {
			temp = (POLY*)malloc(sizeof(POLY));
			if (temp == NULL) { printf("Memory Allocation Error"); exit(-1); }
			temp->coef = p->coef * q->coef;
			temp->exp = p->exp + q->exp;
			temp->link = NULL;
			POLY* r = result;
			POLY* prev = NULL;
			int added = 0;
			while (r != NULL && r->exp >= temp->exp) {
				if (r->exp == temp->exp) {
					r->coef += temp->coef;
					if (r->coef == 0) { // 계수가 0이 되는 경우 해당 항을 제거
						if (prev != NULL) {
							prev->link = r->link;
						}
						else {
							result = r->link;
						}
						free(r);
					}
					added = 1;
					break;
				}
				prev = r;
				r = r->link;
			}
			if (!added) {
				if (prev == NULL) {
					temp->link = result;
					result = temp;
				}
				else {
					temp->link = prev->link;
					prev->link = temp;
				}
			}
			else {
				free(temp);
			}
		}
	}

	return result;
}
void del(POLY* head) {
	POLY* temp;
	while (head != NULL) {
		temp = head;
		head = head->link;
		free(temp);
	}
}
int main(void) 
{
	POLY* a = NULL; // a(x) = 3x5 + 4x3 - 2x2 + 1x + 7
	POLY* b = NULL; // b(x) = 4x3 + 2x2 - 6x - 3
	POLY* c = NULL, * d = NULL, * tmp = NULL; //for result
	//A 초기화 a(x) = 3x5 + 4x3 - 2x2 + 1x + 7
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 3; tmp->exp = 5; tmp->link = NULL;
	a = add(a, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 4; tmp->exp = 3; tmp->link = NULL;
	a = add(a, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = -2; tmp->exp = 2; tmp->link = NULL;
	a = add(a, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 1; tmp->exp = 1; tmp->link = NULL;
	a = add(a, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 7; tmp->exp = 0; tmp->link = NULL;
	a = add(a, tmp);
	printPoly("a(x)", a);
	//B 초기화 b(x) = 4x3 + 2x2 - 6x - 3
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 4; tmp->exp = 3; tmp->link = NULL;
	b = add(b, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = 2; tmp->exp = 2; tmp->link = NULL;
	b = add(b, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = -6; tmp->exp = 1; tmp->link = NULL;
	b = add(b, tmp);
	tmp = (POLY*)malloc(sizeof(POLY));
	if (tmp == NULL) { printf("Memory Allocation Error"); exit(-1); }
	tmp->coef = -3; tmp->exp = 0; tmp->link = NULL;
	b = add(b, tmp);
	printPoly("b(x)", b);
	// 다항식 합
	c = addPoly(a, b);
	printPoly("c(x) = a(x) + b(x) ", c);
	// 다항식 곱
	d = mulPoly(a, b);
	printPoly("d(x) = a(x) x b(x) ", d);
	// 연결리스트 삭제
	del(a); del(b); del(c); del(d);
	return 0;
}
#endif