#include<bits/stdc++.h>
using namespace std ;

// Round Robin Scheduling 

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
    int completed = 0 , time = 0 ;
    queue<int>pq ;
    unordered_map<int,int>mp ;
    while ( completed != n ) {
           int idx = -1 ;
           if ( pq.empty() ) {
               for ( int i = 0 ; i < n ; i ++ ) {
                    if ( mp.find( i ) == mp.end() && bt[i] != -1 ) {
                        pq.push( i ) ;
                        break ;
                    }
               }
           } 
           idx = pq.front() ;
           pq.pop() ;
           mp.erase( idx ) ;
           if ( at[idx] > time ) {
               time = at[idx] ;
           }
           time = time + min( 2 , bt[idx] ) ;
           bt[idx] = bt[idx] - min( 2 , bt[idx] ) ;
           if ( bt[idx] == 0 ) {
               completed ++ ;
               bt[idx] = -1 ;
               ct[idx] = time ;
           } else {
               for ( int i = 0 ; i < n ; i ++ ) {
                   if ( i != idx && mp.find( i ) == mp.end() && bt[i] != -1 && at[i] <= time ) {
                       pq.push( i ) ;
                       mp[i] ++ ;
                   }
               }
               pq.push( idx ) ;
               mp[idx] ++ ;
           }
    }
    cout<<"Completion Time of Processes is : " ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<ct[i]<<" " ;
    }
    return 0 ;
}
