#include "print_msg_1.h"// Заголовочный файл, содержащий функции-функции, указанные в этом файле
#include "print_msg_2.h"
#include <stdio.h>// Файлы библиотеки связанных функций

int main(int argc, char *argv[])
{
    My_log();
    My_print("hahahaha");// Вы можете напрямую вызвать функцию в файле функции, на которую указывает ссылка
    return 0;
}
