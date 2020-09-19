//
//  main.cpp
//  KnapSack
//
//  Created by Sivaprasad Tamatam on 19/09/20.
//

#include <iostream>
using namespace std;

class Item{
public:
    int value, weight;
    
    Item(int v, int w):value(v) , weight(w){
        
    }
};

bool cmp(Item a, Item b){
    double p1 = a.value/a.weight;
    double p2 = b.value/b.weight;
    return p1 > p2;
}
double KnapSack(int W, Item a[], int n){
    sort(a, a+n, cmp);
    int cW = 0;
    double fV = 0.0;
    
    for( int i =0; i<n; i++){
        if(cW + a[i].weight <= W){
            cW += a[i].weight;
            fV += a[i].value;
        } else{
            int remain = W-cW;
            fV += a[i].value * ((double) remain / a[i].weight);
            break;
        }
    }
    return fV;
}
int main(int argc, const char * argv[]) {
    int W = 50;   //    Weight of knapsack
       Item a[] = {{60, 10}, {100, 20}, {120, 30}};
     
       int n = sizeof(a) / sizeof(a[0]);
    cout<<KnapSack(W, a,n);

    return 0;
}
