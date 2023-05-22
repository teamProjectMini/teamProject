#include "HouseholdLedger.h"

//기본기능
//리스트 출력 시 틀 출력
void print_head() {
  printf("\nNo  in-out     Name      Amount     Type\n");
  printf("========================================\n");
}
//명령어 목록 출력
int select_order() {
  int order;
  
  printf("\n\n-----HouseholdLedger-----\n");
  printf("1. print item list\n");
  printf("2. add item\n");
  printf("3. update item\n");
  printf("4. delete item\n");
  printf("5. search item\n");
  printf("6. total expense\n");
  printf("7. compare expense\n");
  printf("8. plan expense\n");
  printf("0. exit");
  printf("\nchoose order > ");
  scanf("%d", &order);

  return order;
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

  printf("=> add success\n\n");
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
//select (update와 delete에 사용)
int select_item(item *t[], int count) {
  int n;
  
  list_item(t, count);
  printf("select number > ");
  scanf("%d", &n);

  return n;
}
//update
int update_item(item *t) {
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

  printf("=> update success\n\n");
  return 1;
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
void total_expense(item *t[], int count){
  int i;
  int total = 0; 
  for(i = 0; i < count; i++){
    if(t[i]->in_or_out==0)total+=t[i]->price;
  }
  printf("The current total expenditure is %d won.\n",total);
  
}

//사용자와 또래지출 비교
void compare_expense(item *t[], int count){
  int ageType;
  int averageTotal[4]={17500,40000,64000,288000};
  
  printf("Which age bracket are you?\n");
  printf("1. Elementary school students\n");
  printf("2. Middle school student\n");
  printf("3. High school student\n");
  printf("4. College students\n");
  printf("Select type -> ");
  scanf("%d",&ageType);
  
  int i;
  int total = 0; 
  for(i = 0; i < count; i++){
    if(t[i]->in_or_out==0)total+=t[i]->price;
  }

  printf("\n");
  if(ageType == 1){
    printf("The average monthly expenditure of elementary school students in Korea is %d won.\n", averageTotal[0]);
  }
  else if(ageType == 2){
    printf("The average monthly expenditure of middle school students in Korea is %d won.\n", averageTotal[1]);
  }
  else if(ageType == 3){
    printf("The average monthly expenditure of high school students in Korea is %d won.\n",averageTotal[2]);
  }
  else if(ageType == 4){
    printf("The average monthly expenditure of college students in Korea is %d won.\n",averageTotal[3]);
  }
  if(averageTotal[ageType-1]+10000 < total)printf("Currently, your expenditure is relatively higher than the average expenditure of your age group in Korea. You have to manage your money properly.\n");
  else printf("Your current expenditure is less than the average expenditure of your age group in Korea. You're managing your money properly:)");
}
//지출 예정 기록


//search 기능
void search_item(item *t[], int count) {
  char fitem[50];
  int x = 0;
  int i;

  printf("search item name > ");
  scanf("%s", fitem);

  for (i = 0; i < count; ++i) {
    if (t[i] == NULL) {
      continue;
    }
    if (strstr(t[i]->name, fitem)) {
      if (x == 0) {
        print_head();
      }
      printf("%2d ", i+1);
      read_item(t[i]);
      ++x;
    }
  }

  if (x == 0) {
    printf("No such data\n");
  }
  printf("\n");
}

//FILE 저장 및 수정
  //파일 직접 건들면 오류 발생 가능성 有 (마지막 줄넘김 없어야 정상 작동)
//파일 읽기
int readfile(item *t[], FILE *f) {
  printf("\n");
  
  if ((f = fopen("HouseholeLedger.txt", "r"))) {
    printf("Found file\n");

    int i = 0;
    while(!(feof(f))) {
      //printf("%d\n", i);
      t[i] = (item*)malloc(sizeof(item));
      fscanf(f, "%d %s %d %d", &t[i]->in_or_out, t[i]->name, &t[i]->price, &t[i]->type);

      ++i;
    }
    fclose(f);

    return i;
  }
  else {
    printf("No file\n");
    return 0;
  }
}
//파일 저장
void savefile(item *t[], int count) {
  FILE *f;
  int k = count - 1;
  int i;

  f = fopen("HouseholeLedger.txt", "w");

  for (i = 0;; ++i) {
    if (t[i] == NULL) {
      continue;
    }
    fprintf(f, "%d %s %d %d", t[i]->in_or_out, t[i]->name, t[i]->price, t[i]->type);
    if (i == k) {
      printf("end\n");
      break;
    }
    fprintf(f, "\n");
  }
}
