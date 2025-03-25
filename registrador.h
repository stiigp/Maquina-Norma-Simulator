struct Registrador {
    int valor = 0;
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
