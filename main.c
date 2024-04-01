#include"monty.h"
int main(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, USAGE);
        exit(EXIT_FAILURE);
    }
    
    process_file(argv[1]);

    return 0;
}
