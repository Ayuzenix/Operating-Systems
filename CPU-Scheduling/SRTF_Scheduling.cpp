#include<bits/stdc++.h>
using namespace std ;

// SRTF Scheduling 

int main() {

    int n ;
    cout<<"Enter the Number of Processes:" ;
    cin>>n ;
    vector<int>at( n ) ;
    vector<int>bt( n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<"Enter the Arrival Time of Process "<<( i + 1 )<<endl ;
         cin>>at[i] ;
         cout<<"Enter the Burst Time of Process "<<( i + 1 )<<endl ;
         cin>>bt[i] ;
    }
    vector<int>ct( n ) ;
    vector<int>btd = bt ;
    int time = 0 , completed = 0 ;
    while ( completed < n ) {
           int curr = 0 ;
           vector<int>store ;
           while ( curr < n  ) {
                 if ( curr < n && bt[curr] != -1 && at[curr] <= time ) {
                 store.push_back( curr ) ;
                 }
                 curr ++ ;
           }
           int mini = INT_MAX , miniIdx = -1 ;
           for ( int i = 0 ; i < store.size() ; i ++ ) {
                if ( bt[store[i]] < mini ) {
                     mini = bt[store[i]] ;
                     miniIdx = store[i] ;
                }
           }
           if ( miniIdx == -1 ) {
               int mini1 = INT_MAX ;
               for ( int i = 0 ; i < n ; i ++ ) {
                   if ( at[i] > time ) {
                       mini1 = min( mini1 , at[i] ) ;
                   }
               }
               time = mini1 ;
           } else {
             bt[miniIdx] -- ;
             time ++ ;
             if ( bt[miniIdx] == 0 ) {
                 ct[miniIdx] = time ;
                 bt[miniIdx] = -1 ;
                 completed ++ ;
             }
           }
    }
    cout<<"Completion Time of Processes is:" ;
    for ( int i = 0 ; i < n ; i ++ ) {
         int ctime = ct[i] , tatime = ct[i] - at[i] , wtime = tatime - btd[i] ;
         cout<<ctime<<" "<<tatime<<" "<<wtime<<endl ;
    }
    return 0 ;
}
