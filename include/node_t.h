/**
 *@brief Struct and type definition for node of linked list
 *@file node_t.h
 *
 */

#ifndef NODE_T_H
#define NODE_T_H

/** Struct @c node.
 *
 * Defines a struct for the list elements.
 * @param num  Value
 * @param next  Pointer to next element
*/
typedef struct node{

    int num;
    struct node *next;
}node_t;
#endif
