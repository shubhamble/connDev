#include "connDev.h"
#include "runtimePoly.h"

int sum(std::vector<int> v){
    int sum = 0;
    for(int r:v){
        sum+=r;
    }
    return sum;
}

int sum(std::queue<int> q){
    int sum=0;
    while(!q.empty()){
        sum+= q.front();
    }
    return sum;
}

int main(int argc, char *argv[]) {
    #ifdef ANIMAL
        Animal* animal1 = new Dog();
        Animal* animal2 = new Cat();

        // Runtime polymorphism: correct derived class function is called
        animal1->sound();  // Output: Dog barks
        animal2->sound();  // Output: Cat meows

        // Clean up
        delete animal1;
        delete animal2;

        Cat *c1 = new Cat();
        c1->sound();
        delete c1;
    #endif

    cFunction();

    std::cout << "Parsing the arguments: \n1. For vector 2. For queue " << std::endl;

    // Parse arguments
    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "-v") == 0) {
            std::cout << "Running vector sum function: " << std::endl;
            std::vector<int> v = {2, 3, 4, 3};
            std::cout << "Sum is: " << sum(v) << std::endl;
        }
        if (std::strcmp(argv[i], "-q") == 0) {
            std::cout << "Running Queue sum: " << std::endl;
            std::queue<int> q;
            q.push(12);
            q.push(20);
            q.push(30);
            std::cout << "Sum is: " << sum(q) << std::endl;
        }
        else {
            std::cout << "Unknown argument: " << argv[i] << std::endl;
        }
    }

    // ************
    // Please give video file name
    // ************
    #ifdef VIDEO
        std::cout << "Parsing the arguments" << std::endl;
        if (argc < 2) {
            fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
            return -1;
        }
        std::cout << "Print media: " << print_media_info(argv[1]) << std::endl;
    #endif

    // Call the media info function from the module
    return 0;
}
