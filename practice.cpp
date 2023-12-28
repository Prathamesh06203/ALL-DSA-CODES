#include<iostream>
#include<set>
#include<iterator>
using namespace std;
void show(set<int>s)
{
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout << " \t" <<*it<<endl;
    }
    cout << "\n";
}
int main()
{
    set<int>ss;
    ss.insert(20);
    ss.insert(63);
    ss.insert(41);
    ss.insert(74);
    ss.insert(87);
    show(ss);
    ss.max_size();
    
    return 0;

}