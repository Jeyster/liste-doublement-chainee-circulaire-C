#include <stdio.h>
#include <stdlib.h>
#include "element.h"

int main()
{
    List *list = initialization(1);

    if (list == NULL)
    {
        printf("!!! Erreur lors de l'initialisation, arret du programme !!!\n");
        exit(0);
    }

    addElement(list, 2);
    displayList(list);

    addElement(list, 3);
    addElement(list, 4);
    addElement(list, 5);
    displayList(list);

    deleteElement(list);
    deleteElement(list);
    deleteElement(list);
    deleteElement(list);
    deleteElement(list);
    displayList(list);

    addElement(list, 1);
    displayList(list);

    addElement(list, 2);
    addElement(list, 3);
    addElement(list, 4);
    addElement(list, 5);
    displayList(list);

    deleteList(list);
    displayList(list);

    /* !!! DEBUG !!! */
    /*
    int elementPosition = 4;
    printf("Element a la position %d : %d\n", elementPosition, getElement(list, elementPosition)->number);
    */
    /*
    printf("Pointeur de la liste : %d\n", list->first);
    printf("Adresse premier element : %d\n", &(list->first->number));
    printf("Premier element : %d\n", list->first->number);
    printf("Pointeur previous du premier element : %d\n", list->first->previous);
    printf("Pointeur next du premier element : %d\n", list->first->next);
    printf("Adresse dernier element : %d\n", &(list->first->next->number));
    printf("Dernier element : %d\n", list->first->next->number);
    printf("Pointeur previous du dernier element : %d\n", list->first->next->previous);
    printf("Pointeur next du dernier element : %d\n", list->first->next->next);
    */
    /* !!! DEBUG !!! */

    return 0;
}
