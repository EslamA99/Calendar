#include <iostream>
#include<cmath>

using namespace std;

class time
{
private:
    int hour;
    int minute;
    string daynight;
public:
    time()
    {
        hour=0;
        minute=0;
        daynight="";
    }

    friend istream&operator>>(istream& in,time& t)
    {

        cout<<"Enter hour = "<<endl;
        in>>t.hour;
        cout<<"Enter minute = "<<endl;
        in>>t.minute;
        cout<<"Enter daynight = "<< endl;
        in>>t.daynight;

        return in;
    }

    friend ostream&operator<<(ostream& out,time& t)
    {
        out<<t.hour<<':'<<t.minute<<" "<<t.daynight<<endl;
        return out;
    }

    bool operator > (time t)
    {
        if(daynight=="PM"&&t.daynight=="AM")
            return true;
        else if(daynight=="AM"&&t.daynight=="PM")
            return false;
        else if(hour>t.hour)return true;
        else if(hour==t.hour&&minute>t.minute)return true;
        else
            return false;

    }

    bool operator < (time t)
    {
        if(daynight=="AM"&&t.daynight=="PM")
            return true;
        else if(daynight=="PM"&&t.daynight=="AM")
            return false;
        else if(hour>t.hour)return true;
        else if(hour==t.hour&&minute>t.minute)return true;
        else
            return false;
    }

    bool operator==(time t)
    {
        if(hour==t.hour&&minute==t.minute&&daynight==t.daynight)
        {
            return true;
        }
        else
            return false;
    }

    bool operator!=(time t)
    {
        if(hour!=t.hour||minute!=t.minute||daynight!=t.daynight)
        {
            return true;
        }
        else
            return false;
    }

    int operator-(time t)
    {
        int sum1=0;
        int sum2=0;
        if(daynight!=t.daynight)
        {
            sum1=abs((hour-t.hour)-12);
            if(hour<t.hour&&minute>t.minute)
            {
                sum2=abs(minute-(t.minute+60));
                sum1--;
            }
            else sum2=abs(minute-t.minute);
        }

        if(daynight==t.daynight)
        {
            sum1=abs((hour-t.hour));
            if(hour<t.hour&&minute>t.minute)
            {
                sum2=abs(minute-(t.minute+60));
                sum1--;
            }
            else sum2=abs(minute-t.minute);
        }
        return (sum1*60)+sum2;
    }
};

class appointment
{
private:
    time start;
    time end;
public:

    appointment() {}

    void setstart(time s)
    {
        start=s;
    }

    time getstart()
    {
        return start;
    }

    void setend(time e)
    {
        end=e;
    }

    time getend()
    {
        return end;
    }

    bool operator==(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1==sum2)
            return true;
        else
            return false;
    }

    bool operator!=(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1!=sum2)
            return true;
        else
            return false;
    }

    bool operator>(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1>sum2)
            return true;
        else

            return false;
    }

    bool operator>=(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1>=sum2)
            return true;
        else

            return false;
    }

    bool operator<(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1<sum2)
            return true;
        else
            return false;
    }

    bool operator <=(appointment ap)
    {
        int sum1=0;
        int sum2=0;
        sum1=start-end;
        sum2=ap.start-ap.end;
        if(sum1<=sum2)
            return true;
        else
            return false;
    }

    friend istream&operator>>(istream& in,appointment& t)
    {
        cout<<"Enter Start time = "<<endl;
        in>>t.start;
        cout<<"Enter End time = "<<endl;
        in>>t.end;
        return in;
    }

    friend ostream&operator<<(ostream& out,appointment& t)
    {
        out<<"Start time = "<<t.start<<endl<<"End time = "<<t.end<<endl;
        return out;
    }

    appointment operator=(appointment& t)
    {
        start=t.start;
        end=t.end;
        return *this;
    }


};

class DayAppointments
{
private:
    appointment * appointments;
    int numOfAppointments;
    string weekDay;
public:
    DayAppointments()
    {
        numOfAppointments=0;
    }
    void insert_(appointment &t)
    {
        int p=0;
        appointment * appointments2;
        numOfAppointments=numOfAppointments+1;
        appointments2= new appointment[numOfAppointments];

        for(int i=0; i<numOfAppointments-1; i++)
        {
            if ((appointments[i].getend()==t.getend()||appointments[i].getstart()==t.getstart())||(t.getstart()>appointments[i].getstart()&&t.getstart()<appointments[i].getend())||(t.getstart()<appointments[i].getstart()&&t.getend()>appointments[i].getend()))
            {
                p++;
                break;
            }
            else if((t.getstart()<appointments[i].getstart()&&t.getend()<appointments[i].getstart())||(t.getstart()<appointments[i].getstart()&&t.getend()<appointments[i].getstart()))
            {
                p=0;
            }
            else
            {
                p=0;
            }
        }

        if (p==0)
        {
            int u=0;
            for(int i=0; i<numOfAppointments; i++)
            {

                if(i==numOfAppointments-1&&u==0){appointments2[i]=t;continue;}
                if(u==0)
                {
                    if(t.getstart()>appointments[i].getstart()&&t.getend()>appointments[i].getend())
                    {
                        appointments2[i]=appointments[i];
                    }
                    else {appointments2[i]=t;u++;}
                }
                else appointments2[i]=appointments[i-1];

            }

            appointments= new appointment[numOfAppointments];
            for(int i=0; i<numOfAppointments; i++)
            {
                appointments[i]=appointments2[i];
            }
        }

        else
        {
            cout<<"Error in insert operation";
            numOfAppointments--;
        }
    }

    appointment & operator []( int  i)
    {
       return  appointments[i];
    }

    void delete_(int n)
    {
        int c=0;
        appointment * appointments1;
        numOfAppointments=numOfAppointments-1;
        appointments1= new appointment[numOfAppointments+1];
        for(int i=0; i<numOfAppointments+1; i++)
        {
            if(i==n-1)
            {
                c++;
                continue;
            }
            else if(c!=0)
            {
                appointments1[i-1]=appointments[i];
            }
            else
            {
                appointments1[i]=appointments[i];
            }
        }
        appointments= new appointment[numOfAppointments];
        for(int i=0; i<numOfAppointments; i++)
        {
            appointments[i]=appointments1[i];
        }
    }

    friend istream &operator>>(istream& in,DayAppointments& t)
    {
        cout<<"Enter your Day: ";
        in>>t.weekDay;
        cout<<"Enter the number of appointment: ";
        in>>t.numOfAppointments;
        t.appointments= new appointment[t.numOfAppointments];
        for(int i=0; i<t.numOfAppointments; i++)
        {
            in>>t.appointments[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream& out,DayAppointments& t)
    {
        out<<"your Day: "<<t.weekDay<<endl<<"number of appointments: "<<t.numOfAppointments<<endl;

        for(int i=0; i<t.numOfAppointments; i++)
        {
            out<<t.appointments[i];
        }
        return out;
    }

    DayAppointments operator=(DayAppointments& t)
    {
        numOfAppointments=t.numOfAppointments;
        appointments= new appointment[numOfAppointments];
        for(int i=0; i<numOfAppointments; i++)
        {
            appointments[i]=t.appointments[i];
        }
        return *this;
    }

    bool operator==(DayAppointments  &t)
    {
        int check=0;
        for(int i=0; i<numOfAppointments; i++)
        {
            if(appointments[i]!=t.appointments[i])
            {
                check++;
            }
        }
        if(check==0)
            return true;
        else
            return false;
    }

    bool operator!=(DayAppointments  &t)
    {
        int check=0;
        for(int i=0; i<numOfAppointments; i++)
        {
            if(appointments[i]==t.appointments[i])
            {
                check++;
            }
        }
        if(check==0)
            return true;
        else
            return false;
    }
};
class Calendar
{
private:
    DayAppointments * days;
    int numOfDays;
public:
    Calendar()
    {
    }
    Calendar(int num)
    {
        days=new DayAppointments[num];
        numOfDays=num;
    }
    void insert2(DayAppointments  d1,int i)
    {
        days[i]=d1;

    }

    friend istream &operator>>(istream& in,Calendar& t)
    {
        cout<<"Number of days: ";
        in>>t.numOfDays;
        t.days= new DayAppointments[t.numOfDays];
        for(int i=0; i<t.numOfDays; i++)
        {
            in>>t.days[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream& out,Calendar& t)
    {



        out<<"number of Days: "<<t.numOfDays<<endl;
        for(int i=0; i<t.numOfDays; i++)
        {

            out<<t.days[i];
        }
        return out;
    }
     DayAppointments & operator []( int  i)
    {
       return days[i];
    }

};

int main()
{
    int choice=0;
    while (true)
    {
        cout<<"1-Compare between two times\n2-Compare between duration of two appointments\n3-Check if two days have equal appointments or not\n4-Insert a appointment to a day\n5-Delete an appointment from a day\n6-Make day of appointment equal to other day of appointment\n7-Create a calendar and perform operations on it\n";
        cin>>choice;

        if(choice==1)
        {
            time t1,t2;
            cin>>t1>>t2;
            cout<<endl<<t1<<endl<<t2<<endl<<endl;
            cout<<"Is (Time1==Time2) = "<<(t1==t2)<<endl;
            cout<<"Is (Time1!=Time2) = "<<(t1!=t2)<<endl;
            cout<<"Is (Time1>Time2) = "<<(t1>t2)<<endl;
            cout<<"Is (Time1<Time2) = "<<(t1<t2)<<endl<<endl;
        }

        if(choice==2)
        {
            appointment a1,a2;
            cin>>a1>>a2;
            cout<<endl<<a1<<endl<<a2<<endl;
            cout<<"Is (Appointment1 == Appointment2) = "<<(a1==a2)<<endl;
            cout<<"Is (Appointment1 != Appointment2) = "<<(a1!=a2)<<endl;
            cout<<"Is (Appointment1 > Appointment2) = "<<(a1>a2)<<endl;
            cout<<"Is (Appointment1 < Appointment2) = "<<(a1<a2)<<endl;
            cout<<"Is (Appointment1 >= Appointment2) = "<<(a1>=a2)<<endl;
            cout<<"Is (Appointment1 <= Appointment2) = "<<(a1<=a2)<<endl<<endl;
        }

        if(choice==3)
        {
            DayAppointments d1,d2;
            cin>>d1>>d2;
            cout<<endl<<d1<<endl<<d2<<endl;
            cout<<"Is (day of appointment1 == day of appointment2) = "<<(d1==d2)<<endl;
            cout<<"Is (day of appointment1 != day of appointment2) = "<<(d1!=d2)<<endl;
        }

        if(choice==4)
        {
            DayAppointments d3;
            appointment a3;
            cin>>d3;
            cout<<"Enter the appointment that you want to be added:\n";
            cin>>a3;
            d3.insert_(a3);
            cout<<endl<<d3<<endl<<endl;
        }

        if(choice==5)
        {
            DayAppointments d4;
            int k=0;
            cin>>d4;
            cout<<"Enter the number of the appointment that you want to delete: ";
            cin>>k;
            d4.delete_(k);
            cout<<endl<<d4<<endl<<endl;
        }

        if(choice==6)
        {
            DayAppointments d5,d6;
            cin>>d5>>d6;
            d6=d5;
            cout<<d6<<endl<<endl;
        }

        if(choice==7)
        {
            Calendar c1;
            cin>>c1;
            int choice2=0;
            while(true)
            {
                cout<<"1-Display an appointment from a day in the calender\n2-Delete an appointment from a day in the calendar\n3-Insert a appointment to a day in the calendar\n4-Print the calendar\n5-Exit\n";
                cin>>choice2;
                if(choice2==1)
                {
                    int d=0;
                    int a=0;
                    cout<<"Enter the number of the day: ";
                    cin>>d;
                    cout<<"Enter the number of appointment: ";
                    cin>>a;
                    DayAppointments app;
                    app=c1[d-1];
                    cout<<app[a-1];
                }
                if(choice2==2)
                {
                    int d=0;
                    int a=0;
                    cout<<"Enter the number of the day: ";
                    cin>>d;
                    cout<<"Enter the number of appointment: ";
                    cin>>a;
                    c1[d-1].delete_(a);
                }
                if(choice2==3)
                {
                    int d=0;
                    int a=0;
                    appointment app;
                    cout<<"Enter the appointment to be added in the calender: "<<endl;
                    cin>>app;
                    /*cout<<"Enter the number of the day: ";
                    cin>>d;
                    cout<<"Enter the number of appointment: ";
                    cin>>a;
                    c1[d-1].insert_(app);
                    */
                    cout<<"How many days do you want to add this appointment? : ";
                    cin>>a;
                    while(a>0)
                    {
                        cout<<"Enter the number of the day: ";
                        cin>>d;
                        c1[d-1].insert_(app);
                        a--;
                    }


                }
                if(choice2==4)
                {
                    cout<<c1;
                }
                if(choice2==5)
                {
                    break;
                }

            }

        }

        if(choice==0)
        {
            break;
        }


    }

}
