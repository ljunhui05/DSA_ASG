#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "Admin.h"
#include "Order.h"
#include "Member.h"

Admin::Admin() {

}

Admin::Admin(string adminID, string password)
{
	AdminID = adminID;
	Password = password;
}

void Admin::ViewIncomingOrders() {

}
void Admin::UpdateOrderStatus() {

}
void Admin::ViewOrderCustoInfo() {

}


