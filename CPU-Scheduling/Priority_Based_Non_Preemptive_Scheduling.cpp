#include<bits/stdc++.h>
using namespace std ;

// Priority Based ( Non Preemptive ) Scheduling 

int main() {
    int n ;
    cout<<"Enter the Number of Processes:" ;
    cin>>n ;
    vector<int>at( n ) ; // Enter Element by Sorted Order as per AT
    vector<int>bt( n ) ;
    vector<int>givenPriority(n) ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<"Enter the Arrival Time of Process "<<( i + 1 )<<endl ;
         cin>>at[i] ;
         cout<<"Enter the Burst Time of Process "<<( i + 1 )<<endl ;
         cin>>bt[i] ;
         cout<<"Enter the Priority of Process "<<( i + 1 )<<endl ;
         cin>>givenPriority[i] ;
    }
    vector<int>ct( n ) ;
    priority_queue<pair<int,int>>pq ;
    int completed = 0 , time = 0 ;
    unordered_map<int,int>mp ;
    while ( completed != n ) {
           int idx = -1 ;
           if ( !pq.empty() ) {
               idx = pq.top().second ;
               pq.pop() ;
           } else {
            for ( int i = 0 ; i < n ; i ++ ) {
                 if ( bt[i] != -1 ) {
                     idx = i ;
                     break ;
                 }
            }
           }
           mp[idx] ++ ;
           if ( at[idx] > time ) {
              time = at[idx] ;
           }
           time = time + bt[idx] ;
           ct[idx] = time ;
           bt[idx] = -1 ;
           completed ++ ;
           for ( int i = 0 ; i < n ; i ++ ) {
                if ( mp.find( i ) == mp.end() && bt[i] != -1 && at[i] <= time ) {
                    pq.push( { givenPriority[i] , i } ) ;
                    mp[i] ++ ;
                }
           }
    }
    cout<<"Completion Time of given Processes is : " ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<ct[i]<<" " ;
    }
    return 0 ;
}
