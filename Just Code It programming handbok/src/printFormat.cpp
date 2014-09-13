int
main() {
  //Width 3
  printf("%3d\n", 45);
  //Width 3 leading 0's
  printf("%03d\n", 45);
  //Width 6, after point precision 2
  printf("%6.2f\n", 4.123);
  //Width 6 leading 0's, after point precision 2
  printf("%06.2f\n", 4.123);
  printf("%x\n", 255); //Prints in hexa lowercase
  printf("%X\n", 255); //Prints in hexa uppercase
  printf("%o\n", 16); //Prints in octal
  return 0;
}