/*
 * validation.h - Заголовочный файл для валидации и базовых операций
 * 
 * Автор: silvagal
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include "structures.h"

// Базовые математические операции
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);

// Обработка скобок
int count_brackets(const char* expr);
Bracket* find_brackets(const char* expr, int* count);
int validate_brackets(const char* expr);
int find_matching_bracket(const char* expr, int open_pos);

// Простая валидация
ValidationResult validate_simple_expression(const char* expr);
int is_valid_character(char c);
int is_digit(char c);
int is_letter(char c);
int is_whitespace(char c);

// Вспомогательные функции
void skip_whitespace(const char* expr, int* pos);
int read_number(const char* expr, int* pos, double* value);
int read_identifier(const char* expr, int* pos, char* buffer, int max_len);
void print_validation_error(ValidationResult result);

#endif // VALIDATION_H 