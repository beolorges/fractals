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

void write_fractal(int size, FILE* f ){
	String* x = get_X(size);
	String* y = get_Y(size);

	fprintf(f, "----------------------------------------------------------------------------------------------------------------------------------------------");
	fprintf(f, "\nEstágio %d: %s+%s\n", size, x->_string, y->_string);

}

int main(){ 
	FILE* f = fopen("./files_output/my_curve.txt", "w");
	fprintf(f, "# PREENCHIMENTO DE ESPAÇO DE LEONARDO\n");
	fprintf(f, "# Leonardo Borges de Oliveira - Universidade Federal de Minas Gerais\n");

	int degree = 60;
	char axiom[4] = "X+Y"; 
	char rulex[14] = "-YFF+XYFXFY--"; 
	char ruley[14] = "+XFF-YXFYFX++";

	fprintf(f, "#\n# Axioma: %s\n# Ângulo: %d\n# Regra de X: %s\n# Regra de Y: %s\n#\n", axiom, degree, rulex, ruley);
	fprintf(f, "# Estágios do Fractal:\n");

	for(int i = 1; i <= 4; i++) 
		write_fractal(i, f);

	fclose(f);
}
