#include "pwgenfunc.h"
void check_char_num(int res, int ch, int *char_num)
{
    printf("Сколько символов должен иметь пароль?(от 4 до 60)\n");
    while ((res = scanf("%d", char_num)) != EOF && (res != 1 || *char_num < 4 || *char_num > 60))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
}
void check_pw_num(int res, int ch, int *pw_num)
{
    printf("Сколько паролей вы хотите сгенерировать?(от 1 до 500)\n");
    while ((res = scanf("%d", pw_num)) != EOF && (res != 1 || *pw_num < 1 || *pw_num > 500))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar() != '\n') && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
}
void check_useLowers(int res, int ch, int *useLowers)
{
    printf("Использовать латиницу в нижнем регистре?\n");
    printf("1 - да\n");
    printf("2 - нет\n");
    while ((res = scanf("%d", useLowers)) != EOF && (res != 1 || (*useLowers != 1 && *useLowers != 2)))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar() != '\n') && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
}
void check_useUppers(int res, int ch, int *useUppers)
{
    printf("Использовать латиницу в верхнем регистре?\n");
    printf("1 - да\n");
    printf("2 - нет\n");
    while ((res = scanf("%d", useUppers)) != EOF && (res != 1 || (*useUppers != 1 && *useUppers != 2)))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar() != '\n') && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
}
void check_useDigits(int res, int ch, int *useDigits)
{
    printf("Использовать цифры от 0 до 9?\n");
    printf("1 - да\n");
    printf("2 - нет\n");
    while ((res = scanf("%d", useDigits)) != EOF && (res != 1 || (*useDigits != 1 && *useDigits != 2)))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar() != '\n') && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
}
void check_useSigns(int res, int ch, int *useSigns, int *useSpecialSigns)
{
    printf("Использовать специальные символы?\n");
    printf("1 - да\n");
    printf("2 - нет\n");
    while ((res = scanf("%d", useSigns)) != EOF && (res != 1 || (*useSigns != 1 && *useSigns != 2)))
    {
        printf("Некорректный ввод! Попробуйте ещё раз.\n");
        while ((ch = getchar() != '\n') && ch != EOF)
            ;
    }
    if (res == EOF)
        exit(0);
    switch (*useSigns)
    {
    case 1:
        printf("Определите набор символов\n");
        printf("1 - лёгкий вход на смартфон\n");
        printf("2 - все специальные симолы\n");
        while ((res = scanf("%d", useSpecialSigns)) != EOF &&
               (res != 1 || (*useSpecialSigns != 1 && *useSpecialSigns != 2)))
        {
            printf("Некорректный ввод! Попробуйте ещё раз.\n");
            while ((ch = getchar() != '\n') && ch != EOF)
                ;
        }
        if (res == EOF)
            return;
        break;
    case 2:
        break;
    }
}