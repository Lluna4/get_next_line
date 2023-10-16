#include "get_next_line.h"

int test_nl_0l(char *buffer, size_t size)
{
    size_t index = 0;
    while (index < size)
    {
        if (buffer[index] == '\n' || buffer[index] == '\0')
            return 1;
        index++;
    }
    return 0;
}

char    *get_next_line(int fd)
{
    static char *permanence;
    char *buffer;
    struct linked_list *head = NULL;
    int read_status = 0;
    int first = 1;

    if (!head)
    {
        return (NULL);
    }

    buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    if (permanence)
    {
        memcpy(buffer, permanence, strlen(permanence));
        memset(permanence, 0, BUFFER_SIZE);
    }
    else
    {
        read_status = read(fd, buffer, BUFFER_SIZE);
        if (read_status == -1)
        {
            free(buffer);
            free(head);
            return (NULL);
        }
        else if (read_status == 0 || test_nl_0l(buffer, strlen(buffer)) == 1)
        {
            free(head);
            return (buffer);
        }
    }

    struct linked_list *temp = head;

    while (1)
    {
        if (first == 1)
        {
            head = malloc(sizeof(struct linked_list));
            temp = head;
            first = 0;
        }
        else
        {
            temp->next = malloc(sizeof(struct linked_list));
            temp = temp->next;
        }

        read_status = read(fd, buffer, BUFFER_SIZE);
        if (read_status == -1)
        {
            free(buffer);
            free(head);
            return (NULL);
        }
        else if (read_status == 0 || test_nl_0l(buffer, strlen(buffer)) == 1)
        {
            free(head);
            return (buffer);
        }
        temp->data = strdup(buffer);
        temp->next = NULL;
        free(buffer);
    }
}
