#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "parser.h"

#define SON(x) (((x) && (*(x) != '\0'))?(x):"NONE") //Если строка пуста или указатель нулевой,  то выдаем NONE (для dump_operation)

void dump_operation(struct operation *op)
{
    if (!op) { // Если дан неверный указатель
        printf("OP: NULL\n");
        return;
    }

        // Если указатель в порядке
    printf("COND: \"%s\"\nOP: \"%s\"\nARGS: \"%s\", \"%s\", \"%s\"\n\n",
               SON(op->cond), SON(op->cmd), SON(op->arg0),
               SON(op->arg1), SON(op->arg2));
}

static inline const char *skip(const char *line, char *skips) // Пропуск строки в строке
{
    line += strlen(skips); // Увеличим указатель на пропарсиваемую строку на длину пропускаемой
    while ((*line == ' ') || (*line == ',')) // Пропустим ненужные символы
        line++;

    if ((*line == '\0') || (*line == '\n') || (*line == ';')) // Если конец строки 
        return 0; // Вернем нулевой указатель

    return line; // Иначе вернем полученный указатель
}

static inline void str_to_lower(char *str) // Переводит строку в нижний регистр
{
    unsigned int l = strlen(str);
    unsigned int i = 0;

    for (i = 0; i < l; i++)
        str[i] = (char)tolower(str[i]);
}

struct operation *parse_code(const char *code)
{
    struct operation *op = (struct operation*)calloc(1, sizeof(*op)); // Выделим память под результат
    char *tokens[5] = {op->cond, op->cmd, op->arg0, op->arg1, op->arg2};
    unsigned int i = 0;

    for (i = 0; i < 5; i++) {
            if (sscanf(code, "%[0-9a-zA-Z@#$]", tokens[i]) <= 0)/*Получаем строку в текущий токен*/
            { // Если встретили запрещенный символ
            fprintf(stderr, "Error!\nUnknown symbol!\n"); // Говорим об этом

            free((void *)op); // Освобождаем память
            return 0; // Возвращаем нулевой указатель
            }

        str_to_lower(tokens[i]); // Переводим строку в нижний регистр

        code = skip(code, tokens[i]); // Пропускаем полученный токен

        if (!code) // Если код закончился
                    break; // Завершаем цикл
    }

    return op; // Возвращаем объектное представление кода
}