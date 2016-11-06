//this is the header file for the program which contains the class
#ifndef FinalProject_hpp
#define FinalProject_hpp
#include <iostream> 

using namespace std;

class Access {
	private:
		int homeAccess;
	
	public:
		Access(int homeAccess) 
		{
			this -> homeAccess = homeAccess;
		}
		
		int getAccess(int homeAccess) 
		{
			return homeAccess;
		}
		
		void setAccess(int homeAccess) 
		{
			this -> homeAccess = homeAccess;
		}
		
		int ifAccess(int)
		{
			if (homeAccess > 1) 
			{
				string error = "error";
				throw error;
				
				cout << error;
			}
			return homeAccess;
		}
};


#endif
