#include <iostream>

using namespace std;

int main(){
   
int* database = nullptr; 
    
database = new int[5];
    
 cout << "print the numbers: " << endl;   
   
    for(int i = 0; i < 5; i++){
        
        database[i] = i * 10;
        
         cout << database[i] << endl;
    }
 
 delete[] database;
   
 database = nullptr;

 return 0;     
    
}

