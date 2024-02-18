#include <iostream>
using namespace std;

long long int findSqrtIntiger(int num){

    int s = 0, e = num;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;

      while(s <= e){
          
          long long int square = mid * mid;

          if(square > num){
            e = mid - 1;
          }
          else if(square == num){
            return mid;
          }
          else{
            ans = mid;
            s = mid + 1;
          }

          mid = s + (e-s)/2;
      }
      


      return ans;
}

double preciseAns(int num, int precision, int tempAns){
       
       double factor = 1, ans;

       for(int i = 0; i < precision; i++){
        factor /= 10;
        for(double j = tempAns; j * j < num; j = j + factor){
             ans = j;
        }
       }
       return ans;
}

int main(){
    
    int num;
    cout << "Enter The Number: ";
    cin >> num;
    int tempAns = findSqrtIntiger(num);
    cout << endl << " The Sqrt of " << num << " is " << preciseAns(num, 3, tempAns) << " and integer  answer is " << tempAns;

    return 0;
}