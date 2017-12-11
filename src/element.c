#include <stdio.h>
#include <stdlib.h>
#include "element.h"


List *initialization(int number)
{
    List *list = malloc(sizeof(*list));
    Element *firstElt = malloc(sizeof(*firstElt));

    if (firstElt == NULL || list == NULL)
    {
        printf("!!! Erreur allocation memoire lors de l'initialisation, arret du programme !!!\n");
        exit(EXIT_FAILURE);
    }

    firstElt->number = number;
    firstElt->previous = NULL;
    firstElt->next = NULL;
    list->first = firstElt;
    list->listSize = 1;

    return list;
}


void addElement(List *list, int number)
{
    Element *newElt = malloc(sizeof(*newElt));
    if (newElt == NULL)
    {
        printf("!!! Erreur allocation memoire lors de l'ajout d'un element, arret du programme !!!\n");
        exit(EXIT_FAILURE);
    }

    newElt->number = number;

    if (list->listSize == 0)
    {
        newElt->previous = NULL;
        newElt->next = NULL;
        list->first = newElt;
    }
    else if (list->listSize == 1)
    {
        newElt->previous = list->first;
        newElt->next = list->first;
        list->first->previous = newElt;
        list->first->next = newElt;
        list->first = newElt;
    }
    else
    {
    	newElt->previous = list->first->previous;
    	newElt->next = list->first;
    	list->first->previous->next = newElt;
    	list->first->previous = newElt;
    	list->first = newElt;
    }

    list->listSize++;
}


void deleteElement(List *list)
{
    Element *toDelete = list->first;
    if (toDelete == NULL)
    {
        printf("!!! ERREUR : pas d'element a supprimer, arret du programme !!!\n");
        exit(EXIT_FAILURE);
    }

    if (list->listSize == 1)
    {
    	list->first = NULL;
    }
    else if (list->listSize == 2)
    {
    	toDelete->previous->next = NULL;
    	toDelete->next->previous = NULL;
    	list->first = toDelete->next;
    }
    else
    {
    	toDelete->previous->next = toDelete->next;
    	toDelete->next->previous = toDelete->previous;
    	list->first = toDelete->next;
    }

    free(toDelete);
    list->listSize--;
}


void deleteList(List *list)
{
    while (list->first != NULL)
    {
        Element *toDelete = list->first;
        if (list->listSize == 1)
        {
        	list->first = NULL;
        }
        else if (list->listSize == 2)
        {
        	toDelete->previous->next = NULL;
        	toDelete->next->previous = NULL;
        	list->first = toDelete->next;
        }
        else
        {
        	toDelete->previous->next = toDelete->next;
        	toDelete->next->previous = toDelete->previous;
        	list->first = toDelete->next;
        }
        free(toDelete);
        list->listSize--;
    }
}


void displayList(List *list)
{
    printf("Taille de la liste : %d\n", list->listSize);

    Element *currentElt = list->first;

    if (currentElt == NULL)
    {
    	printf("Liste vide !\n\n");
    }
    else
    {
        for (int i = 0; i < list->listSize; i++)
        {
            printf("%d -> ",currentElt->number);
            currentElt = currentElt->next;
        }
        printf("...\n\n");
    }
}
