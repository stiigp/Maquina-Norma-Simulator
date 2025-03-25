struct Registrador {
    int valor = 0;
    int sinal = 0;
};

void add(Registrador &reg) {
    reg.valor = reg.valor + 1;
}

void sub(Registrador &reg) {
    reg.valor = reg.valor - 1;
}

int teste(Registrador &reg) {
    return (reg.valor == 0);
}

void exibeResultadoRegistrador(Registrador &reg) {
    if (reg.sinal)
        printf("Valor: -%d\n", reg.valor);
    else
        printf("Valor: %d\n", reg.valor);
}
