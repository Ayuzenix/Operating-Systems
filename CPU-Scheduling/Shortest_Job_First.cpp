#include<bits/stdc++.h>
using namespace std ;

// Shortest Job First ( sjf ) 

int main() {
    
    int n ;
    cout<<"Enter Number of Processes"<<endl ;
    cin>>n ;
    vector<int>at( n ) ;
    vector<int>bt( n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<"Enter the Arrival Time of Process"<<( i + 1 )<<endl ;
         cin>>at[i] ;
         cout<<"Enter the Burst Time of Process"<<( i + 1 )<<endl ;
         cin>>bt[i] ;
    }
    int time = 0 , count = 0 ;
    vector<int>ct( n ) ;
    while ( count < n ) {
         vector<int>store ;
         int curr = 0 ;
         while ( curr < n  ) {
             if ( curr < n && bt[curr] != -1 && at[curr] <= time ) {
                 store.push_back( curr ) ;
             }
             curr ++ ;
         }
         int mini = INT_MAX , miniIdx = -1 ;
         for ( int i = 0 ; i < store.size() ; i ++ ) {
              if ( bt[store[i]] < mini ) {
                  miniIdx = store[i] ;
                  mini = bt[store[i]] ;
              }
         }
         if ( miniIdx == -1 ) {
             int mini1 = INT_MAX , maxiIdx = -1 ;
             for ( int i = 0 ; i < n ; i ++ )  {
                 if ( at[i] > time ) {
                      mini1 = min( mini1 , at[i] ) ;
                 }
             }
             time = mini1 ;
         } else {
            time = time + bt[miniIdx] ;
            ct[miniIdx] = time ;
            bt[miniIdx] = -1 ;
            count ++ ;
         }
    }
    cout<<"Completion Time of Processes is: ";
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<ct[i]<<" " ;
    }

    return 0 ;
}
