#include<iostream>
#include<iomanip>
#include<fstream>
#include <sstream> 
#include<cctype>
using namespace std;
int n_of_sts=0;

struct student_info{
    int id;
    string name;
    int age;
    int marks[5];
    int total;
    float perc;
    string grade;
}student[100];

void menu(){
    cout<<setfill('=')<<setw(60)<<"";
    cout<<"\n\t\tSTUDENT MANAGEMENT SYSTEM\n";
    cout<<setfill('=')<<setw(62)<<" \n";
    cout<<"1. DATA ENTRY MODULE\n";
    cout<<"2. VIEW ALL STUDENTS\n";
    cout<<"3. SEARCH STUDENTS\n";
    cout<<"4. SORT STUDENTS\n";
    cout<<"5. UPDATE STUDENT RECORD\n";
    cout<<"6. DELETE STUDENT RECORD\n";
    cout<<"0. EXIT\n";
    cout<<setfill('=')<<setw(60)<<"";
}

void load(){
    ifstream open("data.txt");
    open.clear();
    open.seekg(0);
    string value;
    int a=0;
    n_of_sts=0;
    
    while(getline(open,value)){
        if(value.find("Id : ")!=string::npos){
            string word=value.substr(5);
            student[a].id=stoi(word);
        }else if(value.find("Name : ")!=string::npos){
            string word=value.substr(7);
            student[a].name=word;
        }else if(value.find("Age : ")!=string::npos){
            string word=value.substr(6);
            student[a].age=stoi(word);
        }else if(value.find("Marks : ") != string::npos){
    		string word = value.substr(8);
    		stringstream ss(word);
    			for(int k=0; k<5; k++){
       		 		ss >> student[a].marks[k];
    			}
		}else if(value.find("Total : ") != string::npos){
    			string word = value.substr(8);
    			student[a].total = stoi(word);
		}else if(value.find("Percentage : ")!=string::npos){
            string word=value.substr(13);
            student[a].perc=stof(word);
        }else if(value.find("Grade : ")!=string::npos){
            string word=value.substr(8);
            student[a].grade=word;
            a++;
        }
    }
    n_of_sts=a;
    open.close();
}

void save(){
    ofstream file("data.txt");
    for(int i=0;i<n_of_sts;i++){
        file<<"Id : "<<student[i].id<<endl;
        file<<"Name : "<<student[i].name<<endl;
        file<<"Age : "<<student[i].age<<endl;
        file<<"Marks : ";
        for(int j=0;j<5;j++){
            file<<student[i].marks[j]<<" ";
        }
        file<<"\nTotal : "<<student[i].total<<endl;
        file<<"Percentage : "<<student[i].perc<<endl;
        file<<"Grade : "<<student[i].grade<<endl;
        file<<endl;
    }
    file.close();
}

bool check_duplicate(int id){
	for(int i=0; i<n_of_sts; i++){
        if(student[i].id == id){
            return true;
        }
    }
    return false;
}

void input(){
	cout<<"\nADD NEW STUDENTS RECORD\n";
   	int number;
    bool isbool;
    cout<<"\nEnter the Number of Students you want to Add : ";
    cin>>number;
    for(int a=n_of_sts; a<n_of_sts+number;a++){
        cout<<"\nStudent Details:\n";
        cout<<"-Id : ";
        cin>>student[a].id;
        cout<<"-Name : ";
        cin.ignore();
        getline(cin,student[a].name);
        cout<<"-Age : ";
        cin>>student[a].age;
        cout<<"-Marks(5 Subjects):\n";
        student[a].total=0;
        for(int i=0;i<5;i++){
            cout<<" Subject"<<i+1<<" : ";
            cin>>student[a].marks[i];
            student[a].total+=student[a].marks[i];
        }
        student[a].perc=(student[a].total*100)/500.0;
        if(student[a].perc>=85){
            student[a].grade="A";
        }else if(student[a].perc>=70){
            student[a].grade="B";
        }else if(student[a].perc>=50){
            student[a].grade="C";
        }else{
            student[a].grade="F";
        }
    }
    
    n_of_sts+=number;
    save();
    	cout<<"\nCalculating Percentage and Grades.........\n";
  		cout<<"Records Added Successfully\n\n";
}

void display(){
    load();
    if(n_of_sts>0){
        cout<<"\n\n--------------------ALL STUDENTS RECORDS--------------------"<<endl;
        cout<<setfill(' ')<<setw(5)<<"ID"
           <<setw(20)<<"Name"
           <<setw(10)<<"Age"
           <<setw(15)<<"Percentage"
           <<setw(8)<<"Grade"<<endl;
        cout<<setfill('-')<<setw(60)<<""<<"\n";
        for(int a=0;a<n_of_sts;a++){
            cout<<setfill(' ')<<setw(5)<<student[a].id
               <<setw(20)<<student[a].name
               <<setw(10)<<student[a].age
               <<setw(15)<<student[a].perc
               <<setw(8)<<student[a].grade<<endl;
        }
        cout<<setfill('-')<<setw(60)<<""<<"\n\n";
    }else{
        cout<<"\nNo Student Record, Choose 1 to Add the Students\n\n";
    }
}

string convert_to_lower(string value){
	for(int a=0 ; a<value.length() ; a++){
		if((int(value[a])>=65 && int(value[a])<=90)){
			value[a] = int(value[a]) + 32;
		}
	}
	return value;
}

string convert_to_upper(string value){
	for(int a=0 ; a<value.length() ; a++){
		if(int(value[a])>=97 && int(value[a])<=122){
			value[a] = int(value[a]) - 32;
		}
	}
	return value;
}

void search(){
    load();
    if(n_of_sts==0){
        cout<<"\nNo Student Records Found!\n\n";
        return;
    }
    
    int choice;
    cout<<"\n1.Search by Id\n";
    cout<<"2.Search by Name\n";
    cout<<"3.Search by Grade\n";
    cout<<"4.Return to Main Menu\n";
    cout<<"Enter choice(1-4) : ";
    cin>>choice;
    
    if(choice<1||choice>4){
        cout<<"\nInvalid Number\n";
        return;
    }
    
    if(choice==1){
        int id;
        bool found=false;
        cout<<"Enter the Id : ";
        cin>>id;
        for(int a=0;a<n_of_sts;a++){
            if(id==student[a].id){
                if(found == false){
                    cout<<setfill('-')<<setw(60)<<""<<"\n";
                    cout<<setfill(' ')<<setw(5)<<"ID"
                       <<setw(20)<<"Name"
                       <<setw(10)<<"Age"
                       <<setw(15)<<"Percentage"
                       <<setw(8)<<"Grade"<<endl;
                    cout<<setfill('-')<<setw(60)<<""<<"\n";
                    found=true;
                }
                cout<<setfill(' ')<<setw(5)<<student[a].id
                   <<setw(20)<<student[a].name
                   <<setw(10)<<student[a].age
                   <<setw(15)<<student[a].perc
                   <<setw(8)<<student[a].grade<<"\n\n";
            }
        }
        if(!found){
            cout<<"\nNo Student exists with ID : "<<id<<"\n";
        }
    }else if(choice==2){
        string name;
        bool found=false;
        cout<<"Enter Name : ";
        cin.ignore();
        getline(cin,name);
        cout<<endl;
        for(int a=0;a<n_of_sts;a++){
            if(convert_to_lower(student[a].name).find(convert_to_lower(name))!=string::npos){
                if(found == false){
                    cout<<setfill('-')<<setw(60)<<""<<endl;
                    cout<<setfill(' ')<<setw(5)<<"ID"
                       <<setw(20)<<"Name"
                       <<setw(10)<<"Age"
                       <<setw(15)<<"Percentage"
                       <<setw(8)<<"Grade"<<endl;
                    cout<<setfill('-')<<setw(60)<<""<<endl;
                    found=true;
                }
                cout<<setfill(' ')<<setw(5)<<student[a].id
                   <<setw(20)<<student[a].name
                   <<setw(10)<<student[a].age
                   <<setw(15)<<student[a].perc
                   <<setw(8)<<student[a].grade<<"\n";
            }
        }
        if(!found){
            cout<<"\nNo Student exists with name : "<<name<<"\n\n";
        }
    }else if(choice==3){
        string grade;
        bool found=false;
        cout<<"Enter Grade(A/B/C/F) : ";
        cin.ignore();
        getline(cin , grade);
        cout<<endl;
        for(int a=0;a<n_of_sts;a++){
            if(convert_to_lower(grade)==convert_to_lower(student[a].grade)){
                if(found == false){
                    cout<<setfill('-')<<setw(60)<<""<<endl;
                    cout<<setfill(' ')<<setw(5)<<"ID"
                       <<setw(20)<<"Name"
                       <<setw(10)<<"Age"
                       <<setw(15)<<"Percentage"
                       <<setw(8)<<"Grade"<<endl;
                    cout<<setfill('-')<<setw(60)<<""<<endl;
                    found=true;
                }
                cout<<setfill(' ')<<setw(5)<<student[a].id
                   <<setw(20)<<student[a].name
                   <<setw(10)<<student[a].age
                   <<setw(15)<<student[a].perc
                   <<setw(8)<<student[a].grade<<"\n";
            }
        }
        if(!found){
            cout<<"No Students exists with Grade : "<<grade<<"\n\n";
        }
    }else if(choice==4){
        return;
    }
}

void display_after_sorting(){
    cout<<setfill(' ')<<setw(5)<<"ID"
       <<setw(20)<<"Name"
       <<setw(10)<<"Age"
       <<setw(15)<<"Percentage"
       <<setw(8)<<"Grade"<<endl;
    cout<<setfill('-')<<setw(60)<<""<<endl;
    
    for(int a=0;a<n_of_sts;a++){
        cout<<setfill(' ')<<setw(5)<<student[a].id
           <<setw(20)<<student[a].name
           <<setw(10)<<student[a].age
           <<setw(15)<<student[a].perc
           <<setw(8)<<student[a].grade<<endl;
    }
    cout<<endl;
}

void sort(){
    load();
    if(n_of_sts==0){
        cout<<"\nNo Student Records Found!\n\n";
        return;
    }
    
    int choice;
    cout<<"\n1.Sort by Name(A-->Z)\n";
    cout<<"2.Sort by Percentage(High-->Low)\n";
    cout<<"3.Sort by Age(Low-->High)\n";
    cout<<"4.Return to Main Menu\n";
    cout<<"Enter choice(1-4) : ";
    cin>>choice;
    
    if(choice==1){
        for(int a=0;a<n_of_sts-1;a++){
            for(int b=0;b<n_of_sts-1;b++){
                if(convert_to_upper(student[b].name)>convert_to_upper(student[b+1].name)){
                    swap(student[b+1],student[b]);
                }
            }
        }
        cout<<"Records have been Sorted by Name Successfully\n";
        display_after_sorting();
    }else if(choice==2){
        for(int a=0;a<n_of_sts-1;a++){
            for(int b=0;b<n_of_sts-1;b++){
                if(student[b].perc<student[b+1].perc){
                    swap(student[b],student[b+1]);
                }
            }
        }
        cout<<"Records have been Sorted by Percentage Successfully\n";
        display_after_sorting();
    }else if(choice==3){
        for(int a=0;a<n_of_sts-1;a++){
            for(int b=0;b<n_of_sts-1;b++){
                if(student[b].age>student[b+1].age){
                    swap(student[b],student[b+1]);
                }
            }
        }
        cout<<"Records have been Sorted by Age Successfully\n";
        display_after_sorting();
    }else if(choice==4){
        return;
    }else{
        cout<<"Invalid Number, Try Again\n";
    }
}

void update(){
    load();
    if(n_of_sts==0){
        cout<<"\nNo Student Records Found!\n\n";
        return;
    }
    
    int id,choice;
    bool found=false;
    cout<<"Enter Student ID to update : ";
    cin>>id;
    
    for(int a=0;a<n_of_sts;a++){
        if(id==student[a].id){
            found=true;
            cout<<"\n1.Update Name";
            cout<<"\n2.Update Age";
            cout<<"\n3.Update Marks";
            cout<<"\n4.Return to Main Menu\n";
            cout<<"\nEnter Choice : ";
            cin>>choice;
            
            if(choice==1){
                cout<<"Enter Name you want to update : ";
                cin.ignore();
                getline(cin,student[a].name);
                cout<<"Name Updated Successfully\n";
            }else if(choice==2){
                cout<<"Enter Age you want to update : ";
                cin>>student[a].age;
                cout<<"Age Updated Successfully\n";
            }else if(choice==3){
                student[a].total=0;
                for(int i=0;i<5;i++){
                    cout<<"Subject"<<i+1<<" : ";
                    cin>>student[a].marks[i];
                    student[a].total+=student[a].marks[i];
                }
                student[a].perc=(student[a].total*100)/500.0;
                if(student[a].perc>=85){
                    student[a].grade="A";
                }else if(student[a].perc>=70){
                    student[a].grade="B";
                }else if(student[a].perc>=50){
                    student[a].grade="C";
                }else{
                    student[a].grade="F";
                }
                cout<<"\nMarks Updated Successfully\n";
            }else if(choice==4){
            	return;
			}else{
                cout<<"Invalid Choice!\n";
            }
            save();
//            break;
        }
    }
    
    if(!found){
        cout<<"Student with ID "<<id<<" not found!\n";
    }
}

void remove(){
    load();
    if(n_of_sts== 0){
        cout <<"\nNo Student Records Found!\n\n";
        return;
    }
    int id;
    cout<<"Enter Student ID to delete: ";
    cin>>id;
	int new_sts =0;
	bool isbool = false;
	for(int a=0 ; a<n_of_sts; a++){
		if(id!=student[a].id){
			student[new_sts] = student[a];
			new_sts++;
		}else{
			isbool = true; // ak bhi value tr
		}
	}
    if(!isbool){
    	cout<<"Student with ID "<<id<<" not found!\n";
    	return;
	}
	n_of_sts = new_sts;
	save();
	cout << "All student records with ID " << id << " deleted successfully!\n";
	
    
}

int main(){
    int choice;
    load();
    while(true){
        menu();
        cout<<"\nEnter Choice (0-6) : ";
        cin>>choice;
        
        switch(choice){
            case 0:
                cout<<"\nExiting Program.........";
                cout<<"\nExited Successfully";
                return 0;
            case 1:
                input();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort();
                break;
            case 5:
                update();
                break;
            case 6:
                remove();
                break;
            default:
                cout<<"\nInvalid Number,Try Again!!!\n";
        }
    }
    return 0;
}
