#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

bool asal_mi(int x){
  if( x <= 1)
    return false;
  for (int i = 2; i*i <= x; i++)
  {
    if(x % i == 0)
      return false;
  }
    return true;
}

vector<int> listele(int taban){
  vector<int> dizi;
  for (int i = 0; i <= taban; i++){
      if(asal_mi(i))
        dizi.push_back(i);
  }
 return dizi; 
}

vector<int> bolenler(int x){
  vector<int> asallar = listele(x);
  vector<int> bolenler;
  int temp = 0;
 
  for (int elema : asallar){
      if( x % elema == 0 ){
        temp = x;
        while (temp % elema == 0)
        {
          temp = temp / elema;
          bolenler.push_back(elema);
        }      
      }  
  }
  return bolenler;  
}

int euler(int x){
  vector<int> bolenlerDizisi = bolenler(x);
  int size = bolenlerDizisi.size();
  unordered_map<int, int> sayac;
  for (int num : bolenlerDizisi)
  {
    sayac[num]++;
  }
  int euler = 1;
  int temp = 1;
  for (const auto& pair : sayac){
    temp = pow(pair.first, pair.second) - pow(pair.first, pair.second-1); // p^q - p^(p-1). NOT: p asal sayi!
    euler = temp * euler;

  }
  return euler; 
}

int main(int argc, char const *argv[])
{
  int x = 0;
  cout<<"sayi gir: ";cin>>x;
  cout<<"euler: "<<euler(x);
  return 0;
}
