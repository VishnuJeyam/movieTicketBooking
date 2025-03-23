#include<iostream>
#include<string>
using namespace std;
class movie
{
        public:
                static int ticketno;
                int tno;
                int bookingcost;
            string time;
            string moviename;
            bool booked;
            int seatnumber;
            int numSeatsNeeded,bookedSeats[100];
            int seat1[10][10],seat2[10][10],seat3[10][10],seat4[10][10],seat5[10][10],seat6[10][10],seat7[10][10],seat8[10][10];
            movie();
            void displayseats(int seats[][10]);
            void bookseats(int seats[][10]);
                void moviedisplay();
                void showtime1();
                void showtime2();
};
class snacks:public movie
{
        public:
                int snackamount;
                string snack;
                int no;
                bool wantsnack;
                void snacksdisplay();
};
class ticket:public snacks
{
        public:
                int totalamount;
                int calpayment(int,int);
                void payment();
                void ticketdisplay();
};
int movie::ticketno=0;
movie::movie()
{
        int seatNumbers1 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat1[i][j] = seatNumbers1++;
        }
    }
    int seatNumbers2 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat2[i][j] = seatNumbers2++;
        }
    }
    int seatNumbers3 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat3[i][j] = seatNumbers3++;
        }
    }
    int seatNumbers4 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat4[i][j] = seatNumbers4++;
        }
    }
    int seatNumbers5 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat5[i][j] = seatNumbers5++;
        }
    }
    int seatNumbers6 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat6[i][j] = seatNumbers6++;
        }
    }
    int seatNumbers7 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat7[i][j] = seatNumbers7++;
        }
    }
    int seatNumbers8 = 1;
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            seat8[i][j] = seatNumbers8++;
        }
    }

    booked=false;
}
void movie::displayseats(int seats[][10])
{
        cout<<endl<<"> > > > > > > > > > > > > > > >  AVAILABLE SEATS < < < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - | Entrance | - "<<endl;
    for (int i = 0; i < 10; i++)
        {
                cout<<endl;
        for (int j = 0; j < 10; j++) {
            cout <<"\t"<< seats[i][j];
        }
        cout << endl;
    }
    cout<<endl<<"- - - - - - - - - - - - - - - - - - |  Screen Here  | - - - - - - - - - - - - - - - -"<<endl<<endl;
}
void movie::bookseats(int seats[][10])
{
        cout<<"| NOTE :Ticket per person = Rs.150 |"<<endl;
        tno=++ticketno;
    cout << "\nEnter the number of seats you need: ";
    cin >> numSeatsNeeded;
    booked=true;
    bookingcost=numSeatsNeeded*150;
        cout << "Enter the seat numbers you want to book:\n";
        for (int k = 0; k < numSeatsNeeded; k++) {
            int seatNum;
            cout << "Seat " << k + 1 << ": ";
            cin >> seatNum;
            bool found = false;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (seats[i][j] == seatNum) {
                        seats[i][j] = 0;
                        bookedSeats[k] = seatNum;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }

            if (!found) {
                cout << "Invalid seat number! Please try again.\n";
                k--;
            }
        }

        cout << "\nYou have successfully booked the following seat(s):\n";
        for (int k = 0; k < numSeatsNeeded; k++) {
            cout << bookedSeats[k] << " ";
        }
        cout << endl;
        cout<<endl<<endl<<"updated seats after booking :"<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - | Entrance | - "<<endl;
    for (int i = 0; i < 10; i++)
        {
                cout<<endl;
        for (int j = 0; j < 10; j++) {
            cout <<"\t"<< seats[i][j];
        }
        cout << endl;
    }
    cout<<endl<<"- - - - - - - - - - - - - - - - - - |  Screen Here  | - - - - - - - - - - - - - - - -"<<endl<<endl;
    cout<<endl<<"NOTE : Seat numbers with '0' are booked seats"<<endl;
}
void movie::moviedisplay()
{
        int ch;
        cout<<endl<<"> > > > > > > > > > > > > > CURRENT RUNNING MOVIES < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"1.                          |  2.                       "<<endl;
        cout<<"MOVIE NAME : Varisu         |  MOVIE NAME : Thunivu     "<<endl;
        cout<<"RATING : 6/10               |  RATING : 6.1/10          "<<endl;
        cout<<"82% Liked this flim         |  80% Liked this flim      "<<endl;
        cout<<"LEAD ACTOR : Vijay          |  LEAD ACTOR : Ajith Kumar "<<endl<<endl;
        cout<<"Enter the movie no:";
        cin>>ch;
        switch(ch)
        {
                case 1:
                        {
                                showtime1();
                                break;
                        }
                case 2:
                        {
                                showtime2();
                                break;
                        }
                default:cout<<"INVALID CHOICE!";
        }
}
void movie::showtime1()
{
        moviename="Varisu";
        cout<<"> > > > > > > > > > > > > > > > > TIMINGS < < < < < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"1. [ 10.00 AM ]"<<"\t\t";
        cout<<"2. [ 02.30 PM ]"<<"\t\t";
        cout<<"3. [ 06:30 PM ]"<<"\t\t";
        cout<<"4. [ 10:30 PM ]"<<endl;
        cout<<endl<<"Enter the show time : ";
        int n;
        cin>>n;
        switch(n)
        {
                case 1:
                        {
                                displayseats(seat1);
                                bookseats(seat1);
                                time="10am";
                                break;
                        }
                case 2:
                        {
                                displayseats(seat2);
                                bookseats(seat2);
                                time="2.30pm";
                                break;
                        }
                case 3:
                        {
                                displayseats(seat3);
                                bookseats(seat3);
                                time="6,30pm";
                                break;
                        }
                case 4:
                        {
                                displayseats(seat4);
                                bookseats(seat4);
                                time="10.30pm";
                                break;
                        }
                default:cout<<endl<<"INVALID CHOICE!"<<endl;
        }
}
void movie::showtime2()
{
        moviename="Thunivu";
        cout<<"> > > > > > > > > > > > > > > > > TIMINGS < < < < < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"1. [ 10.00 AM ]"<<"\t\t";
        cout<<"2. [ 02.30 PM ]"<<"\t\t";
        cout<<"3. [ 06:30 PM ]"<<"\t\t";
        cout<<"4. [ 10:30 PM ]"<<endl;
        cout<<endl<<"Enter the show time : ";
        int n;
        cin>>n;
        switch(n)
        {
                case 1:
                        {
                                displayseats(seat5);
                                bookseats(seat5);
                                time="10am";
                                break;
                        }
                case 2:
                        {
                                displayseats(seat6);
                                bookseats(seat6);
                                time="2.30pm";
                                break;
                        }
                case 3:
                        {
                                displayseats(seat7);
                                bookseats(seat7);
                                time="6,30pm";
                                break;
                        }
                case 4:
                        {
                                displayseats(seat8);
                                bookseats(seat8);
                                time="10.30pm";
                                break;
                        }
                default:cout<<endl<<"INVALID CHOICE!"<<endl;
        }
}



void snacks::snacksdisplay()
{
        int snac;
        wantsnack=false;
        cout<<"> > > > > > > > > > > > > > > > > > SNACKS LIST < < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"\tsno\tITEM\t\t\tRATE"<<endl;
        cout<<"\t1.\tPopcorn\t\t\tRs.60"<<endl;
        cout<<"\t2.\tCoke\t\t\tRs.40"<<endl;
        cout<<"\t3.\tPuffs\t\t\tRs.30"<<endl;
        cout<<"\t4.\tFrenchFries\t\t\tRs.80"<<endl;
        cout<<"\t5.\tIceCreaam\t\t\tRs.40"<<endl<<endl;
        cout<<"Enter your snacks : ";
        cin>>snac;
        switch(snac)
        {

                case 1:
                        {
                                cout<<"Enter no. of popcorns :";
                                cin>>no;
                                snackamount=no*60;
                                snack="popcorn";
                                wantsnack=true;
                                break;
                        }
                case 2:
                        {
                                cout<<"Enter no. of Cokes :";
                                cin>>no;
                                snackamount=no*40;
                                snack="coke";
                                wantsnack=true;
                                break;
                        }
                case 3:
                        {
                                cout<<"Enter no. of puffs :";
                                cin>>no;
                                snackamount=no*30;
                                snack="puffs";
                                wantsnack=true;
                                break;
                        }
                case 4:
                        {
                                cout<<"Enter no. of frenchfries :";
                                cin>>no;
                                snackamount=no*80;
                                snack="french fries";
                                wantsnack=true;
                                break;
                        }
                case 5:
                        {
                                cout<<"Enter no. of icecreams :";
                                cin>>no;
                                snackamount=no*40;
                                snack="Ice Cream";
                                wantsnack=true;
                                break;
                        }
                default:cout<<"Invalid choice!";

        }

}
int ticket::calpayment(int bc,int sm)
{
        return bc+sm;
}
void ticket::payment()
{
        int ch;
        cout<<"- - - - - - - - - - - - - - - Payment Details - - - - - - - - - - - - - - - - "<<endl<<endl;
        cout<<"Total Amount = "<<calpayment(bookingcost,snackamount)<<endl;
        cout<<"press 1 to confirm payment"<<endl<<"press 2 to Cancel payment"<<endl;
        cout<<"Kindly enter your option here : ";
        cin>>ch;
        if(ch==1)
        {
                ticketdisplay();
        }
        else
        {
                cout<<"your payment is cancelled"<<endl<<endl;
                booked=false;
        }
}
void ticket::ticketdisplay()
{
        cout<<endl<<"Your Ticket:"<<endl;
        cout<<endl<<"\t* * * * * * * * *  * * Ticket * * * * * * * * * * * *"<<endl<<endl;
        cout<<"\tTheater Name : VJ CINEMAS "<<endl;
        cout<<"\tTicket number : "<<tno<<endl;
        cout<<"\tMovie Name : "<<moviename<<endl;
        cout<<"\tShow time : "<<time<<endl;
        cout<<"\tSeat number(s):";
        for (int k = 0; k < numSeatsNeeded; k++) {
            cout << bookedSeats[k] << " ";
        }
        cout << endl;
    if(wantsnack)
    {
        cout<<"\tSnacks : "<<snack<<"-"<<no<<endl;
        }
        else
        {
                cout<<"\tSnacks : NONE"<<endl;
        }
        cout<<"\tTotal Cost : "<<calpayment(bookingcost,snackamount)<<endl<<endl;
        cout<<"\t* * * * * * * Thank You For Booking!* * * * * * * * * *"<<endl<<endl;
}
int main()
{
        int ch;
        cout<<"> > > > > > > > > > > > > VJ CINEMAS < < < < < < < < < < < < < < < <"<<endl<<endl;
        cout<<"- - - - - - - - - - welcome! Choose an option below - - - - - - - - - "<<endl<<endl;
        ticket t;
        do
        {
                cout<<"\t\t1.Book Tickets"<<endl;
            cout<<"\t\t2.View Your Ticket"<<endl;
        cout<<"\t\t3.EXIT"<<endl<<endl;
        cout<<"Enter your choice :";
                cin>>ch;
                switch(ch)
                {
                case 1:
                        {
                                string op;
                                t.moviedisplay();
                                cout<<endl<<"Do you need Snacks(yes/no) :";
                                cin>>op;
                                if(op=="yes")
                                {
                                        t.snacksdisplay();
                                }
                                else
                                {
                                        t.snackamount=0;
                                        t.wantsnack=false;
                                }
                                t.payment();
                                break;
                        }
                case 2:
                        {
                                if(t.booked)
                                {
                                        t.ticketdisplay();
                                }
                                else
                                {
                                        cout<<"you haven't booked your ticket yet !"<<endl;
                                }
                                break;
                        }
                case 3:
                        {
                                cout<<endl<<"THANK YOU FOR BOOKING!  VISIT US AGAIN ..."<<endl;
                                return 0;
                                break;
                        }
                default:cout<<"Invalid choice!";
        }
        }while(true);
        return 0;
}
int a=0;