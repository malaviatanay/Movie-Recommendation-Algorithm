#include "movies_circular.h"
#include <vector>
bool MoviesCircular::isEmpty() {
		if (first==NULL) return true;
    	else return false;
	}

Movie* MoviesCircular::addMovie(string newName, Date newDate) {
   	Movie* newNode = new Movie(newName,newDate);

	// IF THERE ARE NO MOVIES IN LIST
	if (isEmpty()){	
		newNode->next=newNode;
		last = newNode;
        first = newNode;
		}

	// IF LOGICAL POSITION OF NEW NODE IS AFTER LAST NODE
	else if (newNode->data >= last->data) {
        last->next = newNode;
        newNode->next = first;
        last = newNode; 
    	}

	// IF LOGICAL POSITION OF NEW NODE IS BEFORE FIRST NODE
	else if (newNode->data <= first->data) {
        newNode->next = first;
        first = newNode;
        last->next = first;
    	} 
		
	// IF LOGICAL POSITION IS SOMEWHERE IN MIDDLE OF LIST
	else {
    	ploc = first;
    	while (newNode->data > ploc->next->data) {
         	ploc = ploc->next;
    	}	
		//	PLACING BETWEEN PLOC AND PLOC->NEXT
    	newNode->next = ploc->next;
    	ploc->next = newNode;
    	}

	return first;

	}


int MoviesCircular::getMovieListIndex(string movieName){
	if(!isEmpty()){
		Movie* iterator = first;
		int index = 1;
		while(iterator->next!=first){
			if(movieName==iterator->data){
				break;
				}
			index+=1;
			iterator=iterator->next;
			}
		return index;
		}
	return 0;	//	FOR EMPTY LIST
	}


void MoviesCircular::printCategoryMovies(){
	if(!isEmpty()){
		Movie* iterator = first;
		int index = 1;
		do{
			cout << index <<  ". MOVIE NAME: " << iterator->data << endl;
			cout << "RELEASE DATE: " << iterator->release_date.printDate() << endl;
			iterator=iterator->next;
			index+=1;
			}while (iterator != first);
		}
	}
  
Movie* MoviesCircular::binarySearchMovie(string movie_name)
{
    ploc = first;
    loc = last;
	Movie* mid_node = NULL;

    do{
		Movie* iterator = ploc;

		if (ploc->next==first){	// IF ONLY ONLY NODE LEFT
			mid_node = ploc;
			}

		//	FINDING MID NODE
		else{

			int index = 1;
			vector<int>v;

			while(iterator->next!=ploc){
				v.push_back(index);
				iterator=iterator->next;
				index+=1;
				
				}
    		int middle = v.size()/2;	// GIVES MIDDLE INDEX
			iterator=ploc;
			index = 1;

			while(iterator->next!=ploc){
				if(index==middle){	// FINDING MIDDLE ELEMENT
					mid_node = iterator;
					break;
				}
				iterator=iterator->next;
				index+=1;
				}
			}
		
		// SEARCHING FOR MOVIE

		if (mid_node == NULL)
            return NULL;
		// IF FOUND
        if (mid_node -> data == movie_name){
			cout<<mid_node->data<<" FOUND"<<endl;
            return mid_node;
		}
		// NOT FOUND
		if(ploc==loc){
			cout<<movie_name<<" NOT FOUND"<<endl;
			return NULL;
		}
		else if (movie_name >= mid_node->data)
            loc = mid_node;	
        else 
			 ploc = mid_node -> next;
    } while (true);
    
}
