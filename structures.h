/*
 * structures.h - Определения всех структур данных для проекта P03D20
 * 
 * Авторы: marianbe, jerrycar, silvagal
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

// marianbe: Основная структура лексемы
typedef struct {
    char type;        // 'n' - число, 'o' - оператор, 'f' - функция, 'v' - переменная
    double value;     // числовое значение
    char operator;    // символ оператора
    char function[10]; // название функции
    int precedence;   // приоритет оператора
} Token;

// marianbe: Структура для хранения графика
typedef struct {
    char** field;     // двумерный массив для отрисовки
    int width;        // ширина поля (80)
    int height;       // высота поля (25)
    double x_min;     // минимальное значение x
    double x_max;     // максимальное значение x
    double y_min;     // минимальное значение y
    double y_max;     // максимальное значение y
} GraphField;

// jerrycar: Стек для алгоритма Дейкстры
typedef struct {
    Token* data;
    int top;
    int capacity;
} Stack;

// jerrycar: Список лексем
typedef struct {
    Token* tokens;
    int count;
    int capacity;
} TokenList;

// jerrycar: Структура для функций
typedef struct {
    char name[10];
    double (*func)(double);
} MathFunction;

// silvagal: Структура для обработки скобок
typedef struct {
    char type;    // '(' или ')'
    int position; // позиция в строке
} Bracket;

// silvagal: Структура для валидации
typedef struct {
    int has_error;
    char error_message[100];
    int error_position;
} ValidationResult;

#endif // STRUCTURES_H 