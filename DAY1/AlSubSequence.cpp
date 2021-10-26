#include<bits/stdc++.h>
using namespace std;

void PrintAllSubSequence(int arr[],int n){
    sort(arr,arr+n);
    int mx=0,count=0;
    vector<int> a;
    a.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            a.push_back(arr[i]);
        }
    }
    for(int i=0;i<a.size();i++){
          if(i>0 && a[i] == a[i-1]+1){
            count++;
          }else{
              count =1;
          }
          mx = max(mx,count);
    }
    cout<<mx;

}



int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
PrintAllSubSequence(arr,n);
    return 0;
}