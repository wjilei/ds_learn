#include <iostream>
#include <vector>

using namespace std;


string revStr(string& str) {
  string strCopy = str;
  int lenStr = str.length();
  for(int i = 0; i < lenStr/2; i ++) {
    char tmp = strCopy[i];
    strCopy[i] = strCopy[lenStr-i-1];
    strCopy[lenStr-i-1] = tmp;
  }

  return strCopy;
}

int main() {
  string a = "HelloWorld";
  string arev = revStr(a);
  cout << arev << endl;
  return 0;
}
