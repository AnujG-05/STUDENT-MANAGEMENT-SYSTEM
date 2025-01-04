#include<iostream>
#include<vector>

using namespace std;

 struct Student{
    int rollNo;
    string name,course;
 };
Student st;
vector<Student>vs;

 int main ()
 {
    Student st1{18,"Anuj","DSA"};
    Student st2{54,"Saurabh","ML"};
    vs.push_back(st1);
    vs.push_back(st2);

    int choice;
    do{
        cout<<"...Select Options..."<<endl;
        cout<<"1.Add New Student: "<<endl;
        cout<<"2.Display All Records: "<<endl;
        cout<<"3.Search Student's Record: "<<endl;
        cout<<"4.Delete Student's Record: "<<endl;
        cout<<"0.Exit"<<endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice == 1)
        {
        system("cls");
        start:
        int newRollno;
        cout<<"Add new Roll no: "; cin>>newRollno;
        // check Roll number entered already existing or not
        bool RollnoExits = false;
        for(int i=0;i<vs.size();i++)
        {
            if(vs[i].rollNo == newRollno)
            {
                RollnoExits = true;
                break;
            }
        }
        if(RollnoExits)
        {
        cout<<"Roll number already exists. Please try again."<<endl;
        goto start;
        }
        
        st.rollNo = newRollno;
        cout<<"Enter Name: "; cin>>st.name;
        cout<<"Course: "; cin>>st.course;

        vs.push_back(st);
        cout<<"------------------New Student Added----------------"<<endl;
        }
        else if(choice == 2)
        {
            system("cls");
            cout<<"...All Records..."<<endl;
            for(int i=0;i<vs.size();i++)
            {
                cout<<"Roll No: "<<vs[i].rollNo<<endl;
                cout<<"Name: "<<vs[i].name<<endl;
                cout<<"Course: "<<vs[i].course<<endl<<endl;
            }
        }
        else if(choice == 3)
        {
            system("cls");
            int Rollno;
            cout<<"Enter Roll No for Search: ";  cin>>Rollno;
            bool found=false;
            for(int i=0;i<vs.size();i++)
            {
                if(Rollno == vs[i].rollNo)
                {
                cout<<"Roll No: "<<vs[i].rollNo<<endl;
                cout<<"Name: "<<vs[i].name<<endl;
                cout<<"Course: "<<vs[i].course<<endl<<endl;
                found = true;
                break;
                }
            }
            if(!found){
            cout<<"Not Found..."<<endl<<endl;
            }
        }
        else if(choice == 4)
        {
            system("cls");
            int Rollno;
            cout<<"Enter Roll No to delete record: ";  cin>>Rollno;
            bool found =false;
            for(int i=0;i<vs.size();i++)
            {
                if(Rollno == vs[i].rollNo)
                {
                    vs.erase(vs.begin() + i);
                    cout<<"--------------------Record Deleted Successfully------------------"<<endl<<endl;
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cout<<"This Roll No is not in our Records..."<<endl<<endl;
            }
        }
        else if(choice == 0)
        {
        system("cls");
        cout<<"Exiting Program..."<<endl<<endl;
        }
        else
        {
        system("cls");
        cout<<"!!Invalid Input!!"<<endl<<endl;
        }
    }
    while(choice!=0);
    return 0;
 }
