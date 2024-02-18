#include <iostream>
using namespace std;

#define N 4

bool isPossibleSolution(int a[], int students, int mid){
     
     int studentCount = 1;
     int pageSum = 0;

     for(int i = 0; i < N; i++){
         
         if(pageSum + a[i] <= mid){
            pageSum+=a[i];
         }
         else{
            studentCount++;
            if(studentCount > students || a[i] > mid){
                return false;
            }
            pageSum = a[i];
         }
     }

     return true;
}

int bookAllocate(int a[], int students){
    
    int sum = 0;
    for(int i = 0; i < N; i++){
       sum+=a[i];
    }
    

    int s = 0, e = sum, mid = s + (e - s)/2, result = -1;

    while(s <= e){

        if(isPossibleSolution(a, students, mid)){
           result = mid;
           e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }

    return result;
}

int main(){
    
    int a[N], students;
    
    cout << "Enter The Number Of Students: ";
    cin >> students;
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << bookAllocate(a, students);
    
    return 0;
}