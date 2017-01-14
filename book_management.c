#include <stdio.h>
#include <windows.h>
void drawLine(int, char);
void addBlank(int);
void show_MainMenu();
void addBook();
void search_books();
void manage_books();
int compare_str(char*, char*);
void copy_str(char*, char*);
char book_title[100][30];
char book_author[100][20];
char book_publisher[100][15];
int current_book_number = 0;
int state[100]={'0'}; // having : 0, borrowing : 1
int main(void) {
  show_MainMenu();
  return 0;
}
void drawLine(int count, char word) {
  while(count--) {
    printf("%c", word);
  }
  return;
}
void addBlank(int count) {
  while(count--) {
    printf(" ");
  }
  return;
}
void show_MainMenu() {
  system("cls");
  int behave_choice;
  drawLine(30, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(3);
  printf("도서 관리 프로그램 v.1");
  addBlank(3);
  drawLine(1, '*');
  printf("\n");
  drawLine(30, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(12);
  printf("MENU");
  addBlank(12);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(28);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(7);
  printf("1. 책 추가하기");
  addBlank(7);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(7);
  printf("2. 검색하기");
  addBlank(10);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(7);
  printf("3. 대출하기/반납하기");
  addBlank(1);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(7);
  printf("4. 종료");
  addBlank(14);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(28);
  drawLine(1, '*');
  printf("\n");
  drawLine(30, '*');
  printf("\n");
  addBlank(2);
  printf("무엇을 도와드릴까요? : ");
  addBlank(1);
  scanf("%d", &behave_choice);
  if(behave_choice<1 || behave_choice>4) {
    addBlank(2);
    printf("1~4번중에서 입력해주세요.\n");
    show_MainMenu();
    return;
  }
  switch(behave_choice) {
    case 1:
      addBook();
      current_book_number++;
    break;
    case 2:
      search_books();
    break;
    case 3:
      manage_books();
    break;
    case 4:
      return;
    break;
  }
  return;
}
void addBook() {
  system("cls");
  int exit_choice;
  printf("나가기를 원하시면 1번을 입력해주세요\n");
  printf("계속 진행을 원하시면 2번을 입력해주세요\n");
  printf(": ");
  scanf("%d", &exit_choice);
  if(exit_choice==1) {
    show_MainMenu();
    return;
  }
  printf("책의 정보를 입력해주세요.\n");
  printf("\n");
  printf("책의 제목: ");
  scanf("%s", book_title[current_book_number]);
  printf("\n");
  printf("책의 저자: ");
  scanf("%s", book_author[current_book_number]);
  printf("\n");
  printf("책의 출판사: ");
  scanf("%s", book_publisher[current_book_number]);
  printf("\n");
  printf("책이 정상적으로 추가되었습니다.\n");
  system("cls");
  show_MainMenu();
  return;
}
void search_books() {
  system("cls");
  int search_method_choice;
  int book_number=0;
  int i=0;
  int find_number=101; // default value for distinguish;
  printf("책 검색 시스템\n");
  printf("하나의 정보를 입력해주세요.\n");
  printf("제목_1번, 작가_2번, 출판사_3번\n");
  printf("나가기는 4번입니다.\n");
  printf("번호를 눌러 선택해주세요. :");
  scanf("%d", &search_method_choice);
  switch(search_method_choice) {
    case 1:
      char received_title[30];
      system("cls");
      printf("< 제목 검색 >\n");
      printf("제목을 입력해주세요.\n");
      printf(" : ");
      scanf("%s", received_title);
      while(!(find_number!=101 || book_number==current_book_number)) {
        if(received_title[0]==book_title[book_number][0]) {
          if(compare_str(received_title, book_title[book_number]))
            break;
        }
        ++book_number;
      }
      find_number=book_number;
      break;
    case 2:
      char received_author[30];
      system("cls");
      printf("< 작가 검색 >\n");
      printf("작가 이름을 입력해주세요.\n");
      printf(" : ");
      scanf("%s", received_author);
      while(!(find_number!=101 || book_number==current_book_number)) {
        if(received_author[0]==book_author[book_number][0]) {
          if(compare_str(received_author, book_author[book_number]))
            break;
        }
        ++book_number;
      }
      find_number=book_number;
      break;
    case 3:
      char received_publisher[30];
      system("cls");
      printf("< 출판사 검색 >\n");
      printf("출판사 이름을 입력해주세요.\n");
      printf(" : ");
      scanf("%s", received_publisher);
      while(!(find_number!=101 || book_number==current_book_number)) {
        if(received_publisher[0]==book_publisher[book_number][0]) {
          if(compare_str(received_publisher, book_publisher[book_number]))
            break;
        }
        ++book_number;
      }
      find_number=book_number;
      break;
    case 4:
      show_MainMenu();
      return;
      break;
    default:
      printf("1, 2, 3, 4번중 하나만 선택해주세요.\n");
      search_books();
      return;
      break;
  }
  printf("< 찾으시는 책의 정보 >\n");
  printf("제목 : %s\n", book_title[find_number]);
  printf("작가 : %s\n", book_author[find_number]);
  printf("출판사 : %s\n", book_publisher[find_number]);
  printf("\n");
  printf("메인메뉴로 나가실려면 Enter키를 눌러주세요.");
  system("pause > nul");
  show_MainMenu();
  return;
}
void manage_books() {
  system("cls");
  int manage_choice;
  int received_number;
  printf("< 책 대출 및 반납 >\n");
  addBlank(2);
  printf("대출은 1번, 반납은 2번, 나가기는 3번 :");
  scanf("%d", &manage_choice);
  if(manage_choice<1 || manage_choice>3) {
    addBlank(2);
    printf("1~2번중 한 번호로 입력해주세요.\n");
    manage_books();
    return;
  }
  switch(manage_choice) {
    case 1:
      addBlank(2);
      printf("대출하실 책의 번호 : ");
      scanf("%d", &received_number);
      state[received_number]=1;
      if(state[received_number]!=1) {
        addBlank(2);
        printf("에러가 발생하였습니다. #01\n");
      }
      break;
    case 2:
      addBlank(2);
      printf("반납하실 책의 번호 : ");
      scanf("%d", &received_number);
      state[received_number]=0;
      if(state[received_number]!=0) {
        addBlank(2);
        printf("에러가 발생하였습니다. #02\n");
      }
      break;
    case 3:
      show_MainMenu();
      return;
      break;
  }
  show_MainMenu();
}
int compare_str(char *str1, char *str2) {
  while(*str1) {
    if(*str1!=*str2) {
      return 0;
    }
    str1++;
    str2++;
  }
  if(*str2=='\0')
    return 1;
  return 0;
}
void copy_str(char *src, char *dest) {
  while(*src) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
  return;
}
