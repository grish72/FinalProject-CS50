#include<stddef.h>
#include <stdio.h>
#include<math.h>
float calc_add(float a, float b);
float subtract(float a, float b);
float multiply(float a , float b);
float divide(float a, float b);
float square_root(float num);
float exponent(float base, float exp);
void linear_equation();
void quadratic_equation();

void linear_equation()
{
float a, b;
printf("Enter two numbers a and b for equation(ax + b =0)\n");
scanf("%f %f",&a, &b);

if (a!=0)
{
    float x = - b / a;
    printf("solution: x= %.2f\n", x);
}
else if(b == 0)
    {
        printf("Infinitely many solutions.\n");
    }
else
    {
        printf("No solution.\n");
    }
}

void quadratic_equation()
{
    float a, b, c;
    printf("Enter three numbers a, b, c for quadratic equations\n.");
    scanf ("%f %f %f", &a, &b, &c);
    if(a == 0)
    {
        printf("This is a linear equation\n.");
        linear_equation();
        return;
    }
        float discriminant = b * b - 4 * a * c;
        if(discriminant > 0)
        {
        float x1 = (-b + sqrt(discriminant)) / (2 *a);
        float x2 = (-b - sqrt(discriminant)) / (2* a);
        printf("Two real solutions: x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
        else if ( discriminant == 0)
        {
            float x = -b / ( 2 * a);
            printf( "One real solution.\n");
        }
        else
        {
            printf("No any solution(Complex roots).\n");
        }
    }
int main()
{
    char operator;
    float num1, num2, result;
    float memory = 0;

    printf("Welcome to my advanced calculator:\n");
    printf("These are the operators for you:\n");
    printf("+ : Addition \n");
    printf("- : Subtraction\n");
    printf("/ : Division\n");
    printf("* : Multiplication\n");
    printf("r : Square root\n");
    printf("^ : Power/ Exponentiation\n");
    printf("m : Save result to memory\n");
    printf("R : Recall memory\n");
    printf("H : Help \n");
    printf("q : Quit\n");
    printf("E : Linear equation(ax+b=0)\n");
    printf("e : Quadratic equation(ax^2+bx+c=0)\n");
    fflush(stdout);
    //simple calculator on basis of operation
    while (1)
    {
        printf("\nEnter an operation (+, -, *, /, r, ^, m, R, H, E, e) or q to quit: ");
        scanf(" %c", &operator);

        if (operator != '+' && operator != '-' && operator !='*' && operator !='/' && operator !='^'&&operator != 'r' && operator != 'q' && operator != 'R' && operator !='m' &&operator != 'E' && operator !='e' && operator != 'H')
        {
            printf("Invalid operator: Please use a valid one.");
            continue;
        }
        if (operator == '/' && num2 == 0)
        {
            printf("Syntax Error.\n");
            continue;
        }
        //if the user wants to quit.
        if (operator == 'q')
        {
            printf("Exiting calculator, Byee!\n");
            break;
        }
        if(operator == 'r')
        {
            printf(" Enter a number for square root:\n");
            scanf("%f", &num1);
            if(num1 < 0)
            {
                printf("Enter a positive number.\n");
            }
        }
     if (operator == 'H')
     {
        printf("Instructions to use this calculator:\n");
        printf("Enter a valid operator(+, -, *, /, r, ^).\n");
        printf("2. Provide two numbers if required.\n");
        printf("3. Use 'q' to quit.\n");
        continue;
     }
    //ask user to give two numbers to perform the calculations.
    printf("Enter two numbers :");
    scanf( "%f %f", &num1, &num2);

    //perform calculations
    switch (operator)
    {
        case '-':
            result = subtract(num1, num2);
            printf("Result: %.2f\n", result);
            break;

        case '+':
            result = calc_add(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result :%.2f\n", result);
            break;
        case '/':
            if (num2 != 0)
            {
            result = divide(num1, num2);
            printf("Result: %.2f\n",result);
            }
            else
            {
                printf("Error performing operation: Undefined");
            }
            break;
        case 'r':
            result = square_root(num1);
            printf("Square Root: %.2f\n", result);
            break;
        case '^':
        result = exponent (num1, num2);
        printf("Result: %.2f\n",result);
            break;
            case 'm':
            memory = result;
            printf("Result saved to memory: %.2f\n", memory);
            break;
            case 'R':
            printf("Recalled memory: %.2f\n", memory);
            break;
            case 'E':
            linear_equation();
            break;

            case 'e':
            quadratic_equation();
            break;
        default:
        printf("Invalid operator. please try again later\n");
    }
    }
    return 0;
}
//lets show how the operators work

float subtract(float a, float b)
{
    return a - b;
}
float calc_add(float a, float b)
{
    return a + b;
    }
float multiply(float a , float b)
{
    return a * b;
    }
float divide (float a , float b)
{
    return a / b;
    }
float square_root(float num)
{
    return sqrt(num);
}
float exponent( float base, float exp)
{
    return pow (base, exp);
 }

