#include <iostream>

#include <cmath>

using namespace std;

int main() {

    char o;

    double x, y;

    

    cin>>x>>o>>y;

    

    switch(o){

    

    case '+':

    cout<<x<<" + "<<y<<" = "<<x+y;

    break;

    

    case '-':

    cout<<x<<" - "<<y<<" = "<<x-y;

    break;

    

    case '/':

    if(y==0){

       cout<<"Cannot divide by 0!";

    }

    else{

       cout<<x<<"/"<<y<<" = "<<x/y;

    }

    break;

    

    case '*':

    cout<<x<<" * "<<y<<" = "<<x*y;

    break;

    

    case '%':

    cout<<int(x)<<" % "<<int(y)<<" = "<<int(x) % int(y);

    break;

    case'^':

    cout<<x<<" ^ "<<y<<" = "<<pow(x,y);

    break;

    

    default:

    cout<<"Please enter a valid operation. Valid operations are +,-,*,/,%, and ^"<<endl;

    break;

    }

    

    

    return 0;

}
