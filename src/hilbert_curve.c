#include <stdio.h>
#include <stdlib.h>

typedef struct string {
	int size;
	char* _string;
} String;

String* get_X(int stage);
String* get_Y(int stage);

String * new_string(char* c){
	String* s = (String *) malloc(1 * sizeof(String));
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
        String *recurrency_rule [7] = { plus, f, minus, f, minus, f, plus};
        return concatenate(recurrency_rule, 7);
    } else {
        String *recurrency_rule [11] = { plus, x, f, minus, y, f, y, minus, f, x, plus };
        return concatenate(recurrency_rule, 11);
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
        String *recurrency_rule [7] = { minus, f, plus, f, plus, f, minus };
        return concatenate(recurrency_rule, 7);
    } else {
        String *recurrency_rule [11] = {minus, y, f, plus, x, f, x, plus, f, y, minus};
        return concatenate(recurrency_rule, 11);
    }
}

void write_fractal(int size, FILE* f ){
	String* s = get_X(size);
	fprintf(f, "----------------------------------------------------------------------------------------------------------------------------------------------");
	fprintf(f, "\nEstágio %d: %s\n", size, s->_string);
}

int main(){
	FILE* f = fopen("./files_output/hilbert_curve.txt", "w");
	fprintf(f, "# PREENCHIMENTO DE ESPAÇO DE HILBERT\n");
	fprintf(f, "# Leonardo Borges de Oliveira - Universidade Federal de Minas Gerais\n");

	int num_fractal;
	int degree;
	char axiom[2]; 
	char rulex[12];
	char ruley[12];

	printf("Insira o axioma: ");
	scanf("%s", axiom);
	printf("Insira o angulo: ");
	scanf("%d", &degree);
	printf("Insira a regra x: ");
	scanf("%s", rulex);
	printf("Insira a regra y: ");
	scanf("%s", ruley);

	fprintf(f, "#\n# Axioma: %s\n# Ângulo: %d\n# Regra de X: %s\n# Regra de Y: %s\n#\n", axiom, degree, rulex, ruley);
	fprintf(f, "# Estágios do Fractal:\n");

	for(int i = 1; i <= 4; i++) 
		write_fractal(i, f);

	fclose(f);
}
