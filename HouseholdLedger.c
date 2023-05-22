#include "HouseholdLedger.h"

//기본기능
void print_head() {
  printf("\nNo  in-out     Name      Amount     Type\n");
  printf("========================================\n");
}

//CRUD
//create
int add_item(item *t) {
  printf("income : 1, expend : 0\n");
  printf("input number > ");
  scanf("%d", &t->in_or_out);
  printf("input name > ");  //지출 및 수입 기록명
  scanf("%s", t->name);
  printf("input amount > ");
  scanf("%d", &t->price);
  printf("항목 나열 ~~\n"); //지출, 수입 종류 추가적으로 생각해서 나열? or 문자열로 받아서 구별  어찌되든 개선 필요
  printf("input type > ");
  scanf("%d", &t->type);

  return 1;
}
//read
void read_item(item *t) {
  char k[5] = "";
  if (t->in_or_out == 1) {
    strcat(k, "in");
  }
  else {
    strcat(k, "out");
  }
  printf("%4s %8s %10d %10d\n", k, t->name, t->price, t->type);
}
//update
int update_item(item *t) {
  
}
//delete
int delete_item(item *t[], int x) {
  free(t[x-1]);
  t[x-1] = NULL;
  return 1;
}

//리스트 전체 출력
void list_item(item *t[], int count) {
  int i;
  print_head();

  for (i = 0; i < count; ++i) {
    if (t[i] == NULL) {
      continue;
    }
    printf("%2d ", i+1);
    read_item(t[i]);
  }
}

//가계부 기능
//분야별 지출 내역 조회
void read_item_type(item t) {  //분야 항목 다시 생각해서 코드 짜야함
  
}
//총 지출 조회 

//사용자와 또래지출 비교

//지출 예정 기록


//FILE 저장 및 수정
