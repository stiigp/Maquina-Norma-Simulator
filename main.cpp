#include <stdio.h>
#include "registrador.h"

void somaSimples(Registrador &A, Registrador &B) {
    // essa funcao soma o conteudo de B em A
    // ao final da execucao, o valor em B sera 0
    // para uma soma que mantem o valor dos registradores, veja funcao abaixo

    while (!teste(B)) { // teste retorna 1 caso o valor de B seja 0
        sub(B);
        add(A);
    }
}

void somaMantendoValores(Registrador &A, Registrador &B) {
    // essa funcao soma o conteudo de B em A
    // ao final da execucao, o valor em B sera mantido
    Registrador C;

    while (!teste(B)) {
        sub(B);
        add(C);
    }

    while (!teste(C)) {
        sub(C);

        add(B);
        add(A);
    }
}

void multiplica(Registrador &A, Registrador &B) {
    // essa funcao multiplica o conteudo dos registradores A e B
    // e armazena seu resultado em A
    // ao final da execucao, o valor de B e mantido
    // e o valor de A e sobrescrito

    Registrador C, D;

    
    while (!teste(A)) {
        sub(A);
        add(C);
    }

    while (!teste(C)) {

        while (!teste(B)) {
            sub(B);
            add(D);
            add(A);
        }

        while (!teste(D)) {
            sub(D);
            add(B);
        }

        sub(C);
    }
}

void aRecebeB(Registrador &A, Registrador &B) {
    Registrador C;

    while (!teste(A)) {
        sub(A);
    }

    while (!teste(B)) {
        sub(B);
        add(C);
    }

    while (!teste(C)) {
        sub(C);
        add(B);
        add(A);
    }
}

int main() {
    Registrador A, B, C;

    for (int i = 0; i < 5; i ++)
        add(A);
    
    for (int i = 0; i < 10; i ++)
        add(B);


    printf("Reg A: %d\nReg B: %d\n", A.valor, B.valor);
    // somaSimples(A, B);
    // somaMantendoValores(A, B);
    // multiplica(A, B);
    aRecebeB(A, B);

    printf("Reg A: %d\nReg B: %d\n", A.valor, B.valor);
}
