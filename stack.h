/*
 * stack.h - Заголовочный файл для работы со стеком и математических функций
 * 
 * Автор: jerrycar
 */

#ifndef STACK_H
#define STACK_H

#include "structures.h"

// Работа со стеком
Stack* create_stack(int capacity);
void push(Stack* stack, Token token);
Token pop(Stack* stack);
Token peek(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);

// Работа со списком лексем
TokenList* create_token_list(int capacity);
void add_token(TokenList* list, Token token);
void free_token_list(TokenList* list);

// Математические функции
double apply_function(const char* func_name, double x);
double my_sin(double x);
double my_cos(double x);
double my_tan(double x);
double my_ctg(double x);
double my_sqrt(double x);
double my_ln(double x);

// Обработка операторов
int is_operator(char c);
int get_precedence(char op);
int is_left_associative(char op);
double apply_operator(char op, double a, double b);

#endif // STACK_H 