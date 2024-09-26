#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _div(stack_t **doubly, unsigned int cline)
{
    int i = 0;
    stack_t *x = NULL;

    x = *doubly;

    for (; x != NULL; x = x->next, i++)
        ;

    if (i < 2)
    {
        dprintf(2, "L%u: can't div, stack too short\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    if ((*doubly)->n == 0)
    {
        dprintf(2, "L%u: division by zero\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    x = (*doubly)->next;
    x->n /= (*doubly)->n;
    _pop(doubly, cline);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mul(stack_t **doubly, unsigned int cline)
{
    int i = 0;
    stack_t *aa = NULL;

    aa = *doubly;

    for (; aa != NULL; aa = aa->next, i++)
        ;

    if (i < 2)
    {
        dprintf(2, "L%u: can't mul, stack too short\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    aa = (*doubly)->next;
    aa->n *= (*doubly)->n;
    _pop(doubly, cline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mod(stack_t **doubly, unsigned int cline)
{
    int pop = 0;
    stack_t *a = NULL;

    a = *doubly;

    for (; a != NULL; a = a->next, pop++)
        ;

    if (pop < 2)
    {
        dprintf(2, "L%u: can't mod, stack too short\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    if ((*doubly)->n == 0)
    {
        dprintf(2, "L%u: division by zero\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    a = (*doubly)->next;
    a->n %= (*doubly)->n;
    _pop(doubly, cline);
}

/**
 * _pchar - print the char value of the first element
 *
 * @k: head of the linked list
 * @c: line number;
 * Return: no return
 */
void _pchar(stack_t **k, unsigned int c)
{
    if (k == NULL || *k == NULL)
    {
        dprintf(2, "L%u: can't pchar, stack empty\n", c);
        free_vglo();
        exit(EXIT_FAILURE);
    }
    if ((*k)->n < 0 || (*k)->n >= 128)
    {
        dprintf(2, "L%u: can't pchar, value out of range\n", c);
        free_vglo();
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*k)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @d: head of the linked list
 * @c: line number;
 * Return: no return
 */
void _pstr(stack_t **d, unsigned int c)
{
    stack_t *i;
    (void)c;

    i = *d;

    while (i && i->n > 0 && i->n < 128)
    {
        printf("%c", i->n);
        i = i->next;
    }

    printf("\n");
}
