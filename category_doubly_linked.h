
#include "category.h"

#ifndef CATEGORYDOUBLYLINKED_H
#define CATEGORYDOUBLYLINKED_H
class CategoryDoublyLinked{
    
public:
	Category* first;
	Category* last;

	Category* loc_category; // TO ITERATE CATEGORIES

    //  TO ITERATE MOVIES
    Movie* ploc_movie;
    Movie* loc_movie;   

	CategoryDoublyLinked() {
		first = NULL;
        last = NULL;
        ploc_movie = NULL;
        loc_movie = NULL;
	};

    bool isEmpty();
    Header* getHeader(string categoryName);
    
    //  EXTERNAL MENU FUNCTIONS
    void addCategory(string categoryName);
    void printAllCategories();
    void printAllMovies();
    Category* searchCategory(string category_name);
    Movie* searchMovie(string movie_name);
    void deleteCategory(string category_name);
    void deleteByReleaseDate(Date to_delete);


    // INTERNAL MENU FUNCTIONS
    void addMovie(Header* current_header, string new_name, Date new_date);
    void getMovieListIndex(Header* current_header, string new_name);
    void printCategoryMovies(Header* current_header); 
    void binarySearchMovie(Header* current_header,string new_name); 

};
#endif 