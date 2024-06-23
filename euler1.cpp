#include<iostream>
using namespace std;


int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b,(a%b));
}

int euler(int n){
    int temp = 0;
    for (int i = 0; i < n; i++){
        if(gcd(n, i) == 1)
          temp++;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
  int num = 0;
  cout<<"Enter number: ";cin>>num;
  cout<<"The number of prime numbers is: "<<euler(num)<<endl;
  return 0;
}
