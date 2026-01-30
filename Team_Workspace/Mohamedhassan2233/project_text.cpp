#include <bits/stdc++.h>
using namespace std;



int main() {
  int n;
  cin>>n;
   int sum=0;
    int t=1;
    int i=1 ;
    while (t>=0){

        sum +=i;
        t=n-sum;
        i++;
    }
cout << i-1;

  return 0;
}
