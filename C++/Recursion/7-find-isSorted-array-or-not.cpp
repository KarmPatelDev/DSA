#include <iostream>
using namespace std;



int isSorted(int a[], int size){

    if(size == 0 || size == 1){
        return true;
    }

    if(a[size - 2] > a[size - 1]){
         return false;
    }
    else{
        bool remainingPart = isSorted(a, size - 1);
        return remainingPart;
    }

}


int main(){
    int size = 5;
    int a[size];

    cout << "Enter The Elements: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }

    if(isSorted(a, size)){
        cout << "The Array is Sorted";
    }
    else{
        cout << "The Array is not Sorted";
    }
    return 0;
}