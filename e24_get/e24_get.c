/* Задача 5. Промышленность не выпускает резисторы и конденсаторы произвольных номиналов,
а используют так называемый E-ряд. Наиболее распространенный ряд — E24. Напишите функцию,
которая принимает значение от 1,0 до 9,9 и в ответ выдает наиболее близкое значение
из этого ряда.*/

#include <stdio.h>
#include <stdlib.h>
float e24_get(float value);
int main()
{
    float num, ans;
    printf("Enter the float value from 1.0 to 9.9 (enter wrong number or q will closing the program)\n");
    while(scanf("%f", &num) == 1 && (num >= 1.0 && num <= 9.9))
    {
        ans = e24_get(num);
        printf("The next number of %.3f is %.1ff\n", num, ans);
        printf("Enter the new float value from 1.0 to 9.9\n");
    }
    printf("Program closed\n");
    return 0;
}

float e24_get(float value)
{
    int count;
    float diff, min = 10, ans;
    static const float e24[] = {1.0f, 1.1f, 1.2f, 1.3f, 1.5f,
    1.6f, 1.8f, 2.0f, 2.2f, 2.4f, 2.7f, 3.0f, 3.3f, 3.6f, 3.9f,
    4.3f, 4.7f, 5.1f, 5.6f, 6.2f, 6.8f, 7.5f, 8.2f, 9.1f};
    for(count = 0; count <= 23; count++)
    {
        diff = fabs(value - e24[count]); // Чем меньше разность чисел по модулю, тем ближе число к значению в ряду
        if(min > diff) // проверка значений минимальной разности
        {
            min = diff; // уменьшение минимальной разности
            ans = e24[count]; // элемент массива при котором произошла минимальная разность
        }
    }
    return ans;
}
