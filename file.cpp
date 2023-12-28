#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> a;
    stack<int> b;
    stack<int> sum;
    int a1,b1;
    cout << "Enter The Number of bits In A" << endl;
    cin >> a1;
    cout << "Enter The Number Of bits In B" << endl;
    cin >> b1;
    for(int i=0;i<a1;i++){
        int bit;
        cin>>bit;
        a.push(bit); 
    }
    for(int i=0;i<b1;i++){
        int bit;
        cin>>bit;
        b.push(bit);
    }
    int carry =1;
    while(!a.empty() || !b.empty())
    {
        int aa=a.top();
        a.pop();
        int bb =b.top();
        b.pop();
        int result=aa+bb+carry;
        if(result==1||result==0)
        {
            sum.push(result);
            carry=0;

        }
        else if(result==2)
        {
            sum.push(0);
            carry =1;

        }
        else if(result==3)
        {
            sum.push(1);
            carry =1;
        }

    }
    cout << "Addittion " << endl;
    cout << carry << endl;
    while(!sum.empty()){
        cout << sum.top() << endl;
        sum.pop();
    }
    cout << endl;
}
