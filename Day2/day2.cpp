#include<bits/stdc++.h>
using namespace std;
#include "vector"
class Triplets{
public:
    int check_triplets(vector<int> &v,int size){
        if (size<3) return 0;
        for (int i=0; i<=size-3;++i) {
            for (int j=i+1; j<=size-2;++j) {
                for (int k=j+1; k<=size-1;++k) {
                    // cout << v[i] << " " << v[j] << " " << v[k] << endl;
                    if (v[i]+v[j]+v[k]==0) return 1;
                }
            }
        }        
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    Triplets arr;
    // int n=3;
    // vector <int> v={1,2,3};
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    cout << arr.check_triplets(v,n)<<endl;
    return 0;
}