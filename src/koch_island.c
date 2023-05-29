#include <stdio.h>
#include <stdlib.h>

typedef struct string {
	int size;
	char* _string;
} String;

String * new_string(char* c){
	String* s = (String *) malloc(1 * sizeof(String));;
	s->size = 1;
	s->_string = c;

	return s;
}

String* concatenate(String** s_array, int array_size){
	String* destination = (String *) malloc(1 * sizeof(String));

	for(int j = 0; j < array_size; j++){
		int initial_position = destination->size;
		destination->size += s_array[j]->size;
		destination->_string = (char *) realloc(destination->_string,  destination->size * sizeof(char*));

		for(int i = initial_position; i < destination->size; i++)
			destination->_string[i] = s_array[j]->_string[i-initial_position];
	}

	return destination;
}

String* get_fractal(int stage){
	String* f = new_string("F");

	if(stage == 0)
		return f;

	String* plus = new_string("+");
	String* minus = new_string("-");

	String* fractal = get_fractal(stage - 1);

	String *recurrency_rule [15] = {
		fractal,
		plus,
		fractal,
		minus,
		fractal,
		minus,
		fractal,
		fractal,
		fractal,
		plus,
		fractal,
		plus,
		fractal,
		minus,
		fractal
	};

	return concatenate(recurrency_rule, 15);
}

void write_fractal(int size){
	String* s = get_fractal(size - 1);

	printf("%s+%s+%s+%s\n", 
		s->_string, 
		s->_string, 
		s->_string, 
		s->_string);
}


int main(){ 
	int size;
	scanf("%d", &size);
	write_fractal(size);
}
