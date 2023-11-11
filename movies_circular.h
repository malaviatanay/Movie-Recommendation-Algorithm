#include "movie.h"
#ifndef MOVIESCIRCULAR_H
#define MOVIESCIRCULAR_H
class MoviesCircular {
    public:
		// MOVIE NODES TO STORE HEAD AND LAST NODE OF CIRCULAR LINKED LIST, PLOC AND LOC AS HELPERS IN BINARY SEARCH
		Movie* first;
		Movie* last;
		Movie* ploc;
		Movie* loc;
	
    	MoviesCircular() {
			first = NULL;
			last = NULL;
			ploc = NULL;
			loc = NULL;	
			}

		//	CHECKS IF NO NODES ARE PRESENT IN MOVIES LIST
		bool isEmpty();
		// ADD A MOVIE WITHIN A CATEGORY
    	Movie* addMovie(string newName, Date newDate);
		// FETCH THE INDEX OF MOVIE IN CATEGORY
		int getMovieListIndex(string movieName);
		// PRINT ALL MOVIES WITHIN A CATEGORY
		void printCategoryMovies();
		Movie* binarySearchMovie(string movie_name);
	};
#endif 