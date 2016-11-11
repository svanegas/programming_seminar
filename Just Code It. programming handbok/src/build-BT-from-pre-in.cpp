string pre, in;

string reconstruct(int stpre, int epre, int stin, int ein) {
  if(stpre > epre || stin > ein) return "";
  char currRoot = pre[stpre];
  int pos = 0;
  for(int i = 0; i < in.size(); ++i) {
    if(currRoot == in[i]) {
      pos = i;
      break;
    }
  }
  string left = reconstruct(stpre + 1, stpre + (pos - stin),
                            stin, pos - 1);
  string right = reconstruct(stpre + (pos - stin) + 1, epre,
                             pos + 1, ein);
  return (left + right) + currRoot;
}
