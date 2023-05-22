#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
typedef struct {
	char name[50];	//항목명
	int in_or_out;	//수입:  1, 지출: 0	수입, 지출 예정 여부도 포함?
	int price; 	//수입 및 지출 금액
	int type;	//분야, 항목	각 번호 정할 필요 有
} item;

//기본기능
void print_head();

//CRUD
//create
int add_item(item *t);
//read
void read_item(item *t);
//update
int update_item(item *t);
//delete
int delete_item(item *t[], int count);

//리스트 전체 출력
void list_item(item *t[], int count);

//가계부 기능
//분야별 지출 내역 조회
void read_item_type(item t);
//총 지출 조회

//사용자와 또래지출 비교

//지출 예정 기록


//FILE 저장 및 수정
