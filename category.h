#include "movies_circular.h"
#include "header.h"
class Category {
public:
    string data;
    // USING PREVIOUS AND NEXT POINTERS FOR DOUBLY LINKED LIST
    Category* previous;
    Category* next;
    Header* header; // HEADER NODE FOR EACH CATEGORY

    Category(string new_name, Header* new_header) : data(new_name), header(new_header){
        previous = NULL;
        next = NULL;
        }
    };