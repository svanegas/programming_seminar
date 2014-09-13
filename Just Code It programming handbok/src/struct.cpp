struct dato {
  //x tiene más prioridad que y, (Ver abajo la funcion <)
  int x, y;
  dato (int X, int Y) : x(X), y(Y) {}
  
  //Función que reemplaza el operador < entre dos 'dato'
  //retorna true si this es menor, false de lo contrario.
  bool operator < (const dato &otro) const {
    if (x < otro.x) return true;
    else if (x == otro.x) {
      //Como las x son iguales, entro a preguntar por las y
      if (y < otro.y) return true;
      else return false;
    }
    else { //x > otro.x
       return false;
    }
  }
};

int
main() {
  int x, y;
  vector <dato> v;
  while (cin >> x >> y && x) {
    v.push_back(dato(x, y));
  }
  sort(v.begin(), v.end());
  cout << "Ordenados: " << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].x << " " << v[i].y << endl; 
  }
  return 0;
}