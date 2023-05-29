#include <stdio.h>
#include <stdlib.h>

typedef struct string {
	int size;
	char* _string;
} String;

String* get_X(int);
String* get_Y(int);

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

String* get_Y(int stage){
	if(stage == 0)
		return NULL;

    String* y = get_Y(stage - 1);
	String* x = get_X(stage - 1);
    String* f = new_string("F");
	String* plus = new_string("+");
	String* minus = new_string("-");

    if(y == NULL || x == NULL){
        String *recurrency_rule [8] = { plus, f, f, minus, f, f, plus, plus };
        return concatenate(recurrency_rule, 8);
    } else {
        String *recurrency_rule [13] = { plus, x, f, f, minus, y, x, f, y, f, x, plus, plus };
        return concatenate(recurrency_rule, 13);
    }
}

String* get_X(int stage){
	if(stage == 0)
		return NULL;

    String* f = new_string("F");
    String* y = get_Y(stage - 1);
	String* x = get_X(stage - 1);
	String* plus = new_string("+");
	String* minus = new_string("-");

    if(y == NULL || x == NULL){
        String *recurrency_rule [8] = { minus, f, f, plus, f, f, minus, minus};
        return concatenate(recurrency_rule, 8);
    } else {
        String *recurrency_rule [13] = {minus, y, f, f, plus, x, y, f, x, f, y, minus, minus};
        return concatenate(recurrency_rule, 13);
    }
}

void write_fractal(int size){
	String* x = get_X(size);
	String* y = get_Y(size);

	printf("%s+%s\n", x->_string, y->_string);
}

int main(){ 
	int size;
	scanf("%d", &size);
	write_fractal(size);
}
