#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
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
                //gotoxy(15, 15);
                printf("A: ");
                exibeResultadoRegistrador(A);
                
                printf("B: ");
                exibeResultadoRegistrador(B);
                Sleep(1000);
                printf("\n");
                sub(B);
                add(A);
            }
        } else {
            // a eh negativo mas b eh positivo
            while (!teste(B)) {
                //gotoxy(25, 50);
                printf("A: ");
                exibeResultadoRegistrador(A);
                printf("B: ");
                exibeResultadoRegistrador(B);
                Sleep(1000);
                printf("\n");
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
                //gotoxy(25, 50);
                printf("A: ");
                exibeResultadoRegistrador(A);
                printf("B: ");
                exibeResultadoRegistrador(B);
                Sleep(1000);
                printf("\n");
                sub(B);
                add(A);
            }
        } else {
            // a positivo e B negativo
            while (!teste(B)) {
                //gotoxy(25, 50);
                printf("A: ");
                exibeResultadoRegistrador(A);
                printf("B: ");
                exibeResultadoRegistrador(B);
                Sleep(1000);
                printf("\n");
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
    if (teste(A)) {
        A.sinal = 0;
    }

    B.sinal = 0;
    //gotoxy(25, 50);
    printf("A: ");
    exibeResultadoRegistrador(A);
    printf("B: ");
    exibeResultadoRegistrador(B);
    Sleep(1000);
    printf("\n");
}

void somaMantendoValores(Registrador &A, Registrador &B) {
    // essa funcao soma o conteudo de B em A
    // ao final da execucao, o valor em B sera mantido
    Registrador C;

    while (!teste(B)) {
        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        Sleep(1000);
        printf("\n");
        sub(B);
        add(C);
    }

    while (!teste(C)) {

        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        Sleep(1000);
        printf("\n");

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
        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        printf("D: ");
        exibeResultadoRegistrador(D);
        Sleep(1000);
        printf("\n");
        sub(A);
        add(C);
    }

    while (!teste(C)) {

        while (!teste(B)) {
            //gotoxy(25, 50);
            printf("A: ");
            exibeResultadoRegistrador(A);
            printf("B: ");
            exibeResultadoRegistrador(B);
            printf("C: ");
            exibeResultadoRegistrador(C);
            printf("D: ");
            exibeResultadoRegistrador(D);
            Sleep(1000);
            printf("\n");
            sub(B);
            add(D);
            add(A);
        }

        while (!teste(D)) {
            //gotoxy(25, 50);
            printf("A: ");
            exibeResultadoRegistrador(A);
            printf("B: ");
            exibeResultadoRegistrador(B);
            printf("C: ");
            exibeResultadoRegistrador(C);
            printf("D: ");
            exibeResultadoRegistrador(D);
            Sleep(1000);
            printf("\n");
            sub(D);
            add(B);
        }

        sub(C);
    }
}

void aRecebeB(Registrador &A, Registrador &B) {
    Registrador C;

    while (!teste(A)) {
        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        Sleep(1000);
        printf("\n");
        sub(A);
    }

    while (!teste(B)) {
        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        Sleep(1000);
        printf("\n");
        sub(B);
        add(C);
    }

    while (!teste(C)) {
        //gotoxy(25, 50);
        printf("A: ");
        exibeResultadoRegistrador(A);
        printf("B: ");
        exibeResultadoRegistrador(B);
        printf("C: ");
        exibeResultadoRegistrador(C);
        Sleep(1000);
        printf("\n");
        sub(C);
        add(B);
        add(A);
    }
}

void pegaValores(Registrador &A, Registrador &B) {
    int aux;

    printf("Digite o valor do registrador A: ");

    scanf("%d", &aux);
    if (aux < 0) {
        A.valor = aux * -1;
        A.sinal = 1;
    } else {
        A.valor = aux;
        A.sinal = 0;
    }

    printf("Digite o valor do registrador B: ");

    scanf("%d", &aux);
    if (aux < 0) {
        B.valor = aux * -1;
        B.sinal = 1;
    } else {
        B.valor = aux;
        B.sinal = 0;
    }
}

void exibeMenu () {
	char c;
	system("cls");

        // Exibe o conteÃºdo do arquivo (se existir)
        FILE *arquivo = fopen("gatito.txt", "r");
        if (arquivo) {
            while ((c = fgetc(arquivo)) != EOF) {
                putchar(c);
            }
            fclose(arquivo);
        } 
}

void resultado(Registrador &A, Registrador &B) {
	//clrscr();
	//exibeMenu();
	printf("\nA: ");
    exibeResultadoRegistrador(A);
    printf("\nB: ");
    exibeResultadoRegistrador(B);
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}


int main() {
    Registrador A, B;
	

	char tecla;
	exibeMenu();
	do {
	
	while(!kbhit());
	tecla= getch();
	switch (tecla) {
                case 'a':
                	pegaValores(A, B);
                    somaSimples(A, B);
                    resultado(A,B);
                    system("cls");
                    exibeMenu();
                    break;
                case 'b':
                	pegaValores(A, B);
                    somaMantendoValores(A, B);
                    resultado(A,B);
                    system("cls");
                    exibeMenu();
                    break;
                case 'c':
                	pegaValores(A, B);
                    multiplica(A, B);
                    resultado(A,B);
                    system("cls");
                    exibeMenu();
                    break;
                case 'd':
                	pegaValores(A, B);
                    aRecebeB(A, B);
                    resultado(A,B);
                    system("cls");
                    exibeMenu();
                    break;
                default:
                    printf("\nOpcao invalida!\n");
                    break;
            }
	} while (tecla!=27);
        

    return 0;
}
