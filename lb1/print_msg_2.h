#include "print_msg_1.h"// Не забудьте включить заголовочный файл этого файла
#include <stdio.h>

void My_print(char *msg)// Объявлять не нужно, объявление объявляется в заголовочном файле
{
    printf("Входящий параметр: %s",  msg);
}
