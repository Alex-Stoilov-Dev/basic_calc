#include <ctype.h>
#include <stdio.h>

#define EXPRESSION_LENGTH 10
#define MAX_NUM_SIZE 128

void sanitize_arr(char *arr[]){
    
    size_t count = sizeof(&arr) / sizeof(char); 

    char num_op;

    for (size_t i = 0; i < count; i++){
        if ((int)num_op == ' ' && i != count - 1){
            arr[i] = arr[i + 1];
        }
    }
}

int main(int argc, char *argv[])
{
    char expression[EXPRESSION_LENGTH];
    char operator_buffer[EXPRESSION_LENGTH - 1];
    int num_buffer[EXPRESSION_LENGTH];
    int result_buffer[1];
    int count = sizeof(expression) / sizeof(char);

    char num_or_operator;
    fgets(expression, count, stdin);

    int op_count = 0;
    int num_count = 0;


    for (size_t i = 0; i < count; i++)
    {
        num_or_operator = expression[i];
        if (num_or_operator == '+' || num_or_operator == '-')
        {
            operator_buffer[op_count++] = num_or_operator;
        }
        else if (isdigit(num_or_operator) >= 0)
        {
            num_buffer[num_count++] = num_or_operator - '0';
        }
        else
        {
            printf("Hey that's an invalid expression");
            break;
        }        
    }

    int nums_size = sizeof(num_buffer) / sizeof(int);

    for (size_t i = 0; i < nums_size - 1; i++)
    {
        int current_val = num_buffer[i];
        int next_val = num_buffer[i + 1];

        char next_operator = operator_buffer[i];

       if(next_operator == operator_buffer[i+1] && next_operator == '-'){
            operator_buffer[i] = '+';
            next_operator = operator_buffer[i];
            operator_buffer[i + 1] = 0;
       }

        switch (next_operator)
        {
        case '+':
            result_buffer[0] = current_val + next_val;
            break;
        case '-':
            result_buffer[0] = current_val - next_val;
            break;
        }
    }

    printf("Our result is: %d", result_buffer[0]);
}
