#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int *collection;
    int capacity;
    int size;
}   Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

void Interface()
{
    printf("===== Main Menu =====\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. IsEmpty\n");
    printf("5. IsFull\n");
    printf("6. Exit(press ESC)\n");
    printf("=====================\n");
    printf("\nEnter your choice: ");
}

int main(){
    int MAXSIZE;
    printf("Input the maximum size of the stack:");
    scanf("%d", &MAXSIZE);
    Stack *stack = create_stack(MAXSIZE);
    if (stack == NULL)
    {
        printf("Stack creation failed. Exiting...\n");
        return 1;
    }
    while(1){
        int choice;
        Interface();
        choice = getch();
        switch(choice){
            case 49:{
                system("cls");
                char value[100];
                printf("Enter a value to push: ");
                scanf("%s", value);
                if (push(stack, value))
                {
                    printf("Pushed %s onto the stack.\n", value);
                }
                else
                {
                    printf("Stack is full. Cannot push.\n");
                }
                getch();
                system("cls");
                break;}
            case 50:{
                system("cls");
                char *item;
                if (pop(stack, &item))
                {
                    printf("Popped %s from the stack.\n", item);
                    free(item);
                }
                else
                {
                    printf("Stack is empty. Cannot pop.\n");
                }
                getch();
                system("cls");
                break;}
            case 51:{
                system("cls");
                char *item;
                if (peek(stack, &item))
                {
                    printf("Element at the top of the stack: %s\n", item);
                }
                else
                {
                    printf("Stack is empty. Cannot peek.\n");
                }
                getch();
                system("cls");
                break;}
            case 52:{
                system("cls");
                printf("Stack empty: %s\n" , is_empty(stack)?"true":"false");
                getch();
                system("cls");
                break;
                }
            case 53:{
                system("cls");
                printf("Stack full: %s\n" , is_full(stack)?"true":"false");
                getch();
                system("cls");
                break;}
            case 54:{
                destroy_stack(stack);
                system("cls");
                printf("\033[0;32m");
                printf("Exiting... Goodbye!\n");
                printf("\033[0m");
                return 0;
                break;}
            case 27:{
                destroy_stack(stack);
                system("cls");
                printf("\033[0;32m");
                printf("Exiting... Goodbye!\n");
                printf("\033[0m");
                return 0;}
            default:{
                system("cls");
                printf("\033[0;31m");
                printf("Invalid choice. Please try again.\n");
                printf("\033[0m");
                system("pause");
                system("cls");
                break;}
        }
    }

    return 0;
}

Stack *create_stack(int capacity)
{
    if (capacity <= 0)
        return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    stack->collection = malloc(sizeof(int)*capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

void destroy_stack(Stack *stack)
{
  for (int i = 0; i < stack->size; i++)
    {
        free(stack->collection[i]); // Free the memory allocated for strings
    }
  free(stack->collection);
  free(stack);
}

bool is_full(Stack *stack)
{
  return stack->capacity == stack->size;
}

bool is_empty(Stack *stack)
{
  return stack->size == 0;
}

bool push(Stack *stack, int item)
{
  if (is_full(stack))
    return false;
  stack->collection[stack->size] = strdup(item); // Duplicate the string and store the pointer
  stack->size++;
  return true;
}

bool peek(Stack *stack, int *item)
{
  if (is_empty(stack))
    return false;
  *item = stack->collection[stack->size - 1];
  return true;
}

bool pop(Stack *stack, int *item)
{
  if (is_empty(stack))
    return false;
  stack->size--;
  *item = stack->collection[stack->size];
  return true;
}

