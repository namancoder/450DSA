// merge 2 sorted arrays
#include<bits/stdc++.h>
using namespace std;


int main() {
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9,10};
    int c[10];
    int i,j,k;
        i = j = k = 0;
    while(i < 5 && j < 5) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < 5) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < 5) {
        c[k] = b[j];
        j++;
        k++;
    }
    for(i = 0; i < 10; i++) {
        cout << c[i] << " ";
    }
    return 0;
}