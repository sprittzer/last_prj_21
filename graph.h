/*
 * graph.h - Заголовочный файл для основных функций программы P03D20
 * 
 * Автор: marianbe
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "structures.h"

// Основные функции программы
int main(int argc, char* argv[]);
void draw_graph(const char* expression);

// Парсинг и валидация
int parse_expression(const char* expr, Token* tokens, int* token_count);
int validate_expression(const char* expr);
int check_brackets(const char* expr);
int check_invalid_chars(const char* expr);

// Алгоритм Дейкстры (shunting-yard)
int shunting_yard(Token* tokens, int token_count, Token* output, int* output_count);
double evaluate_rpn(Token* rpn, int rpn_count, double x);

// Отрисовка графика
void init_graph_field(GraphField* field);
void plot_point(GraphField* field, double x, double y);
void render_graph(GraphField* field);
void clear_graph_field(GraphField* field);
void free_graph_field(GraphField* field);

// Координатные преобразования
int x_to_screen(double x, GraphField* field);
int y_to_screen(double y, GraphField* field);
double screen_to_x(int screen_x, GraphField* field);
double screen_to_y(int screen_y, GraphField* field);

#endif // GRAPH_H 