#include<iostream>
using namespace std;
class Bank_Account {
protected:
	int Balance_In_Pennis;
	double Interest_Rate;
	string Account_Number;
public:
	Bank_Account()
	{
		Balance_In_Pennis = 0;
		Interest_Rate = 0.0;
		
	}
	virtual string get_Account_Number()
	{
		return Account_Number;
	}
	virtual void set_Account_Number(string a)
	{
		Account_Number = a;
	}
	virtual void credit(int bal)
	{
		if (bal > 0)
			Balance_In_Pennis = bal;
		else
			Balance_In_Pennis = 0;
	}
	virtual int get_Balance_In_Pennis()
	{
		return Balance_In_Pennis;
	}
	virtual void set_Interest_Rate(double interest)
	{
		Interest_Rate = interest;
	}
	virtual double get_Interest_Rate()
	{
		return Interest_Rate;
	}
	virtual void Apply_Interest() = 0;
	virtual string get_Account_info() = 0;
	virtual bool debit(int val ) = 0;
};
class Saving_Account :public Bank_Account
{
public:
	Saving_Account(int am, double d, const string arr)
	{
		credit(am);
		set_Interest_Rate(d);
		set_Account_Number(arr);
	}
	virtual void Apply_Interest()
	{
		Balance_In_Pennis += Balance_In_Pennis * Interest_Rate / 100;
		
	}
	virtual string get_Account_info()
	{
		cout << "Account_type:  Savings\n";
		cout << "Account_Balance is:  " << Balance_In_Pennis << endl;
		cout << "Interest_Rate is:" << get_Interest_Rate() << endl;
		cout << "Account Number:  " ;
		return Account_Number;
	}
	virtual  bool debit(int val)
	{
		if (Balance_In_Pennis >= val)
		{
			Balance_In_Pennis -= val;
			return true;
		}
		else
			return false;
	}
};
class Checking_Account :public Bank_Account
{
	int Over_Draft_Fee_In_Pennis = 0;
public:
	Checking_Account(int am, double d, const string arr, int fee)
	{   
		    credit(am);
			set_Interest_Rate(d);
			set_Account_Number(arr);
			Over_Draft_Fee_In_Pennis = fee;
	}
	int get_Over_Due_Fee()
	{
		return Over_Draft_Fee_In_Pennis;
	}
	void set_Over_Due_Fee(int val)
	{
		Over_Draft_Fee_In_Pennis = val;
	}
	bool debit(int val)
	{
		if (val <= Balance_In_Pennis)
		{
			Balance_In_Pennis -= val;
			return true;
		}
		else
		{
			Balance_In_Pennis -= Over_Draft_Fee_In_Pennis;
		}
	}
	 void Apply_Interest()
	{
		 Balance_In_Pennis += Balance_In_Pennis * Interest_Rate / 100;

	}
	string get_Account_info()
	{
		cout << "Account type:  Checking" << endl;
		cout << "Balance :  " << Balance_In_Pennis << endl;
		cout << "Interest Rate:  " << Interest_Rate << endl;
		cout << "Over_Draft_Fee:  " << Over_Draft_Fee_In_Pennis << endl;
		cout << "Account_Number:";
		return Account_Number;
	}
};
class Credit_Card_Account :public Bank_Account
{
	int credit_card_limit_in_pennis=0;
public:
	Credit_Card_Account(int am, double d, const string arr, int cred)
	{
			credit(am);
			set_Interest_Rate(d);
			set_Account_Number(arr);
			credit_card_limit_in_pennis = cred;
		
	}
	/*void credit(int val)
	{
		if (val <= credit_card_limit_in_pennis)
		{
			Balance_In_Pennis += val;
			cout << 1;
		}
		else
			cout << 0;
	}*/
	int get_credit_card_limit_in_pennis()
	{
		return credit_card_limit_in_pennis;
	}
	void set_credit_card_limit_in_pennis(int val)
	{
		credit_card_limit_in_pennis = val;
	}
	bool debit(int val)
	{
		if (val <= credit_card_limit_in_pennis&&val<=Balance_In_Pennis)
		{
			Balance_In_Pennis -= val;
			return true;
		}
		else
			return false;
	}
	void Apply_Interest()
	{
		
		int d=Balance_In_Pennis * Interest_Rate/10;
		Balance_In_Pennis += d;

	}
	string get_Account_info()
	{
		cout << "Account type: Credit Card " << endl;
		cout << "Balance :  " << Balance_In_Pennis << endl;
		cout << "Interest Rate:  " << Interest_Rate << endl;
		cout << "credit card limit in pennis:  " << credit_card_limit_in_pennis << endl;
		cout << "Account_Number:";
		return Account_Number;
	}
};
int main()
{
		Bank_Account* b1, * b2, * b3;
		Saving_Account sa(100, 0.05, "03334555928321");
		Checking_Account cha(350, 0.08, "03334897928321", 100);
		Credit_Card_Account cca(1000, 0.2, "05244897928321", 5000);
		b1 = &sa;
		std::cout << b1->get_Account_info() << std::endl;
		//prints saving account info
		b2 = &cha;
		std::cout << b2->get_Account_info() << std::endl;
		//prints checking account info
		b3 = &cca;
		std::cout << b3->get_Account_info() << std::endl;
		//prints credit card account info

		//Saving Account
		cout<<b1->debit(50); //returns true and decreases amountInPennies
		std::cout << b1->get_Account_info() << std::endl;
		//prints saving account info (with amountInPennies = 100)

		//Checking Account
	     cout<<	b2->debit(60); //returns true and decreases amountInPennies
		std::cout << b2->get_Account_info() << std::endl;
		//prints checking account info (with amountInPennies = 290)
		cout<<b2->debit(300); //returns true, 290 - 300 < 0, hence overdraftFee is subtracted, amountInPennies = 190
		std::cout << b2->get_Account_info() << std::endl;
		//prints saving account info (with amountInPennies = 190)

		//CreditCard Account
		cout<<b3->debit(600); //returns true and decreases amountInPennies
		std::cout << b3->get_Account_info() << std::endl;
		//prints checking account info (with amountInPennies = 400)
		b3->credit(20000); //returns false because cannot exceed creditLimit
		b3->debit(400); //returns true, amountInPennies = 0
	   cout<<b3->debit(50); //returns false, cannot overdraw, amountInPennies = 0
	    b3->credit(1000); //returns true, in credit limit, amountInPennies = 1000
		b3->Apply_Interest(); //applies interest because amountInPennie > 0
		std::cout << b3->get_Account_info() << std::endl;
		//prints saving account info (with amountInPennies = 190)
	     return 0;

}