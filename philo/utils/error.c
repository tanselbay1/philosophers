#include "../philo.h"

int error_msg(const char *msg)
{
    while (*msg)
    {
        write(2, msg, 1); // Write to stderr (file descriptor 2)
        msg++;
    }
    write(2, "\n", 1); // Add a newline
    return (1);
}