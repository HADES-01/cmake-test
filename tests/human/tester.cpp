#include <Human.h>
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "\nTesting Human Library\n\n";
    if(argc < 2) return 1;
    Human h(atoi(argv[1]), std::string(argv[2]));
    h.show_age();
    h.show_name();
    return 0;
}