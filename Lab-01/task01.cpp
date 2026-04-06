//#include <iostream>
//using namespace std;
//
//class Course {
//public:
//    virtual ~Course() = default;
//
//    virtual int duration() const = 0;
//};
//
//class OnlineCourse : public Course {
//private:
//    int weeks;
//    int hoursPerWeek;
//
//public:
//    OnlineCourse(int w, int hpw) : weeks(w), hoursPerWeek(hpw) {}
//
//    int duration() const override {
//        return weeks * hoursPerWeek;
//    }
//};
//
//class OfflineCourse : public Course {
//private:
//    int months;
//    int hoursPerDay;
//
//public:
//    OfflineCourse(int m, int hpd) : months(m), hoursPerDay(hpd) {}
//
//    int duration() const override {
//        // assuming 30 days per month
//        return months * 30 * hoursPerDay;
//    }
//};
//
//int main() {
//    OnlineCourse online(6, 5);
//    OfflineCourse offline(2, 3);
//
//    cout << "Online course duration:  " << online.duration() << " hours" << endl;
//    cout << "Offline course duration: " << offline.duration() << " hours" << endl;
//
//    return 0;
//}