#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const int MAXN = 1005;
char s[MAXN];
string cs;

int
main() {
  while (true) {
    scanf("%s", s); //Only a token stored in char array
    cout << "scanf: |" << s << "|" << endl;
    gets(s); //Until end of line or EOF stored in char array
    cout << "gets: |" << s << "|" << endl;
    getline(cin, cs); //Until end of line or EOF stored in string
    cout << "getline: |" << cs << "|" << endl;
    // ---------------------------------------
    for (int i = 0; i < strlen(s); i++) cout << s[i] << " - ";
    cout << endl;
    char dest[MAXN];
    strncpy(dest, s, 5); //Dest, source, length (size_t)
    dest[5] = '\0'; //ALWAYS ADD NULL CHARACTER AT END POSITION
    cout << "cpyDest: |" << dest << "|" << endl;
    strncat(dest, s, 3); //Dest, source, length (size_t)
    cout << "catDest: |" << dest << "|" << endl;
    dest[4] = '\0'; //Cut string, result length 5
    if (strncmp(s, dest, 5) == 0) cout << "equals 5" << endl;
    if (strncmp(s, dest, 4) == 0) cout << "equals 4" << endl;
  }
  return 0;
}
