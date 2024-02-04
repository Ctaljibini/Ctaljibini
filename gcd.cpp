  #include <iostream>
  #include<iomanip>
  using namespace std;


  int ebob(int num1, int num2)
  {
    int rmder = 0; //remainder
    int coffct = 0; //coefficient of a variable

    cout << "Enter the numbers: " << num1 << ", " << num2 << endl;
    cout<<"************************************"<<endl;
    do
    {
          rmder = num1 % num2;
          coffct = (num1 - rmder) / num2;
          cout<<setw(6)<<num1<<setw(2)<<" = "<<setw(2)<<coffct<<setw(1)
              <<"."<<setw(2)<<num2<<setw(2)<<" + "<<setw(2)<<rmder<<endl;


          num1 = num2;
          num2 = rmder;
    } while (rmder != 0);

    return num1;
  }

// coefficient of X
  int gcdExtendedX(int a, int b, int *x, int *y){
      if(a == 0){
          *x = 0;
          *y = 1;
          return b;
      }  

      int x1, y1;
      int gcd = gcdExtendedX(b % a, a, &x1, &y1);

      *x = y1 - (b / a) * x1;
      *y = x1;

      return gcd;
  }


// coefficient of X
  int gcdExtendedY(int a, int b, int *x, int *y){
      if(a == 0){
          *y = 0;
          *x = 1;
          return b;
      }  

      int x1, y1;
      int gcd = gcdExtendedY(b % a, a, &y1, &x1);

      *y = y1 - (b / a) * x1;
      *x = x1;

      return gcd;
  }


  int main(int argc, char const *argv[])
  {
    int num1 = 0, num2 = 0;

    cout<<"Enter big number: ";cin>>num1;
    cout<<"enter small number: ";cin>>num2;
    int ebobValue = ebob(num1, num2);

    cout<<"The greatest common divisor (GCD): "<<ebobValue<<endl;

    // Print value X
    int x, y;
    int gcdX = gcdExtendedX(num2, num1, &x, &y);

    if(ebobValue % gcdX != 0){
        cout<<"Denklemin sonucu yok!"<<endl;
        return 1;
    }

    // Print value X
    int mod_inverse = ((x * (ebobValue / gcdX)) % num1 + num1 ) % num1;
    cout<<"x : "<<mod_inverse<<endl;
    
    // Print value Y
    int z, t;
    int gcdY = gcdExtendedY(num2, num1, &z, &y);
    if( ebobValue % gcdY != 0){
        cout<<"Denklemin sonucu yok!"<<endl;
        return 1;
    }
    int mod_inverse_y = ((z *(ebobValue / gcdY)) % num1 + num1) % num1;
    cout<<"y: "<<(mod_inverse_y - num1 )<<endl;

    system("pause");
    return 0;
  }
