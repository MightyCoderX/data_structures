#include <stdio.h>

#include "queue/queue.h"

/* Queue *
 *
 * Functions:
 * - create
 * - enqueue
 * - dequeue
 *
 * head & tail
 *
 * Implementations:
 * - array
 * - circular array (% operator)
 * - linked list
 */

int main(void) {
    LinkedQueue queue = queue_init();

    queue_enqueue(&queue, 10);
    queue_enqueue(&queue, 9);
    queue_enqueue(&queue, 35);

    queue_print(&queue);

    int v = queue_dequeue(&queue);
    printf("%d\n", v);

    queue_print(&queue);

    queue_free(&queue);
    queue_print(&queue);

    return 0;
}
