#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "DoubleLinkedList.h"


//some colors for terminal texts
#define RED "\033[1;31m"  
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define RESET "\033[1m"

double_list_t* create_list_D()
{
    double_list_t* new_list = (double_list_t*) malloc(sizeof(double_list_t));
    if(!new_list)
        return NULL;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->len = 0;

    return new_list;
}

double_node_t* create_node_D(void* val)
{
    double_node_t* new_node = (double_node_t*) malloc(sizeof(double_node_t));
    if(!new_node)
        return NULL;

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->val = val;

    return new_node;
}



void list_right_push_D(double_list_t* list, double_node_t* node)
{
    if(!node || !list)
        return;

    if(list->len > 0)
    {
        node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        node->next = NULL;
        node->prev = NULL;
        list->head = node;
        list->tail = node;
    }

    list->len++;
}
//Define
void List_at_middle_push_D(double_list_t* list, double_node_t* node,int index)
{
    if(!list || !node)
        return;

    double_node_t* temp;
    if(list->len > 0)
    {
        node->next = NULL;
        temp = list->head;

        for (int i = 0; i < index-2; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                return;
        }
        if (temp != NULL)
        {
            node->next = temp->next;
            temp->next = node;
        }
    }
    else
    {
        node->next = NULL;
        node->prev = NULL;
        list->head = node;
        list->tail = node;
    }
    
    list->len++;

}
//Define
void list_right_pop_D(double_list_t* list)
{
    if(!list || list->len == 0)
        return;

    double_node_t* node = list->tail;

    if(list->len > 1)
    {
        list->tail = node->prev;
        list->tail->next = NULL;
    } 
    else
    {
        list->tail = NULL;
        list->head = NULL;
    }
    
    list->len--;
    free(node);    
    free(list);

}

void list_left_push_D(double_list_t* list, double_node_t* node)
{
    if(!list || !node)
        return;

    if(list->len > 0)
    {
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }

    list->len++;   
}

void list_left_pop_D(double_list_t* list)
{
    double_node_t* node = list->head;

    if(!list || !node)
        return;

    if (list->len > 1)
    {
        list->head = node->next;
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
        list->head = NULL;
    }
    list->len--;
    free(node);
    free(list);

}

double_node_t* finde_node_D(double_list_t* list, void* val)
{
    if(!list)
        return NULL;

    double_node_t* node = list->head;

    while(node != NULL)
    {
        if (node->val == val)
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

double_node_t* node_at_index_D(double_list_t* list, int index)
{
    if(!list || index < 0 || index >= list->len)
        return NULL;

    int current_index = 0;
    double_node_t* node = list->head;

    while(current_index < list->len)
    {
        if (current_index == index)
        {
            return node;
        }

        node = node->next;
        current_index++;
    }

    return NULL;
}

void delete_list_D(double_list_t* list)
{
    if(!list)
        return;

    unsigned int len = list->len;
    double_node_t* next;
    double_node_t* curr = list->head;

    while(len > 0)
    {
        next = curr->next;

        free(curr);
        curr = next;
        len--;
    }

    list->len = 0;
    list->head = NULL;
    list->tail = NULL;
    free(next);

}

void remove_node_D(double_list_t* list, double_node_t* node)
{
    if(!list || !node)
        return;

    if (node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        list->head = node->next;
    }
    
    if (node->next)
    {
        node->next->prev = node->prev;
    }
    else
    {
        list->tail = node->prev;
    }
    
    free(node);
    free(list);

    list->len--;
}

void ConsoleD_char(double_list_t* list)
{
    if(!list)
        return;

    int index = 0;
    double_node_t* node = list->head;
    printf(RED"\nPrinting DoubleLinkedList that contains %d elements.\n"RESET, list->len);

    while(node != NULL)
    {
        printf(BLUE"Current node  value: %s, At position %d.\n"RESET, (char*)node->val, index + 1);

        node = node->next;
        index++;
    }
}

void ConsoleD_int(double_list_t* list)
{
    if(!list)
        return;

    int index = 0;
    double_node_t* node = list->head;
    printf(RED"\nPrinting DoubleLinkedList that contains %d elements.\n"RESET, list->len);

    while(node != NULL)
    {
        printf(BLUE"Current node  value: %d, At position %d.\n"RESET, (int*)node->val, index + 1);

        node = node->next;
        index++;
    }
}
