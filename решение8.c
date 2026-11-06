#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void print_chars(int count, char sym1, char sym2, int mode);
int sum_range(int m, int n);
double power_of_two(int i);
double calculate_function(double x);
void print_tabulation(double a, double b, double h);
double calculate_homework(int N);

int main()

{
	setlocale(LC_CTYPE, "RUS");

    printf("=== Задание 0 ===\n");
    int n0;
    char sym1, sym2;
    printf("Введите количество символов: ");
    scanf("%d", &n0);
    printf("Введите первый и второй символ для замены: ");
    scanf(" %c %c", &sym1, &sym2);

    printf("\nНачальный вывод:\n");
    print_chars(n0, '*', '*', 0);

    printf("\n*) В начале и в конце '+':\n");
    print_chars(n0, '*', '*', 1);

    printf("\n**) Половина строки первым символом (%c), половина вторым (%c):\n", sym1, sym2);
    print_chars(n0, sym1, sym2, 2);

    printf("\n***) После каждого символа '!':\n");
    print_chars(n0, '*', '*', 3);

    printf("\n=== Задание 1 ===\n");
    int m, n;
    printf("Введите m и n (m >= n): ");
    scanf("%d %d", &m, &n);
    int s = sum_range(m, n);
    printf("Сумма чисел от %d до %d = %d\n", m, n, s);

    printf("\n=== Задание 1А ===\n");
    int degn;
    printf("Введите степень n: ");
    scanf("%d", &degn);
    for (int i = 0; i <= degn; i++)

    {
		double res = power_of_two(i);
		printf("2^%d = %10.0lf\n", i, res);
    }
    
        double last_res = power_of_two(degn);
		printf("Результат: %.1lf K\n", last_res / 1024.0);

        double limit_m;
		printf("Введите предел m (m > 0): ");
		scanf("%lf", &limit_m);
		
		printf("Значения в K (до %.1lf) K\n", limit_m / 1024.0);
		for (int i = 0; power_of_two(i) <= limit_m; i++)

		{
			double current_val = power_of_two(i);
			printf("2^%d = %1.0lf\n", i, current_val / 1024.0);
			}

    printf("\n=== Задание 2 ===\n");
    double a2 = 2.0, b2 = 4.0;
    printf("Функция: y = x^3 + 3x^2 - 3 на интервале [%.1lf; %.1lf]\n", a2, b2);
    double h;
    printf("Введите шаг табуляции (h > 0): ");
    scanf("%lf", &h);
    if (h <= 0.0)
    
    {
        printf("Ошибка: шаг табуляции должен быть больше 0\n");
    }

    else

    {
        print_tabulation(a2, b2, h);
    }

    printf("\n=== Домашнее задание ===\n");
    int N;
    printf("Введите целое N (N > 0): ");
    scanf("%d", &N);

    if (N <= 0)
    
    {
        printf("Ошибка: N должно быть больше 0\n");
    }

    else 
    
    {
        double sum_dz = calculate_homework(N);
        printf("Сумма ряда: %.0lf\n", sum_dz);
    }

    return 0;

}

void print_chars(int count, char sym1, char sym2, int mode)
{
    if (mode == 0)

    {
        for (int i = 1; i <= count; i++) putchar(sym1);
        printf("\n");
    }

    else if (mode == 1)

    {
        putchar('+');
        for (int i = 1; i <= count; i++) putchar(sym1);
        putchar('+');
        printf("\n");
    }

    else if (mode == 2)

    {
        for (int i = 1; i <= count; i++)

        {
            if (i <= count / 2) putchar(sym1);
            else putchar(sym2);
        }

        printf("\n");

    }

    else if (mode == 3)

    {
        for (int i = 1; i <= count; i++)

        {
            putchar(sym1);
            putchar('!');
        }

        printf("\n");
    }

}

int sum_range(int m, int n)

{
	int s = 0;
    for (int i = m; i >= n; i--)

    {
		s += i;
    }
    return s;
}

double power_of_two(int i)

{
	return pow(2.0, i);
}

double calculate_function(double x)

{
	return pow(x, 3) + 3.0 * pow(x, 2) - 3.0;
}

void print_tabulation(double a, double b, double h)

{
	printf("---------------------\n");
	printf("|   x   |    y       |\n");
	printf("---------------------\n");

	for (double x = a; x <= b + 0.0001; x += h)

	{
		double y = calculate_function(x);
		printf("| %7.2lf | %8.4lf |\n", x, y);
	}

	printf("---------------------\n");
}

double calculate_homework(int N)

{
	double sum = 0.0;
	for (int i = N; i <= 2 * N; i++)

	{
        sum += pow(i, 2);
	}

	return sum;
}
