/*Implement matrix class as ADT. Write a program to perform matrix addition, subtraction, and
multiplication. In read matrix function, raise an exception if any attempt is made to have rows and columns
beyond the array size. Raise an exception if any attempt is made to perform matrix operations on matrices
which does not satisfy the matrix order criteria. Implement using C++.*/
#include<iostream>
using namespace std;
class ADT{
    public:
    int i,j,row1,row2,col1,col2;
    int mat1[4][4],mat2[4][4],col1[4][4],col2[4][4],add[4][4],sub[4][4],mul[4][4];
    void get_data()
    {
        try{
        cout << "Enter Row For mat 1" << endl;
        cin>>row1;
        cout <<"Enter Column for mat 1" << endl;
        cin>>col1;
        cout <<"Enter Row For mat 2 " << endl;
        cin>>row2;
        cout << "Enter Column For mat 2" << endl;
        cin>>col2;
        
        if(row1>4||col1>4||row2>4||col2>4)
        {
            throw 1;
        } 
        

        cout << "Enter ,matrix 1" << endl;
        for(i=0;i<row1;i++){
            for(j=0;j<col1;j++)
            {
                cout << "mat1[" << i << "][" << j << "] : ";
                cin >> mat1[i][j];
                cout << endl;
            }
        }
        cout << "Enter Matrix 2 " << endl;
        for(i=0;i<row2;i++){
            for(j=0;j<col2;j++){
                cout << "mat2["<< i << "][" << j << "] :";
                cin >> mat2[i][j];
                cout << endl;
            }
        }
        }catch (int f) {
cout << "ERROR!!.\n";
return;

    }
    }
    void display()
    {
        cout<<"Matrix 1 is "<<endl;
        for(i=0;i<row1;i++){
            for(j=0;j<col1;j++){
                cout << mat1[i][j] << endl;
            }
        }
        cout << endl;
        cout << "Matrix 2 is " << endl;
        for(i=0;i<row2;i++){
            for(j=0;j<col2;j++){
                cout << mat2[i][j] << endl;
            
        }
        }
        cout << endl;
    }
    void add()
    {
        try{
            if(row1!=row2 && col1!=col2)
            {
                throw 5;
            }
            for(i=0;i<row2;i++){
                for(j=0;j<col2;j++){
                    add[i][j]=mat1[i][j]+mat2[i][j];
                    cout <<"Addition of matrix is : " << endl << add[i][j] << endl;

                }
            }
            cout << endl;
        }catch(int h){
            cout << "Exception occured R!!!" << endl;
            return ;
        }
    }

    void sub()
    {
        try{
             if(row1!=row2 && col1!=col2)
            {
                throw 5;
            }
            for(i=0;i<row2;i++){
                for(j=0;j<col2;j++){
                    sub[i][j]=mat1[i][j]-mat2[i][j];
                    cout << "Substraction of Matrix Are : " << endl << sub[i][j] << endl;
                }
            }
            cout << endl;
        }catch(int t){
            cout <<"Exception!!!!!!!"<<endl;
            return ;
        }

    }

};
int main()
{
    
            ADT p;

    cout << "Enter Detalisd" << endl;
    p.get_data();
    int n,l;
    cout << "Enter operation to perform(1/0)" << endl;
    cin>>n;
    while(n==1){
        ADT d;
        cout << "Enter choice " << endl;
        cout << "1.Additipon" << endl;
        cout << "2.Substraction" << endl;
        cout << "3.Multiply" << endl;
        cin>>l;
        switch(l)
        {
            case 1:
                d.add();
                break;
            case 2:
                d.sub();
                break;
        }
        return 0;

    }

}