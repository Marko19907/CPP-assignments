
int main() {
    int a = 5;
    int &b = a;
    int *c;
    c = &b;
    a = b + *c;
    b = 2;

    // can be complied now

    return 0;
}
