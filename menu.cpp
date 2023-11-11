#include "category_doubly_linked.cpp"

class Menu{
    public:
    CategoryDoublyLinked navigator;
    Header* current_header = NULL;
};


    int main(){
    Menu menu;

    menu.navigator.addCategory("Children");


    menu.current_header = menu.navigator.getHeader("Children");
    menu.navigator.addMovie(menu.current_header,"Barbie",Date(2002,8,4));
    menu.navigator.addMovie(menu.current_header,"Harry Potter",Date(2005,3,4));
    menu.navigator.addMovie(menu.current_header,"Lion King", Date(2008,7,5));
    menu.navigator.printCategoryMovies(menu.current_header);

    menu.navigator.getMovieListIndex(menu.current_header,"Lion King");
    menu.navigator.binarySearchMovie(menu.current_header,"Lion King");
    menu.navigator.binarySearchMovie(menu.current_header,"Tekken");
    menu.navigator.binarySearchMovie(menu.current_header,"Harry Potter");
    menu.navigator.searchMovie("Barbie");


    menu.navigator.deleteByReleaseDate(Date(2003,12,12));
    menu.navigator.printCategoryMovies(menu.current_header);


    menu.navigator.addCategory("Action");
    menu.current_header = menu.navigator.getHeader("Action");
    menu.navigator.addMovie(menu.current_header,"Tekken",Date(2002,8,4));
    menu.navigator.addMovie(menu.current_header,"Rocky",Date(2002,8,4));
    menu.navigator.addMovie(menu.current_header,"Tekken",Date(2002,8,4));
    menu.navigator.printAllMovies();

    
    menu.navigator.addCategory("Comedy");
    menu.current_header = menu.navigator.getHeader("Comedy");
    menu.navigator.addMovie(menu.current_header,"Harold & Kumar",Date(2002,8,4));
    menu.navigator.addMovie(menu.current_header,"Jerry McGuire",Date(2002,8,4));
    menu.navigator.addMovie(menu.current_header,"Tuxedo",Date(2002,8,4));
    menu.navigator.printAllMovies();
    menu.navigator.deleteCategory("Comedy");
    menu.navigator.printAllCategories();
    
    return 0;
}
