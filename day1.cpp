#include "iostream"
using namespace std;
#include "vector"
class Container{
public:
    int max_area(vector<int> &v,int n){
        int left=0;
        int right=n-1;
        int area=0;

        while(left<right){
            int height = v[left];
            if (height>v[right]) height=v[right];
            int width = right-left;
            int temp_area = width*height;
            if (area<temp_area) area=temp_area;

            if (v[left]<v[right]) left++;
            else right--;
        }
        return area;
    }
};
int main(int argc, char const *argv[])
{
    Container* ptr = new Container;
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    cout << "Max area for {1,8,6,2,5,4,8,3,7}: "<< ptr->max_area(v1,v1.size())<<endl;

    vector<int> v2 = {1,1};
    cout << "Max area for {1,1}: "<< ptr->max_area(v2,v2.size())<<endl;
    return 0;
}