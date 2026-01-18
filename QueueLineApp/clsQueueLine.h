#pragma once
#include "clsDate.h"
#include <queue>
#include <stack>
class clsQueueLine {
	class _clsTicket {
		string _TicketTime = "", _Prefix = "";
		int _AverageServeTime = 0, _Number = 0, _WaitingClients = 0, _ExpectedServeTime = 0;
	public:
		_clsTicket(string Prefix, int Number, int WaitingClients, int AverageServeTime) {
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_Number = Number;
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		};
		string TicketTime() {
			return _TicketTime;
		};
		string Prefix() {
			return _Prefix;
		};
		int AverageServeTime() {
			return _AverageServeTime;
		};
		int Number() {
			return _Number;
		};
		string FullNumber() {
			return _Prefix + to_string(_Number);
		}
		int WaitingClients() {
			return _WaitingClients;
		};
		int ExpectedServeTime() {
			return _AverageServeTime * _WaitingClients;
		};
		void Print() {
			cout << "\n\t\t\t\t\t\t_______________________________";
			cout << "\n\n\t\t\t\t\t\t\t      " << FullNumber() << "\n";
			cout << "\n\t\t\t\t\t\t     " << _TicketTime << ".\n";
			cout << "\n\t\t\t\t\t\t      Waiting Clients = " << _WaitingClients << ".\n";
			cout << "\n\t\t\t\t\t\t         Serve Time in";
			cout << "\n\t\t\t\t\t\t          " << ExpectedServeTime() << " Minutes.\n";
			cout << "\t\t\t\t\t\t_______________________________";
		};
	};
	string _Prefix = "";
	int _TotalTickets = 0, _AverageServeTime = 0;
public:
	queue<_clsTicket>QueueLine;
	clsQueueLine(string Prefix, int AverageServeTime) {
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	};
	int WaitingClients() {
		return QueueLine.size();
	};
	short ServedClients() {
		return _TotalTickets - WaitingClients();
	};
	void IssueTicket() {
		_TotalTickets++;
		_clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	};
	void PrintInfo() {
		cout << "\n\n\t\t\t\t\t\t_______________________________";
		cout << "\n\n\t\t\t\t\t\t\t  Queue Info";
		cout << "\n\t\t\t\t\t\t_______________________________";
		cout << "\n\n\t\t\t\t\t\t     Prefix          = " << _Prefix << ".\n";
		cout << "\n\n\t\t\t\t\t\t     Total Tickets   = " << _TotalTickets << ".\n";
		cout << "\n\n\t\t\t\t\t\t     Served Clients  = " << ServedClients() << ".\n";
		cout << "\n\n\t\t\t\t\t\t     Waiting Clients = " << WaitingClients() << ".\n";
		cout << "\t\t\t\t\t\t_______________________________\n\n";
	};
	void PrintTicketsLineRTL() {
		if (QueueLine.empty()) {
			cout << "\n\n\t\t\t\t\tTickets: No Tickets.";
			return;
		};
		queue<_clsTicket>TempQueueLine = QueueLine;
		cout << "\n\n\t\t\t\t\tTickets: ";
		while (!TempQueueLine.empty()) {
			_clsTicket Ticket = TempQueueLine.front();
			cout << Ticket.FullNumber() << " <-- ";
			TempQueueLine.pop();
		};
		cout << endl;
	};
	void PrintTicketsLineLTR() {
		if (QueueLine.empty()) {
			cout << "\n\n\t\t\t\t\tTickets: No Tickets.";
			return;
		};
		queue<_clsTicket>TempQueueLine = QueueLine;
		stack<_clsTicket>TempStackLine;
		cout << "\n\n\t\t\t\t\tTickets: ";
		while (!TempQueueLine.empty()) {
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		};
		while (!TempStackLine.empty()) {
			_clsTicket Ticket = TempStackLine.top();
			cout << Ticket.FullNumber() << " --> ";
			TempStackLine.pop();
		};
		cout << endl;
	};
	void PrintAllTickets() {
		cout << "\n\n\t\t\t\t\t\t\t ---Tickets---";
		if (QueueLine.empty()) {
			cout << "\n\n\t\t\t\t\t\t    ---No Tickets---\n";
			return;
		};
		queue<_clsTicket>TempQueueLine = QueueLine;
		while (!TempQueueLine.empty()) {
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		};
	};
	bool ServeNextClient() {
		if (QueueLine.empty())
			return false;
		QueueLine.pop();
		return true;
	};
};