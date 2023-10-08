#ifndef TABLE_ARRAY
#define TABLE_ARRAY

const short TableSize = 100;
const short TableOk = 0;
const short TableEmpty = 1;
const short TableFull = 0;
const short TableNoKey = 0;
extern short TableError;

#define BaseType int

typedef struct {
    int key;
    BaseType data;
} element;

typedef struct {
    element Buf[TableSize];
    short Uk;
} Table;

void TableInit(Table *T);

/*Если таблица не переполнена, осуществить линейный поиск и если найден ключ,
то обновляем элемент. Иначе - записываем элемент в конец и увеличиваем Uk на 1.*/
void TablePut(Table *T, element E);


#endif