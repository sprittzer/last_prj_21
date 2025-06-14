# План работы над проектом P03D20

## Общая информация о проекте

**Проект:** P03D20 - разработка программы на языке C для построения графиков математических функций в терминале.

**Задача:** Программа должна принимать математическое выражение в виде строки и выводить график функции в виде символов "*" на поле 25x80 точек.

**Команда:** marianbe, jerrycar, silvagal

---

## Распределение функций и структур данных по участникам

### marianbe

#### Структуры данных:
- **Token** - основная структура лексемы (тип, значение, оператор, функция, приоритет)
- **GraphField** - структура для хранения графика (поле, размеры, диапазоны координат)

#### Функции:
- **Основные функции программы:** main(), draw_graph()
- **Парсинг и валидация:** parse_expression(), validate_expression(), check_brackets(), check_invalid_chars()
- **Алгоритм Дейкстры:** shunting_yard(), evaluate_rpn()
- **Отрисовка графика:** init_graph_field(), plot_point(), render_graph(), clear_graph_field(), free_graph_field()
- **Координатные преобразования:** x_to_screen(), y_to_screen(), screen_to_x(), screen_to_y()

### jerrycar

#### Структуры данных:
- **Stack** - стек для алгоритма Дейкстры (данные, вершина, вместимость)
- **TokenList** - список лексем (токены, количество, вместимость)
- **MathFunction** - структура для функций (название, указатель на функцию)

#### Функции:
- **Работа со стеком:** create_stack(), push(), pop(), peek(), is_empty(), free_stack()
- **Работа со списком лексем:** create_token_list(), add_token(), free_token_list()
- **Математические функции:** apply_function(), my_sin(), my_cos(), my_tan(), my_ctg(), my_sqrt(), my_ln()
- **Обработка операторов:** is_operator(), get_precedence(), is_left_associative(), apply_operator()

### silvagal

#### Структуры данных:
- **Bracket** - структура для обработки скобок (тип, позиция)
- **ValidationResult** - структура для валидации (ошибка, сообщение, позиция)

#### Функции:
- **Базовые математические операции:** add(), subtract(), multiply(), divide(), power()
- **Обработка скобок:** count_brackets(), find_brackets(), validate_brackets(), find_matching_bracket()
- **Простая валидация:** validate_simple_expression(), is_valid_character(), is_digit(), is_letter(), is_whitespace()
- **Вспомогательные функции:** skip_whitespace(), read_number(), read_identifier(), print_validation_error()

---

## Распределение по файлам

### Основные файлы:

#### `src/graph.h` (marianbe)
```c
// Общие структуры данных
typedef struct Token Token;
typedef struct GraphField GraphField;
typedef struct Stack Stack;
typedef struct TokenList TokenList;
typedef struct MathFunction MathFunction;
typedef struct Bracket Bracket;
typedef struct ValidationResult ValidationResult;

// Основные функции программы
int main(int argc, char* argv[]);
void draw_graph(const char* expression);
```

#### `src/graph.c` (marianbe)
```c
// Основные функции программы
int main(int argc, char* argv[]);
void draw_graph(const char* expression);

// Парсинг и валидация
int parse_expression(const char* expr, Token* tokens, int* token_count);
int validate_expression(const char* expr);
int check_brackets(const char* expr);
int check_invalid_chars(const char* expr);

// Алгоритм Дейкстры
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
```

### Модули jerrycar:

#### `src/stack.h` (jerrycar)
```c
// Структуры данных
typedef struct Stack Stack;
typedef struct TokenList TokenList;
typedef struct MathFunction MathFunction;

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
```

#### `src/stack.c` (jerrycar)
```c
// Реализация всех функций из stack.h
```

### Модули silvagal:

#### `src/validation.h` (silvagal)
```c
// Структуры данных
typedef struct Bracket Bracket;
typedef struct ValidationResult ValidationResult;

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
```

#### `src/validation.c` (silvagal)
```c
// Реализация всех функций из validation.h
```

### Дополнительные файлы:

#### `src/structures.h` (общий)
```c
// Все структуры данных
typedef struct {
    char type;        // 'n' - число, 'o' - оператор, 'f' - функция, 'v' - переменная
    double value;     // числовое значение
    char operator;    // символ оператора
    char function[10]; // название функции
    int precedence;   // приоритет оператора
} Token;

typedef struct {
    char** field;     // двумерный массив для отрисовки
    int width;        // ширина поля (80)
    int height;       // высота поля (25)
    double x_min;     // минимальное значение x
    double x_max;     // максимальное значение x
    double y_min;     // минимальное значение y
    double y_max;     // максимальное значение y
} GraphField;

typedef struct {
    Token* data;
    int top;
    int capacity;
} Stack;

typedef struct {
    Token* tokens;
    int count;
    int capacity;
} TokenList;

typedef struct {
    char name[10];
    double (*func)(double);
} MathFunction;

typedef struct {
    char type;    // '(' или ')'
    int position; // позиция в строке
} Bracket;

typedef struct {
    int has_error;
    char error_message[100];
    int error_position;
} ValidationResult;
```

#### `Makefile` (marianbe)
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/graph

SOURCES = $(SRCDIR)/graph.c $(SRCDIR)/stack.c $(SRCDIR)/validation.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lm

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
```

---

## Правила, которые НЕЛЬЗЯ нарушать

### Технические ограничения
1. **Запрещенные библиотеки:** Можно использовать только `<math.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>` и собственные модули
2. **Запрещенные функции:** НЕЛЬЗЯ использовать `system()`, `exit()` и другие системные вызовы
3. **Запрещенные операторы:** НЕЛЬЗЯ использовать `goto`
4. **Глобальные переменные:** ЗАПРЕЩЕНЫ

### Принципы структурного программирования (Дейкстра)
1. **Один вход - один выход:** Каждая функция должна иметь только один вход и один выход
2. **Размер функций:** Не более 42 строк в функции
3. **Вложенность:** Не более 4 уровней вложенности
4. **Базовые конструкции:** Только последовательность, ветвление, цикл
5. **Подпрограммы:** Повторяющиеся фрагменты оформлять в виде функций

### Требования к коду
1. **Стиль:** Соответствие Google Style (clang-format)
2. **Анализ:** Прохождение cppcheck без ошибок
3. **Память:** Отсутствие утечек памяти (проверка leaks/valgrind)
4. **Сборка:** Makefile с целью `all`, исполняемый файл `build/graph`

### Функциональные требования
1. **Размер поля:** 25x80 точек
2. **Область определения:** [0; 4π]
3. **Область значений:** [-1; 1]
4. **Координаты:** Центр в точке {0, 12} (середина левой границы)
5. **Оси:** Ордината направлена вниз, абсцисса - направо
6. **Символы:** "*" для графика, "." для фона
7. **Округление:** По правилам математики

### Поддерживаемые операции
- `+`, `-` (унарный и бинарный), `*`, `/`
- `()`, `sin(x)`, `cos(x)`, `tan(x)`, `ctg(x)`, `sqrt(x)`, `ln(x)`

### Обработка ошибок
- При некорректном выражении выводить "n/a"
- Проверять несбалансированные скобки
- Проверять недопустимые символы
- Проверять некорректную вложенность

---

## Команды для проверки

```bash
# Стиль кода
clang-format -n src/*.c src/*.h

# Статический анализ
cppcheck --enable=all --suppress=missingIncludeSystem src/

# Утечки памяти (MacOS)
leaks -atExit -- ./build/graph | grep LEAK:

# Сборка
make all
```

---

## Дополнительные правила из материалов

### От разработчиков
1. Всю дорогу сопровождает чувство неопределенности - ЭТО НОРМАЛЬНО
2. Уровни могут сильно отличаться друг от друга
3. Игра многопользовательская
4. Будь внимателен к источникам информации
5. Следи за временем - минимум одно испытание в день
6. Всегда делай push только в ветку develop
7. Каждое задание проходит ряд проверок
8. Не жульничай, не пытайся обмануть систему
9. Не списывай, разбирайся до конца
10. Почаще заглядывай в папку materials

### Принципы структурного программирования
1. Отказ от оператора безусловного перехода goto
2. Программа строится из трёх базовых конструкций: последовательность, ветвление, цикл
3. Базовые конструкции могут быть вложены произвольно
4. Повторяющиеся фрагменты оформляются в виде подпрограмм
5. Логически законченные группы инструкций оформляются как блоки
6. Все конструкции должны иметь один вход и один выход
7. Разработка ведётся пошагово, методом «сверху вниз»

### Следствия принципов
1. Запрет на использование глобальных переменных
2. Не более одного выхода из функции
3. Не более одного выхода из цикла
4. Вложенность блоков не должна превышать 4
5. Размер функций не превышает 42 строки
6. Запрет на использование функции exit() 
