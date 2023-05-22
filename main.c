#include "HouseholdLedger.h"

int main(void) {
  item *t[20];
  int order;

  FILE *f;
  
  int index = readfile(t, f);
  int count = index;

  while(1) {
    order = select_order();
    

    if (order == 1) {  //1. print item list
      if (count > 0) {
        list_item(t, index);
      }
      else {
        printf("=> There is no data\n");
      }
    }

    else if (order == 2) {  //2. add item
      t[index] = (item*)malloc(sizeof(item));
      count += add_item(t[index++]);
    }

    else if (order == 3) {  //3. update item
      int x = select_item(t, index);
      if (x == 0) {
        printf("=> cancelled\n");
        continue;
      }
      update_item(t[x-1]);
    }

    else if (order == 4) {  //4. delete item
      int x = select_item(t, index);
      if (x == 0) {
        printf("=> cancelled\n");
        continue;
      }

      int q;
      printf("Really delete? (deletd : 1) > ");
      scanf("%d", &q);

      if (q == 1) {
        if (t[x-1]) {
          delete_item(t, x);
          --count;
          printf("=> delete success\n");
          if (x == index) {
            --index;
          }
        }
      }
      else {
        printf("=> cancelled\n");
      }
    }

    else if (order == 5) {  //5. search item
      search_item(t, index);
    }

    // else if (order == 6) {  //6. 추가 기능
      
    // }

    else if (order == 0) {  //0. exit
      break;
    }
  }

  printf("\nprogram finish\n\n");

  if (count == 0) {
    printf("no data. can't save.\nfinish\n");
  }

  else {
    while(1) {
      getchar();
      printf("\nsave file? (save : 1, no : 2) >");
      scanf("%d", &order);
  
      if (order == 1) {
        printf("save? (yes : 1) > ");
        scanf("%d", &order);
  
        if (order == 1) {
          //save
          savefile(t, index);
          break;
        }
        else {
          continue;
        }
      }
        
      else if (order == 2) {
        printf("don't save? (yes : 1) > ");
        scanf("%d", &order);
  
        if (order == 1) {
          break;
        }
        else {
          continue;
        }
      }
        
      else {
        printf("wrong input\n");
      }
      fprintf(f, "\n");
    }
  }
}
