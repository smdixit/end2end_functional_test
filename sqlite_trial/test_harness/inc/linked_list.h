#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef LINKED_LIST_C
#define EXTERN extern
#else
#define EXTERN
#endif

#include <stdio.h>

/**
 * @brief Holds an element and pointer to next
 *
 * A pointer to an element which can be any user data.
 * Also holds pointer to next node.
 */
typedef struct ListEle{
	void *data;				/**< pointer to arbitrary user data. */
	struct ListEle *next;	/**< pointer to next node. */
}LISTELE_T;

/**
 * @brief Holds a List.
 *
 * Pointer to head and tail of this List.
 */

 void Callout_one(void);
 void Callout_3(void);

#undef EXTERN
#endif

