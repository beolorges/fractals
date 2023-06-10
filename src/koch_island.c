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

void write_fractal(int size, FILE* f ){
	String* s = get_fractal(size);
	
	fprintf(f, "----------------------------------------------------------------------------------------------------------------------------------------------");
	fprintf(f, "\nEstágio %d: %s+%s+%s+%s\n", 
		size,
		s->_string, 
		s->_string, 
		s->_string, 
		s->_string);

}


int main(){ 
	FILE* f = fopen("./files_output/koch_island.txt", "w");
	fprintf(f, "# ILHA DE KOCH\n");
	fprintf(f, "# Leonardo Borges de Oliveira - Universidade Federal de Minas Gerais\n");

	int num_fractal;
	int degree;
	char axiom[8]; 
	char rule[16];

	printf("Insira o axioma: ");
	scanf("%s", axiom);
	printf("Insira o angulo: ");
	scanf("%d", &degree);
	printf("Insira a regra: ");
	scanf("%s", rule);

	fprintf(f, "#\n# Axioma: %s\n# Ângulo: %d\n# Regra: %s\n#\n", axiom, degree, rule );
	fprintf(f, "# Estágios do Fractal:\n");
	
	for(int i = 1; i <= 4; i++) 
		write_fractal(i, f);

	fclose(f);
}
