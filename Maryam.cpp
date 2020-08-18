#include <iostream>
#include <fstream>
using namespace std;

class HOD
{
public:
    // Attributes
    string name, surename, gender;
    int age;

public:
    // SETTERS
    void set_name(string n)
    {
        name = n;
    }
    void set_surname(string s)
    {
        surename = s;
    }
    void set_gender(string g)
    {
        gender = g;
    }
    void set_age(int a)
    {
        age = a;
    }

    //GETTERS
    string get_name()
    {
        return this->name;
    }
    string get_surename()
    {
        return this->surename;
    }
    string get_gender()
    {
        return this->gender;
    }
    int get_age()
    {
        return this->age;
    }
};

class subject
{
    // Attributes
public:
    static string data_file;
    string subject_name, subject_id;
    int crdit_hrs;

    // GETTERS
    void set_item_name(string n)
    {
        this->subject_name = n;
    }
    void set_subject_id(string i)
    {
        this->subject_id = i;
    }
    void set_crdit_hrs(int p)
    {
        this->crdit_hrs = p;
    }
    // SETTERS
    string get_item_name()
    {
        return this->subject_name;
    }
    string get_subject_id()
    {
        return this->subject_id;
    }
    int get_crdit_hrs()
    {
        return this->crdit_hrs;
    }

    string get_data_file()
    {
        return this->data_file;
    }
};

class staff_member : public HOD
{
    // Attributes
    static string data_file;
    string c_id;

public:
    // GETTERS
    subject p;
    void set_staff_memberid(string s)
    {
        this->c_id = s;
    }
    //SETTERS
    string get_staff_memberid()
    {
        return this->c_id;
    }
    string get_data_file()
    {
        return this->data_file;
    }
};

string staff_member ::data_file = "staff_member";
string subject ::data_file = "subject";

class data
{
public:
    staff_member C[100];
    subject P[100];
    int psize, csize;
    data()
    {

        string c_id, name, sure, gend, iname, iid;
        int pric, age;
        ifstream cfile;
        cfile.open("staff_member.txt");

        if (cfile)
        {
            int i = 0;
            while (!cfile.eof())
            { // READING staff_member RECORD FROM DATA FILE staff_member.TXT
                csize = i;
                cfile >> c_id >> name >> sure >> gend >> age >> iid >> iname >> pric;
                C[i].set_age(age);
                C[i].set_staff_memberid(c_id);
                C[i].set_gender(gend);
                C[i].set_name(name);
                C[i].set_surname(sure);
                C[i].p.set_subject_id(iid);
                C[i].p.set_item_name(iname);
                C[i].p.set_crdit_hrs(pric);
                i++;
            }
        }
        else
            cout << "ERROR IN CUSTOMR FILE";
        cfile.close();

        ifstream pfile;
        pfile.open("subjects.txt");

        if (pfile)
        {
            int x = 0;
            while (!pfile.eof())
            { // READING subject RECORD FROM DATA FILE subject.TXT
                psize = x;
                pfile >> iid >> iname >> pric;
                P[x].set_subject_id(iid);
                P[x].set_item_name(iname);
                P[x].set_crdit_hrs(pric);
                x++;
            }
        }
        pfile.close();
    }

    //SHOW subject RECORD
    void show_item()
    {
        for (int i = 0; i <= psize; i++)
        {
            cout << P[i].get_subject_id() << "\t" << P[i].get_item_name() << "\t" << P[i].get_crdit_hrs() << endl;
        }
    }

    //SHOW staff_member RECORD
    void show_staff_member()
    {
        for (int i = 0; i <= csize; i++)
        {
            cout << C[i].get_age() << "\t" << C[i].gender << "\t" << C[i].get_staff_memberid() << "\t" << C[i].get_gender() << "\t" << C[i].get_name() << "\t" << C[i].get_surename() << endl;
        }
    }

    void search_item()
    {
        string s;
        cout << " ENTER ID ";
        cin >> s;
        for (int i = 0; i <= psize; i++)
        {
            if (P[i].get_subject_id() == s)
            {
                cout << P[i].get_subject_id() << "\t" << P[i].get_item_name() << "\t" << P[i].get_crdit_hrs() << endl;
                return;
            }
        }
        cout << "Record not found ";
    }
    void searc_staff_member()
    {
        string s;
        cout << " ENTER ID ";
        cin >> s;
        for (int i = 0; i <= csize; i++)
        {
            if (C[i].get_staff_memberid() == s)
            {
                cout << P[i].get_subject_id() << "\t" << P[i].get_item_name() << "\t" << P[i].get_crdit_hrs() << endl;
                return;
            }
        }
        cout << "Record not found ";
    }

    void add_staff_member()
    {
        string c_id, name, sure, gend, iname, iid;
        int pric, age;
        cout << "Entre staff_member id ";
        cin >> c_id;
        cout << "entre name  ";
        cin >> name;
        cout << "entre surename  ";
        cin >> sure;
        cout << "Entre gender ";
        cin >> gend;
        cout << "Entre subject name ";
        cin >> iname;
        cout << "Entre subject id ";
        cin >> iid;
        cout << "Entre age";
        cin >> age;
        cout << "Entre subject crdit_hrs ";
        cin >> pric;
        csize++;
        C[csize].set_age(age);
        C[csize].set_staff_memberid(c_id);
        C[csize].set_gender(gend);
        C[csize].set_name(name);
        C[csize].set_surname(sure);
        C[csize].p.set_subject_id(iid);
        C[csize].p.set_item_name(iname);
        C[csize].p.set_crdit_hrs(pric);
    }

    void delete_staff_member()
    {
        string s;
        cout << "Entre ID";
        cin >> s;
        int i = 0;
        for (i = 0; i <= csize; i++)
        {
            if (C[i].get_staff_memberid() == s)
            {
                break;
            }
        }
        while (i < csize)
        {
            C[i] = C[i + 1];
            i++;
        }
        csize--;
    }
    void delete_item()
    {
        string s;
        cout << "Entre ID";
        cin >> s;
        int i = 0;
        for (i = 0; i <= psize; i++)
        {
            if (P[i].get_subject_id() == s)
            {
                break;
            }
        }
        while (i < psize)
        {
            P[i] = P[i + 1];
            i++;
        }
        psize--;
    }

    void update_staff_member()
    {
        string c_id, name, sure, gend, iname, iid;
        int pric, age;
        string s;
        cout << "Entre ID";
        cin >> s;
        for (int i = 0; i <= csize; i++)
        {
            if (C[i].get_staff_memberid() == s)
            {

                cout << "Entre staff_member id ";
                cin >> c_id;
                cout << "entre name  ";
                cin >> name;
                cout << "entre surename  ";
                cin >> sure;
                cout << "Entre gender ";
                cin >> gend;
                cout << "Entre subject name ";
                cin >> iname;
                cout << "Entre subject id ";
                cin >> iid;
                cout << "Entre age";
                cin >> age;
                cout << "Entre subject crdit_hrs ";
                cin >> pric;
                C[i].set_age(age);
                C[i].set_staff_memberid(c_id);
                C[i].set_gender(gend);
                C[i].set_name(name);
                C[i].set_surname(sure);
                C[i].p.set_subject_id(iid);
                C[i].p.set_item_name(iname);
                C[i].p.set_crdit_hrs(pric);
                return;
            }
        }
    }

    void menu()
    {
        char c;
        while (true)
        {

            system("cls");
            cout << "1.ADD staff_member\n";
            cout << "2.Show staff_member\n";
            cout << "3.Show subject\n";
            cout << "4.Search staff_member\n";
            cout << "5.Seach subject\n";
            cout << "6.Delete staff_member\n";
            cout << "7.Delete subject\n";
            cout << "8.Update staff_member\n";
            cout << "9.EXIT\n";
            cout << "Entre choice ";
            cin >> c;
            switch (c)
            {
            case '1':
                system("cls");
                this->add_staff_member();
                system("pause");
                break;
            case '2':
                system("cls");
                this->show_staff_member();
                system("pause");
                break;
            case '3':
                system("cls");
                this->show_item();
                system("pause");
                break;
            case '4':
                system("cls");
                this->searc_staff_member();
                system("pause");
                break;
            case '5':
                system("cls");
                this->search_item();
                system("pause");
                break;
            case '6':
                system("cls");
                this->delete_staff_member();
                system("pause");
                break;
            case '7':
                system("cls");
                this->delete_item();
                system("pause");
                break;
            case '8':
                system("cls");
                this->update_staff_member();
                system("pause");
                break;
            case '9':
                exit(1);
            default:
                break;
            }
        }
    }
};

int main()
{
    data D;
    D.menu();
}
