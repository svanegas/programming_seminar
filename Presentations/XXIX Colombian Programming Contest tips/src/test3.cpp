int
main() {
  int a, b;
  while (scanf("%d:;%d", &a, &b) != EOF) // EOF!
    printf("%05d - %05d\n", a, b);
  return 0;
}

