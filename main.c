#include <stdio.h>
#include <string.h>
#define TAM 100

void qInicio ( char palavra[TAM],int size);
void q0( int contador, char palavra[TAM],int size);
void q1( int contador, char palavra[TAM],int size);
void q2( int contador, char palavra[TAM],int size);
void q3( int contador, char palavra[TAM],int size);
void q4( int contador, char palavra[TAM],int size);
void q5( int contador, char palavra[TAM],int size);
void q6( int contador, char palavra[TAM],int size);
void q7( int contador, char palavra[TAM],int size);
void q8( int contador, char palavra[TAM],int size);
void q9( int contador, char palavra[TAM],int size);
void qFim();
void qErro();

int main(){
	int size = 0;
    char palavra[TAM]; //casos de comprovação:
    fflush(stdin);
    gets(palavra);

    while(palavra[size] != '\0')
    {
    	size++;
	}

    qInicio(palavra,size);

    return 0;
}

void qInicio ( char palavra[TAM],int size ){
    int contador = 0;
    q0( contador, palavra,size );
}

void q0( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'f' ){
           q1( ++contador, palavra,size );

        }else if (palavra[contador] == 'c'){
           q8( ++contador, palavra ,size);

        }else{
            qErro();
        }

    }
}

void q1( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'l' ){
          q2( ++contador, palavra ,size);

        }else if (palavra[contador] == 'o'){
           q3( ++contador, palavra,size );

        }else{
            qErro();
        }

    }
}

void q2( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'o' ) {
        q5 ( ++contador, palavra,size );

    } else {
        qErro();
    }
}

void q3( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'r' ) {
        q4 ( ++contador, palavra ,size);

    } else {
        qErro();
    }
}

void q4( int contador, char palavra[TAM] ,int size){
	if(contador == size)
	{
		qFim();
	}

    else
    {
    	qErro();
	}

}

void q5( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'a' ) {
        q6 ( ++contador, palavra ,size);

    } else {
        qErro();
    }
}

void q6( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 't' ) {
        q7 ( ++contador, palavra ,size);

    } else {
        qErro();
    }
}

void q7( int contador, char palavra[TAM],int size ){
    if(contador == size)
	{
		qFim();
	}

    else
    {
    	qErro();
	}
}

void q8( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'h' ){
          q9( ++contador, palavra ,size);

        }else{
            qErro();
        }

    }
}

void q9( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'a' ) {
        q3 ( ++contador, palavra ,size);

    } else {
        qErro();
    }
}


void qErro(){
    printf("Palavra regeitada pelo automata!\n");
}

void qFim(){
    printf("Palavra Aceita pelo automata!\n");
}
