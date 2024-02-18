#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key){
     
     int s = 0, e = size - 1, mid = s + (e - s)/2, ans = -1;

     while(s <= e){

        if(arr[mid] == key){
          while(arr[mid - 1] == key){
          mid--;
          }
          ans = mid;
          return ans;
        }

        else if(arr[mid] > key){
          e = mid - 1;
        }

        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
     }
     return ans;
}

int lastOccurence(int arr[], int size, int key){
     
     int s = 0, e = size - 1, mid = s + (e - s)/2, ans = -1;

     while(s <= e){

        if(arr[mid] == key){
          while(arr[mid + 1] == key){
          mid++;
          }
          ans = mid;
          return ans;
        }
        else if(arr[mid] > key){
          e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
     }

     return ans;
}

int main(){
    
    int a[] = {11, 16, 16, 16, 25, 30};
    int firstOccur = firstOccurence(a, 6, 31);
    int lastOccur = lastOccurence(a, 6, 31);
    cout << "First Position is " << firstOccur << endl << "Last Position is " << lastOccur << endl;
    if(firstOccur != -1 && lastOccur != -1){
        cout << "Total Occurences is " << (lastOccur - firstOccur) + 1;
    }
    else{
        cout << "The Number is Not Present";
    }

    return 0;
}