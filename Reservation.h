#include "Database.h"
#include"Account.h"
#include<ctime>
#include"Account.h"
#include"Datetime.h"
#include"ReservationFilter.h"
#include"UserData.h"

class Reservation{
	private:
		string _id;
		DateTime _startTime;
		DateTime _expiredTime;
		User* _borrower;
	public:
		Reservation(string _id, DateTime _startTime, DateTime _expiredTime, User* _borrower){
			this->_id = _id;
			this->_startTime = _startTime;
			this-> _expiredTime = _expiredTime;
			this->_borrower = _borrower;
		}
		bool isExpired(){
			if (this->_expiredTime - this->_startTime <=0){
				return 1;
			}
			return 0;
		}
		int getTimeLeft(){
			return this->_expiredTime- this->_startTime;
		}
		vector<string> getReserve(){
			vector<string> res;
			res.push_back(this->_id);
			res.push_back(this->_startTime.To_String());
			res.push_back(this->_expiredTime.To_String());
			res.push_back(to_string(2));
			res.push_back(this->_borrower->getId());
			return res;
		}
		void print(){
			cout<<this->_id<<" "<<this->_startTime.To_String()<<" "<<this->_expiredTime.To_String()<<" "<<this->_borrower->getId()<<endl;
		}
};

class ReservationData:public Database{
	private:
		vector<vector<string>> reservationData;
	public:
		ReservationData(string ReservationDatabase):Database(ReservationDatabase){
			this->reservationData = getRecord();
		}
		bool createReservation(){
			createRecord(this->reservationData);
			return 1;
		}
		vector<vector<string>> getAllData(){
			return this->reservationData;
		}
		
		vector<Reservation> readAllReservation(){
			vector<Reservation> res;
			for (auto row: this->reservationData){
				string id = row[0];
				DateTime startTime = DateTime(row[1]);
				DateTime expiredTime = DateTime(row[2]);
				UserData* tmp = new UserData("Account.csv"); 
				User* borrower = tmp->GetUser(row[4]); 
				Reservation resevereRow =  Reservation(id,startTime, expiredTime, borrower);
				res.push_back(resevereRow);
			}
			return res;
		} 

		bool updateReservation(Reservation a){
			vector<string> reserve  = a.getReserve();
			this->updateRecord(reserve);
			return 1;
		}

		static bool compare(vector<string> a1, vector<string> a2){
			if (a1.size() != a2.size()){
				return 0;
			}
			for (int i=0;i<a1.size();i++){
				if (a1[i] != a2[i]){
					return 0;
				}
			}
			return 1;
		}

		bool deleteReservation(Reservation a){
			vector<string> reserve = a.getReserve();
			vector<vector<string>> tmp;
			bool check = 0;
			for (auto row: this->reservationData){
				if (compare(row,reserve)){
					check = 1;
					continue;
				}
				else{
					tmp.push_back(row);
				}
			} 
			return check;
		}

		Reservation* readUserReservation(User* user, ReservationFilter check){
			string id = user->getId();
			for (auto row:this->reservationData){
				if (id == row[4]){
					DateTime start = DateTime(row[1]);
					DateTime end = DateTime(row[2]);
					UserData* tmp = new UserData("Account.csv");
					User* borrower = tmp->GetUser(row[4]); 
					Reservation* newReservation = new Reservation(row[0],start, end,borrower);
					return newReservation;
				}
			}
			return NULL;
		}

};
#pragma once