#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // Windows specific

// NOTES:
// getch() (for closing the window without the need to press Enter) works only on Windows.


// --MACROS--
// Error codes
#define ERRCODE_NULL -1 // Now value found, got NULL
                      
// Errors
#define ERROR_NULL(x)                               \
  if ((*x) == NULL || (*x)->next == NULL) {         \
    printf("\nError code: %d"                       \
           "\nPress any key to end the program...", \
           ERRCODE_NULL);                           \
    getch();                                        \
    return ERRCODE_NULL;                            \
  }                                              

// --CUSTOMS--
typedef struct node {
	int age;
	struct node* next;
} staff;

// --PROTORYPES--
void append(staff* head, int age);
void push(staff** node, int age);
void print_linklist(staff* list);
int pop(staff** node);

// --LOGIC--
int main() {
  staff* person_head = malloc(sizeof(staff));
  person_head->next = NULL;

  person_head->age = 0;

  for (int i = 1; i <= 10; i++) {
    append(person_head, i);
    push(&person_head, -i);
  }

  if (pop(&person_head) == ERRCODE_NULL) {
    return 1;
  };

  print_linklist(person_head);
	
  // To prevent terminal window closing
  printf("= PROGRAM IS FINISHED =");
	getch();
}

// Append a new node at the end, duh...
void append(staff* head, int age) {
  staff* currient = head;
  while (currient->next != NULL) {
    currient = currient->next;
  }

  currient->next = malloc(sizeof(staff));
  currient->next->age = age;
  currient->next->next = NULL;
}

// Push a new node at the beginning
void push(staff** node, int age) {
  staff* new_head = malloc(sizeof(staff));
  new_head->age = age;
  new_head->next = *node;
  *node = new_head;
}

// Remove the first node of a list
int pop(staff** node) {
  // error check
  ERROR_NULL(node);

  staff* new_head = (*node)->next;
  free(*node);
  *node = new_head;

  return 0;
}

void pop_end() {
  //
}

// Print the value of every node of a linked list
void print_linklist(staff* list) {
  staff* buff = list;
  
  while (1) {
    printf("%d\n", buff->age);

    if (buff->next == NULL) break;
    else buff = buff->next;
  }
}
