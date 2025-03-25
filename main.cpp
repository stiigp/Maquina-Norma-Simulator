#include <stdio.h>
#include "registrador.h"

void somaSimples(Registrador &A, Registrador &B) {
    // essa funcao soma o conteudo de B em A
    // ao final da execucao, o valor em B sera 0
    // e a funcao considera o sinal do numero, ao contrario das outras
    // para uma soma que mantem o valor dos registradores, veja funcao abaixo

        
    if (A.sinal) {
        // a eh negativo
        if (B.sinal) {
            // ambos negativos -> simplesmente faz a soma
            while (!teste(B)) {
                sub(B);
                add(A);
            }
        } else {
            // a eh negativo mas b eh positivo
            while (!teste(B)) {
                if (A.sinal) {
                    sub(B);
                    sub(A);
                } else {
                    sub(B);
                    add(A);
                }
                if (teste(A))
                    A.sinal = 0;
            }
        }
    } else {
        // a eh positivo
        if (!B.sinal) {
            // ambos positivos, simplesmente faz a soma
            while (!teste(B)) {
                sub(B);
                add(A);
            }
        } else {
            // a positivo e B negativo
            while (!teste(B)) {
                if (A.sinal) {
                    sub(B);
                    add(A);
                } else {
                    sub(B);
                    sub(A);
                }
                if (teste(A))
                    A.sinal = 1;
            }
        }
    }
    B.sinal = 0;
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
    A.sinal = 0;
    
    for (int i = 0; i < 10; i ++)
        add(B);
    B.sinal = 0;

    
    somaSimples(A, B);
    // somaMantendoValores(A, B);
    // multiplica(A, B);

    printf("A: "); exibeResultadoRegistrador(A);
    printf("B: "); exibeResultadoRegistrador(B);
    
}
