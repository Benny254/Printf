#include "main.h"

int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size) {
    char c = va_arg(types, int);
    return (handle_write_char(c, buffer, flags, width, precision, size));
}

int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size) {
    int length = 0, i;
    char *str = va_arg(types, char *);

    // ... (remaining code of print_string)

    return (write(1, str, length));
}

int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size) {
    return (write(1, "%%", 1));
}

int print_int(va_list types, char buffer[],
    int flags, int width, int precision, int size) {
    // ... (remaining code of print_int)

    return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

int print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size) {
    // ... (remaining code of print_binary)

    return (count);
}

