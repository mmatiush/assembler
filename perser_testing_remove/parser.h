#ifndef PARSER_H
#define PARSER_H

struct operation {
    char cond[32]; // Условие выполнения
    char cmd[32];  // Сама команда
    char arg0[32]; // Первый аргумент
    char arg1[32]; // Второй аргумент
    char arg2[32]; // Третий агрумент
};

void dump_operation(struct operation *op); // Вывод данных операции
struct operation *parse_code(const char *code); // Парсит строку в общее представление кода

#endif // PARSER_H
