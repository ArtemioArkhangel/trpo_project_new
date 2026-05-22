#define _GNU_SOURCE
#include "../src/pwgenfunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_custom_password_all_groups(void)
{
    char char_kit[200] = {0};
    custom_password(char_kit, 1, 1, 1, 1, 1);

    if (strlen(char_kit) == 0)
    {
        fprintf(stderr, "\n    ОШИБКА: пул пуст при всех группах\n");
        exit(1);
    }
    if (!strpbrk(char_kit, "abcdefghijklmnopqrstwxyz"))
    {
        fprintf(stderr, "\n    ОШИБКА: нет строчных\n");
        exit(1);
    }
    if (!strpbrk(char_kit, "ABCDEFGHIJKLMNOPQRSTWXYZ"))
    {
        fprintf(stderr, "\n    ОШИБКА: нет прописных\n");
        exit(1);
    }
    if (!strpbrk(char_kit, "0123456789"))
    {
        fprintf(stderr, "\n    ОШИБКА: нет цифр\n");
        exit(1);
    }
    if (!strpbrk(char_kit, "!@#$%&*()-_=+.,;:/?'<=>[]^|{}`~"))
    {
        fprintf(stderr, "\n    ОШИБКА: нет спецсимволов\n");
        exit(1);
    }
}
void test_custom_password_no_groups(void)
{
    char char_kit[200] = {0};
    custom_password(char_kit, 2, 2, 2, 2, 0);

    if (strlen(char_kit) != 0)
    {
        fprintf(stderr, "\n    ОШИБКА: пул не пуст\n");
        exit(1);
    }
}
void test_custom_password_easy_signs_only(void)
{
    char char_kit[200] = {0};
    custom_password(char_kit, 2, 2, 2, 1, 2);

    if (strlen(char_kit) == 0)
    {
        fprintf(stderr, "\n    ОШИБКА: пул пуст\n");
        exit(1);
    }
}
void test_generate_password_length(void)
{
    char buffer[] = "ABC123";
    char str[9];
    FILE *old = stdout;
    stdout = fopen("/dev/null", "w");
    GeneratePassword(str, 8, buffer, 1);
    fclose(stdout);
    stdout = old;

    if (strlen(str) != 8)
    {
        fprintf(stderr, "\n    ОШИБКА: длина %zu, ожидалась 8\n", strlen(str));
        exit(1);
    }
}
void test_generate_password_multiple(void)
{
    char buffer[] = "ABC";
    char str[5];
    FILE *old = stdout;
    stdout = fopen("/dev/null", "w");
    GeneratePassword(str, 4, buffer, 3);
    fclose(stdout);
    stdout = old;
}
void test_check_char_num_boundaries(void)
{
    int char_num;
    int res = 0, ch = 0;
    FILE *old_out = stdout;
    stdout = fopen("/dev/null", "w");
    FILE *fake_in = fmemopen("4\n", 2, "r");
    FILE *old_in = stdin;
    stdin = fake_in;
    check_char_num(res, ch, &char_num);
    fclose(fake_in);

    if (char_num != 4)
    {
        stdout = old_out;
        fprintf(stderr, "\n    ОШИБКА: не принято 4\n");
        exit(1);
    }
    fake_in = fmemopen("61\n4\n", 6, "r");
    stdin = fake_in;
    check_char_num(res, ch, &char_num);
    fclose(fake_in);
    stdin = old_in;
    if (char_num != 4)
    {
        stdout = old_out;
        fprintf(stderr, "\n    ОШИБКА: не обработано 61\n");
        exit(1);
    }
    fclose(stdout);
    stdout = old_out;
}
void test_check_pw_num_boundaries(void)
{
    int pw_num;
    int res = 0, ch = 0;
    FILE *old_out = stdout;
    stdout = fopen("/dev/null", "w");
    FILE *fake_in = fmemopen("500\n", 4, "r");
    FILE *old_in = stdin;
    stdin = fake_in;
    check_pw_num(res, ch, &pw_num);
    fclose(fake_in);
    if (pw_num != 500)
    {
        stdout = old_out;
        fprintf(stderr, "\n    ОШИБКА: не принято 500\n");
        exit(1);
    }
    fake_in = fmemopen("501\n1\n", 7, "r");
    stdin = fake_in;
    check_pw_num(res, ch, &pw_num);
    fclose(fake_in);
    stdin = old_in;
    if (pw_num != 1)
    {
        stdout = old_out;
        fprintf(stderr, "\n    ОШИБКА: не обработано 501\n");
        exit(1);
    }
    fclose(stdout);
    stdout = old_out;
}
void test_check_use_signs_invalid(void)
{
    int useSigns, useSpecialSigns;
    int res = 0, ch = 0;
    FILE *old_out = stdout;
    stdout = fopen("/dev/null", "w");
    FILE *fake_in = fmemopen("3\n1\n2\n", 7, "r");
    FILE *old_in = stdin;
    stdin = fake_in;
    check_useSigns(res, ch, &useSigns, &useSpecialSigns);
    fclose(fake_in);
    stdin = old_in;
    if (useSigns != 1)
    {
        stdout = old_out;
        fprintf(stderr, "\n    ОШИБКА: не обработан неверный ввод (3)\n");
        exit(1);
    }
    fclose(stdout);
    stdout = old_out;
}