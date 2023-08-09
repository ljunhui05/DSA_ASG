#include <string>
//#include <vector>
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

/*void ViewIncomingOrders(const vector<Order>& orders, Order::OrderStatus checkStatus) {
    for (const Order& order : orders) {
        if (order.getStatus() == checkStatus) {
            // Display order details (e.g., order ID, customer name, items, etc.)
        }
    }
}

void UpdateOrderStatus(vector<Order>& orders, int orderId, Order::OrderStatus newStatus)
{
    for (Order& order : orders) {
        if (order.getOrderId() == orderId) {
            order.setStatus(newStatus);
            return;
        }
    }
    // Handle case when the specified order ID is not found
}

void ViewOrderCustoInfo(const vector<Order>& orders, int orderId)
{
    for (const Order& order : orders) {
        if (order.getOrderId() == orderId) {
            const Member& customer = order.getCustomerDetails();
            cout << "Order ID: " << order.getOrderId() << endl;
            cout << "Customer Name: " << customer.getName() << endl;
            cout << "Order Status: " << Order::getOrderStatusString(order.getStatus()) << endl;
            // Display other customer information if available
            return; // Exit the loop after finding the order
        }
    }
}*/
