// Course:  CS213 - Programming II  - 2018
// Title:   Assignment III - Task 1 - Problem 1
// Program: CS213-2018-A3-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    17 NOV 2018
// Version: 2.0

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
    time()///empty constructor to put initial value
    {
        hour=0;
        minute=0;
        daynight="";
    }

    friend istream&operator>>(istream& in,time& t)///cin operator to enter the time
    {
        cout<<"Enter hour = "<<endl;
        in>>t.hour;
        cout<<"Enter minute = "<<endl;
        in>>t.minute;
        cout<<"Enter daynight = "<< endl;
        in>>t.daynight;
        return in;
    }

    friend ostream&operator<<(ostream& out,time& t)///cout operator to print the time
    {
        out<<t.hour<<':'<<t.minute<<" "<<t.daynight<<endl;
        return out;
    }

    bool operator > (time t)///bool operator to know who is if the first time bigger than second time
    {
        if(daynight=="PM"&&t.daynight=="AM")///if two times are not in the same 12 hours time
            return true;
        else if(daynight=="AM"&&t.daynight=="PM")///if two times are not in the same 12 hours time
            return false;
        else if(hour>t.hour)return true;///if hour1 > hour2
        else if(hour==t.hour&&minute>t.minute)return true;///if hour1=hour2 and minute1>minute2
        else
            return false;

    }

    bool operator < (time t)///bool operator to know who is if the first time smaller than second time
    {
        if(daynight=="AM"&&t.daynight=="PM")///if two times are not in the same 12 hours time
            return true;
        else if(daynight=="PM"&&t.daynight=="AM")///if two times are not in the same 12 hours time
            return false;
        else if(hour<t.hour)return true;///if hour1 > hour2
        else if(hour==t.hour&&minute<t.minute)return true;///if hour1=hour2 and minute1>minute2
        else
            return false;
    }

    bool operator==(time t)///bool operator to know who is if the first time equal second time
    {
        if(hour==t.hour&&minute==t.minute&&daynight==t.daynight)///if the first time equal second time
        {
            return true;
        }
        else
            return false;
    }

    bool operator!=(time t)///bool operator to know who is if the first time equal second time
    {
        if(hour!=t.hour||minute!=t.minute||daynight!=t.daynight) ///if the first time not equal second time
        {
            return true;
        }
        else
            return false;
    }

    int operator-(time t)///operator to return the deference between the first time and second time in minutes
    {
        int sum1=0;///to put hours of the two times in it
        int sum2=0;///to put minutes of the two times in ti
        if(daynight!=t.daynight)
        {
            sum1=abs((hour-t.hour)-12);///to convert it to 12 hour time
            if(hour<t.hour&&minute>t.minute)///if the deference between two times is less than 1 hour
            {
                sum2=abs(minute-(t.minute+60));
                sum1--;///minus hours by one
            }
            else sum2=abs(minute-t.minute);
        }

        if(daynight==t.daynight)///if two times are in 12 hour time
        {
            sum1=abs((hour-t.hour));
            if(hour<t.hour&&minute>t.minute)///if the deference between two times is less than 1 hour
            {
                sum2=abs(minute-(t.minute+60));
                sum1--; ///minus hours by one
            }
            else sum2=abs(minute-t.minute);
        }
        return (sum1*60)+sum2;///sum1*60 to convert hours to minutes
    }
};

class appointment
{
private:
    time start;
    time end;
public:

    appointment() {}

    void setstart(time s)///function to set the start
    {
        start=s;
    }

    time getstart()///function to get the start
    {
        return start;
    }

    void setend(time e)///function to set the end
    {
        end=e;
    }

    time getend()///function to get the end
    {
        return end;
    }

    bool operator==(appointment ap)///to know if the duration of two times are equal
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1==sum2)///if duration1=duration2
            return true;
        else
            return false;
    }

    bool operator!=(appointment ap)///to know if the duration of two times are not equal
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1!=sum2)///if duration1 not equal duration2
            return true;
        else
            return false;
    }

    bool operator>(appointment ap)///to know if the duration of the first time > duration of the second time
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1>sum2)///if duration1 > duration2
            return true;
        else

            return false;
    }

    bool operator>=(appointment ap)///to know if the duration of the first time > or = duration of the second time
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1>=sum2)///if duration1 > or = duration2
            return true;
        else

            return false;
    }

    bool operator<(appointment ap)///to know if the duration of the first time < duration of the second time
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1<sum2)///if duration1 < duration2
            return true;
        else
            return false;
    }

    bool operator <=(appointment ap)///to know if the duration of the first time < or = duration of the second time
    {
        int sum1=0;///to put first duration in it
        int sum2=0;///to put second duration in it
        sum1=start-end;///using operator- in class time
        sum2=ap.start-ap.end;///using operator- in class time
        if(sum1<=sum2)///if duration1 < or = duration2
            return true;
        else
            return false;
    }

    friend istream&operator>>(istream& in,appointment& t)///cin operator to enter start and end
    {
        cout<<"Enter Start time = "<<endl;
        in>>t.start;
        cout<<"Enter End time = "<<endl;
        in>>t.end;
        return in;
    }

    friend ostream&operator<<(ostream& out,appointment& t)///cout operator to print start and end
    {
        out<<"Start time = "<<t.start<<endl<<"End time = "<<t.end<<endl;
        return out;
    }

    appointment operator=(appointment& t)///t1=t to make everything in t equal to everything in t1
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
        numOfAppointments=0;///initial value for number of appointment
    }
    void insert_(appointment &t)///to insert appointment in a day
    {
        int p=0;///counter to know if the appointment that i want to insert will overlap other existing appointment
        appointment * appointments2;///define new array
        numOfAppointments=numOfAppointments+1;///increase numOfAppointments by one because of the inserted appointment
        appointments2= new appointment[numOfAppointments];///define new array with size=size+1 to add the inserted appointment

        for(int i=0; i<numOfAppointments-1; i++)///for loop to check if the appointment that i want to insert will overlap other existing appointment or not
        {
            ///many condtions to know if the appointment that i want to insert will overlap other existing appointment
            if ((appointments[i].getend()==t.getend()||appointments[i].getstart()==t.getstart())||(t.getstart()>appointments[i].getstart()&&t.getstart()<appointments[i].getend())||(t.getstart()<appointments[i].getstart()&&t.getend()>appointments[i].getend()))
            {
                p++;///p++ if the appointment that i want to insert will overlap other existing appointment
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

        if (p==0)///if the appointment that i want to insert will not overlap other existing appointment
        {
            int u=0;///counter to sort the inserted appointment
            for(int i=0; i<numOfAppointments; i++)
            {
                if(i==numOfAppointments-1&&u==0)///if the inserted appointment is the biggest appointment in the day
                {
                    appointments2[i]=t;///put it in the last index in the day and we are done
                    continue;
                }
                if(u==0)///if the inserted appointment did not insert yet
                {
                    if(t.getstart()>appointments[i].getstart()&&t.getend()>appointments[i].getend())///if the inserted appointment is bigger than appointment[i]
                    {
                        appointments2[i]=appointments[i];
                    }
                    else///if not put it in the index i of the day
                    {
                        appointments2[i]=t;
                        u++;
                    }
                }
                else appointments2[i]=appointments[i-1];///after the inserted appointment has been added to the day

            }

            appointments= new appointment[numOfAppointments];///define array of appointments with the size = size+1
            for(int i=0; i<numOfAppointments; i++)
            {
                appointments[i]=appointments2[i];///put the data in the array of appointment
            }
        }

        else///if the inserted appointment will overlap any of appointments
        {
            cout<<"Error in insert operation\n";
            numOfAppointments--;///return the number of appointment to the first value
        }
    }

    appointment & operator []( int  i)///operator to return the chosen index [i] of the array of appointments
    {
        return  appointments[i];///return the chosen index of the array of appointments
    }

    void delete_(int n)///delete an appointment from a day
    {
        int c=0;///counter to know the index of the chosen appointment to delete
        appointment * appointments1;
        numOfAppointments=numOfAppointments-1;///minus number of appointments by 1
        appointments1= new appointment[numOfAppointments+1];///define new array to put in it the new data
        for(int i=0; i<numOfAppointments+1; i++)
        {
            if(i==n-1)///i is the chosen index
            {
                c++;
                continue;
            }
            else if(c!=0)///if the chosen index is known
            {
                appointments1[i-1]=appointments[i];///equal to the index-1 in the new array because we deleted index
            }
            else///if the chosen index will not be known yet
            {
                appointments1[i]=appointments[i];
            }
        }
        appointments= new appointment[numOfAppointments];///define our array of appointments with the new size (size-1)
        for(int i=0; i<numOfAppointments; i++)
        {
            appointments[i]=appointments1[i];///put the new data in our new array
        }
    }

    friend istream &operator>>(istream& in,DayAppointments& t)///operator print
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

    friend ostream &operator<<(ostream& out,DayAppointments& t)///operator cin
    {
        out<<"your Day: "<<t.weekDay<<endl<<"number of appointments: "<<t.numOfAppointments<<endl;

        for(int i=0; i<t.numOfAppointments; i++)
        {
            out<<t.appointments[i];
        }
        return out;
    }

    DayAppointments(DayAppointments&t){///copy constructor
        numOfAppointments=t.numOfAppointments;
        appointments= new appointment[numOfAppointments];
        for(int i=0; i<numOfAppointments; i++)///for loop to copy the data to the other object
        {
            appointments[i]=t.appointments[i];
        }
    }

    DayAppointments operator=(DayAppointments& t)///t=t1 to put everything of t1 equal to everything in t
    {
        numOfAppointments=t.numOfAppointments;
        appointments= new appointment[numOfAppointments];
        for(int i=0; i<numOfAppointments; i++)///for loop to copy the data to the other object
        {
            appointments[i]=t.appointments[i];
        }
        return *this;
    }

    bool operator==(DayAppointments  &t)///bool operator to know if appointment1 equal to appointment2
    {
        if(numOfAppointments!=t.numOfAppointments)return false;
        int check=0;///counter to know if appointment1 not equal to appointment2
        for(int i=0; i<numOfAppointments; i++)
        {
            if((appointments[i].getstart()!=t.appointments[i].getstart())||(appointments[i].getend()!=t.appointments[i].getend()))///if appointment1 not equal to appointment2
            {
                check++;
            }
        }
        if(check==0)
            return true;
        else
            return false;
    }

    bool operator!=(DayAppointments  &t)///bool operator to know if appointment1 not equal to appointment2
    {
        int check=0;///counter to know if appointment1 equal to appointment2
        for(int i=0; i<numOfAppointments; i++)
        {
            if((appointments[i].getstart()==t.appointments[i].getstart())||(appointments[i].getend()==t.appointments[i].getend()))///if appointment1 equal to appointment2
            {
                check++;
            }
        }
        if(check==0)
            return true;
        else
            return false;
    }
    ~DayAppointments(){
        for(int i=0; i<numOfAppointments; i++){delete &appointments[i];}
        delete [] appointments;
    }
};
class Calendar
{
private:
    DayAppointments * days;
    int numOfDays;
public:
    Calendar(){}

    friend istream &operator>>(istream& in,Calendar& t)///cin to enter the calendar
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

    friend ostream &operator<<(ostream& out,Calendar& t)///cout the calendar
    {
        out<<"number of Days: "<<t.numOfDays<<endl;
        for(int i=0; i<t.numOfDays; i++)
        {
            out<<t.days[i];
        }
        return out;
    }

    DayAppointments & operator []( int  i)///operator to return the chosen day of the calendar
    {
        return days[i];///return the chosen day of the calendar
    }

};

int main()
{
    int choice=0;
    while (true)
    {
        cout<<"1-Compare between two times\n2-Compare between duration of two appointments\n3-Check if two days have equal appointments or not\n4-Insert a appointment to a day\n5-Delete an appointment from a day\n6-Make day of appointment equal to other day of appointment\n7-Create a calendar and perform operations on it\n8-Exit\n";
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
                cout<<"1-Display an appointment from a day in the calender\n2-Delete an appointment from a day in the calendar\n3-Insert a appointment to a day in the calendar\n4-Check if two days have equal appointments\n5-Print the calendar\n6-Exit\n";
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
                    app=c1[d-1];///minus 1 because we send to the operator the index
                    cout<<app[a-1];///minus 1 because we send to the operator the index
                }
                if(choice2==2)
                {
                    int d=0;
                    int a=0;
                    cout<<"Enter the number of the day: ";
                    cin>>d;
                    cout<<"Enter the number of appointment: ";
                    cin>>a;
                    c1[d-1].delete_(a);///minus 1 because we send to the operator the index
                }
                if(choice2==3)
                {
                    int d=0;
                    int a=0;
                    appointment app;
                    cout<<"Enter the appointment to be added in the calender: "<<endl;
                    cin>>app;
                    cout<<"How many days do you want to add this appointment? : ";
                    cin>>a;
                    while(a>0)///loop until the inserted appointment will be added to the days user entered
                    {
                        cout<<"Enter the number of the day: ";
                        cin>>d;
                        c1[d-1].insert_(app);///minus 1 because we send to the operator the index
                        a--;
                    }
                }

                if(choice2==4)
                {
                    int d=0;///number of the day
                    int a=0;///number of the other day
                    cout<<"Enter the number of the day: ";
                    cin>>d;
                    cout<<"Enter the number of the other day: ";
                    cin>>a;
                    if(c1[d-1]==c1[a-1])cout<<"true\n";///minus 1 because we send to the operator the index
                    else cout<<"false\n";
                }

                if(choice2==5)
                {
                    cout<<c1;
                }

                if(choice2==6)
                {
                    break;
                }

            }

        }

        if(choice==8)
        {
            break;
        }


    }

}
