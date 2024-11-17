#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack
{
    char arr[MAX];
    int top;
};

// Function to initialize stack
void initStack(struct Stack *stack)
{
    stack->top = -1;
}

// Function to push element to stack
void push(struct Stack *stack, char c)
{
    if (stack->top < MAX - 1)
    {
        stack->arr[++stack->top] = c;
    }
}

// Function to pop element from stack
char pop(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->arr[stack->top--];
    }
    return '\0'; // Return null character if stack is empty
}

int main()
{
    char str[MAX];
    struct Stack stack;

    // Initialize stack
    initStack(&stack);

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Push all characters of the string to stack
    for (int i = 0; i < strlen(str); i++)
    {
        push(&stack, str[i]);
    }

    // Pop characters from stack to reverse the string
    printf("Reversed string: ");
    while (stack.top != -1)
    {
        printf("%c", pop(&stack));
    }
    printf("\n");
    return 0;
};