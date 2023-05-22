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
//리스트 출력 시 틀 출력
void print_head();
//명령어 목록 출력
int select_order();

//CRUD
//create
int add_item(item *t);
//read
void read_item(item *t);
//select (update와 delete에 사용)
int select_item(item *t[], int count);
//update
int update_item(item *t);
//delete
int delete_item(item *t[], int count);

//리스트 전체 출력
void list_item(item *t[], int count);

//가계부 기능
//분야별 지출 내역 조회
void read_item_type(item *t[], int count);

//총 지출 조회
void total_expense(item *t[], int count);
//사용자와 또래지출 비교
void compare_expense(item *t[], int count);
//지출 예정 기록
void expense_plan(item *t[], int count);

//search 기능
void search_item(item *t[], int count);

//FILE 저장 및 수정
//파일 읽기
int readfile(item *t[], FILE *f);
//파일 저장
void savefile(item *t[], int count);

