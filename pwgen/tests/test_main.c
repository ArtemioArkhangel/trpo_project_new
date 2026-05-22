#include <stdio.h>
extern void test_custom_password_all_groups(void);
extern void test_custom_password_no_groups(void);
extern void test_custom_password_easy_signs_only(void);
extern void test_generate_password_length(void);
extern void test_generate_password_multiple(void);
extern void test_check_char_num_boundaries(void);
extern void test_check_pw_num_boundaries(void);
extern void test_check_use_signs_invalid(void);
static int passed = 0;
void run_test(void (*func)(void), const char *name)
{
    printf("  %s ... ", name);
    fflush(stdout);
    func();
    printf("OK\n");
    passed++;
}
int main(void)
{
    printf("Unit-тесты\n");
    printf("custom_password (формирование алфавита):\n");
    run_test(test_custom_password_all_groups, "Все группы + полные спецсимволы");
    run_test(test_custom_password_no_groups, "Ни одной группы");
    run_test(test_custom_password_easy_signs_only, "Только лёгкий вход");
    printf("\nGeneratePassword (генерация):\n");
    run_test(test_generate_password_length, "Длина пароля 8 символов");
    run_test(test_generate_password_multiple, "Генерация 3 паролей");
    printf("\nВалидация ввода:\n");
    run_test(test_check_char_num_boundaries, "Границы длины (4 — ок, 61 — нет)");
    run_test(test_check_pw_num_boundaries, "Границы количества (500 — ок, 501 — нет)");
    run_test(test_check_use_signs_invalid, "Неверный ответ на да/нет");
    printf("Пройдено тестов: %d\n", passed);
    return 0;
}