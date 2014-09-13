int
main() {
  bitset<16> set1; //Inicializa todo en 0
  bitset<16> set2(0xFA2); //Inicializa con valor hex
  bitset<16> set3(string("0101101")); //Inicializa a partir 
                                      //del string
  cout << set3.count() << endl; //Imrpime 4
  cout << set3.test(0) << endl; //Imprime true
  cout << set3.test(1) << endl; //Imprime false
  cout << set1.any() << endl; //False porque set1 no tiene
                              //bits en 1
  cout << set1.none() << endl; //True
  //cout << set2.all() << endl; //False, almenos hay
                                //un bit apagado
  cout << set1.set() << endl; //Poner todos en 1
  cout << set1.set(2) << endl; //Poner pos 2 en 1
  cout << set1.reset(1) << endl; //Apaga el pos 1
  cout << set1.flip(2) << endl; //Hacer flip al pos 2
  string s = set1.to_string <char, string::traits_type, 
                             string::allocator_type>();
  cout << s << endl;
  cout << set1.to_ulong() << endl;
  return 0;
}
