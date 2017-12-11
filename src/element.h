#ifndef DEF_ELEMENT

#define DEF_ELEMENT

/* Structures */
typedef struct Element Element;
struct Element
{
    int number;
    Element *previous;
    Element *next;
};

typedef struct List List;
struct List
{
    Element *first;
    int listSize;
};


/* Prototypes */
List *initialization(int number);
void addElement(List *list, int number);
void deleteElement(List *list);
void deleteList(List *list);
void displayList(List *list);

#endif // DEF_ELEMENT
