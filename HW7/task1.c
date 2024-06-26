/*D3 Практик 1
В обратном порядке
Дано целое неотрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.
Данные на входе: 	Одно неотрицательное целое число
Данные на выходе: 	Последовательность цифр введенного числа в обратном порядке через пробел

Пример №1
Данные на входе: 	15
Данные на выходе: 	5 1

Пример №2
Данные на входе: 	54321
Данные на выходе: 	1 2 3 4 5 */

#include <stdio.h>
#include <locale.h>

void swap(int n)
{
    if (n > 0)
    {
        printf("%d ", n % 10);
        swap(n / 10);
    }
}

int main()
{
    int n;
    setlocale(LC_ALL, ".UTF-8");
    printf("Введите одно неотрицательное целое число: ");
    scanf("%d", &n);
    swap(n);
    return 0;
}