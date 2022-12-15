#include "Time.h"
#include <string>

Time::Time(void) : hour(0), minute(0), seconds(0) {}

Time::Time(int a, int b, int c) {
	hour = a;
	minute = b;
	seconds = c;
}

void Time::set_first(int first) {
	hour = first;
}

int Time::get_first() {
	return hour;
}

void Time::set_second(int second) {
	minute = second;
}

int Time::get_second() {
	return minute;
}

void Time::set_third(int third) {
	seconds = third;
}

int Time::get_third() {
	return seconds;
}

void Time::add_first() {
	hour++;
}

void Time::add_second() {
	minute++;
}

void Time::add_third() {
	seconds++;
}

void Time::add_seconds(int third) {
	seconds += third;
}

void Time::add_minute(int second) {
	minute += second;
}

void Time::normalize_time() {
	if (seconds >= 60) {
		minute += seconds / 60;
		seconds %= 60;
	}
	if (minute >= 60) {
		hour += minute / 60;
		minute %= 60;
	}
	if (hour >= 24) {
		hour %= 24;
	}
}

void Time::get_time() {
	cout << hour << ":" << minute << ":" << seconds << endl;
}

ostream& operator<<(ostream& out, Time& d) {
	out << "Hour = " << d.hour << endl;
	out << "Minute = " << d.minute << endl;
	out << "Seconds = " << d.seconds << endl;
	return out;
}

istream& operator>>(istream& in, Time& d) {
	in >> d.hour;
	in >> d.minute;
	in >> d.seconds;
	return in;
}

string Time::toString() {
	string s = "Hour: " + to_string(hour) + ". Minute: " + to_string(minute) + ". Seconds: " + to_string(seconds) + ".";
	return s;
}
