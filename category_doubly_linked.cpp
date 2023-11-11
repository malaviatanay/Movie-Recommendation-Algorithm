
#include "movies_circular.cpp"
#include "category_doubly_linked.h"

bool CategoryDoublyLinked::isEmpty() {
	if (first==NULL) return true;
    else return false;
    }

Header* CategoryDoublyLinked::getHeader(string category_name){
    cout << endl<<"MOVING TO CATEGORY " << category_name << endl << endl;
    return searchCategory(category_name)->header;
    }

//  EXTERNAL MENU FUNCTION

void CategoryDoublyLinked::addCategory(string category_name){
	Category* new_node = new Category(category_name, (new Header(new MoviesCircular())));
    cout << "ADDING " << category_name << " TO CATEGORY LIST"<<endl;

	if (isEmpty()){
		first = new_node;
		last = new_node;
	}
	else{
		last->next = new_node;
		new_node->previous = last;
		last = new_node;
	    }
    }

void CategoryDoublyLinked::printAllCategories(){
    Category* iterator = first;
	cout << "THE FOLLOWING ARE THE CATEGORIES" << endl;
    int index=1;
	if (!isEmpty()){
		while (iterator != NULL){
			cout << index << ". " << iterator->data << endl;;
			iterator = iterator->next;
            index+=1;
		    }
	    }
	cout << endl;
    }

void CategoryDoublyLinked::printAllMovies(){
    cout << "PRINTING ALL MOVIES" << endl;
    loc_category = first;
    while (loc_category != NULL) {
        cout<<"FOR CATEGORY "<<loc_category->data<<endl;
        loc_movie = loc_category->header->movieList->first;
        loc_category->header->movieList->printCategoryMovies();
        loc_category = loc_category->next;
    }
    cout<<endl<<endl;
}


Category* CategoryDoublyLinked::searchCategory(string category_name){
    loc_category = first;
    while (loc_category != NULL) {
        if (loc_category->data == category_name) {
            return loc_category;
            }
        loc_category = loc_category->next;
        }
    return NULL;
    }

Movie* CategoryDoublyLinked::searchMovie(string movie_name) {
    cout << "SEARCHING FOR "<< movie_name << endl;
    loc_category = first;
    while (loc_category != NULL) {
        return loc_category->header->movieList->binarySearchMovie(movie_name);
        loc_category = loc_category->next;
        }
    return NULL;
    }

void CategoryDoublyLinked::deleteCategory(string category_name){
    
    cout << endl << "REMOVING " << category_name << " FROM CATEGORIES" << endl;
    Category* to_delete = searchCategory(category_name);

    // DELETING ALL MOVIES IN CATEGORY
    if(!(to_delete->header->movieList->isEmpty())){
		Movie* del_movie = to_delete->header->movieList->last->next;
		while (to_delete->header->movieList->last->next != to_delete->header->movieList->last) {    // ITERATE TO END OF LIST
			del_movie = to_delete->header->movieList->last->next;
			to_delete->header->movieList->last->next = to_delete->header->movieList->last->next->next;
			delete del_movie;
		}
	}

    // IF CATEGORY TO DELETE IS PRESENT AT START OF LIST
    if (to_delete->previous==NULL){
        Category* temp = first;
		first = first->next;
		first->previous = NULL;
		delete temp;
    }
    // IF CATEGORY TO DELETE IS PRESENT AT END OF LIST
    else if (to_delete->next==NULL){
        Category* temp = last;
		last = last->previous;
		last->next = NULL;
		delete temp;
    }
    // IF CATEGORY TO DELETE IS IN MIDDLE
    else{
        (to_delete->previous)->next = to_delete->next;
		(to_delete->next)->previous = to_delete->previous;
		delete to_delete;
    }
}


void CategoryDoublyLinked::deleteByReleaseDate(Date delete_before){
    cout << "DELETING ALL MOVIES RELEASED BEFORE " << delete_before.printDate() << endl;
    loc_category = first;
    while (loc_category != NULL) {
        loc_movie = loc_category->header->movieList->first;
        ploc_movie = loc_category->header->movieList->last;
        while (loc_movie != NULL) {
            if (loc_movie->release_date.compareDates(delete_before)) {
                Movie* toDelete = loc_movie;
                loc_movie = loc_movie->next;
                if (loc_category->header->movieList->first == toDelete && loc_category->header->movieList->last == toDelete){
                    loc_category->header->movieList->first = NULL;
                    loc_category->header->movieList->last = NULL;
                    loc_category->header = NULL;
                    break;
                }
                else 
                if (loc_category->header->movieList->first == toDelete) {
                    loc_category->header->movieList->first = toDelete->next;
                    loc_category->header->movieList->last = toDelete->next;
                }
                ploc_movie->next = toDelete->next;
                delete toDelete;
            }
            else{ 
                ploc_movie = loc_movie;
                loc_movie = loc_movie->next;
                if (loc_movie == loc_category->header->movieList->first) {
                    break;
                }
            }
        }
        loc_category = loc_category->next;
    }
}

// INTERNAL MENU FUNCTIONS

void CategoryDoublyLinked::addMovie(Header* current_header, string movie_name, Date movie_date) {
    if (current_header->movieList->first == NULL) {
        current_header->movieList->addMovie(movie_name,movie_date);
        current_header->movieList->first =current_header->movieList->first;
    }
    else{
        current_header->movieList->first = current_header->movieList->addMovie(movie_name,movie_date);
    }
}

void CategoryDoublyLinked::getMovieListIndex(Header* current_header,string movie_name){
    if (current_header->movieList->first == NULL){
        cout<<"MOVIE NOT FOUND";
    }
    else{
        cout<< movie_name << "\tINDEX: " <<current_header->movieList->getMovieListIndex(movie_name) << endl;;
    }
}

void CategoryDoublyLinked::printCategoryMovies(Header* current_header){
    cout << "PRINTING MOVIES FOR THE CATEGORY" << endl;
    if (current_header->movieList->first == NULL){
        cout<<"MOVIES NOT FOUND"<<endl;
    }
    else{
        current_header->movieList->printCategoryMovies();
    }
}

void CategoryDoublyLinked::binarySearchMovie(Header* current_header,string movie_name){
    if (current_header->movieList->first == NULL){
        cout<<"MOVIE NOT FOUND"<<endl;
    }
    else{
        cout << "SEARCHING FOR "<<movie_name<<endl;;
        current_header->movieList->binarySearchMovie(movie_name);
    }
};







