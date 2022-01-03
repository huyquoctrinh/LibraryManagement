#include"Account.h"
#include"Reservation.h"
using namespace std;

int main(){

    ReservationData* data = new ReservationData("Reservation.csv");
    vector<Reservation> res = data->readAllReservation();
    for (auto reserve: res){
        reserve.print();
        cout<<endl;
    }

}