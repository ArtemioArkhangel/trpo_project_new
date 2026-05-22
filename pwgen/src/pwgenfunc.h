#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void custom_password(char *char_kit, int useLowers, int useUppers, int useDigits, int useSigns, int useSpecialSigns);
void GeneratePassword(char *str, int char_num, char *buffer, int pw_num);
void check_char_num(int res, int ch, int *char_num);
void check_pw_num(int res, int ch, int *pw_num);
void check_useLowers(int res, int ch, int *useLowers);
void check_useUppers(int res, int ch, int *useUppers);
void check_useDigits(int res, int ch, int *useDigits);
void check_useSigns(int res, int ch, int *useSigns, int *useSpecialSigns);