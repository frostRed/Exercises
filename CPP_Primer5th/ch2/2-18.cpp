int main() {
    int i = 0, ii = 1;
    int *pi = nullptr;

    pi = &i;
    pi = &ii;
    *pi = 5;

    return 0;
}
