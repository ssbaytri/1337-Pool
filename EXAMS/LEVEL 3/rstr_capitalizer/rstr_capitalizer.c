#include <unistd.h>

// Check if the character is a letter
int ft_is_letter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_is_space(char c) {
    return (c == ' ' || c == '\t' || c == '\0');
}

// Convert uppercase to lowercase
char ft_to_lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

// Convert lowercase to uppercase
char ft_to_upper(char c) {
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

// Capitalize the last letter of each word
void rstr_capitalizer(char *str) {
    int i = 0;
    
    while (str[i]) {
        if (ft_is_letter(str[i])) {
            if (ft_is_space(str[i + 1])) {
                str[i] = ft_to_upper(str[i]);
            } else {
                str[i] = ft_to_lower(str[i]);
            }
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        write(1, "\n", 1);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        rstr_capitalizer(argv[i]);
        write(1, "\n", 1); // Print newline after each argument
    }
    return 0;
}
