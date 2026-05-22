#include "pwgenfunc.h"

int main(void)
{
    srand(time(NULL));
    int res = 0, ch = 0;
    int char_num, pw_num;
    int useLowers, useUppers, useDigits, useSigns, useSpecialSigns;
    check_char_num(res, ch, &char_num);
    check_pw_num(res, ch, &pw_num);
    printf("Введите параметры генерируемого(мых) пароля(лей)\n");
    check_useLowers(res, ch, &useLowers);
    check_useUppers(res, ch, &useUppers);
    check_useDigits(res, ch, &useDigits);
    check_useSigns(res, ch, &useSigns, &useSpecialSigns);
    char password[char_num + 1];
    char char_kit[200] = {0};
    custom_password(char_kit, useLowers, useUppers, useDigits, useSigns, useSpecialSigns);
    if (strlen(char_kit) == 0)
        return 0;
    printf("Ваш(и) пароль(ли)\n");
    GeneratePassword(password, char_num, char_kit, pw_num);
    return 0;
}