#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Time {
public:
    int hour;
    int min;
    
    Time plus(Time b) {
        Time result = {this->hour + b.hour, this->min + b.min};
        return result;
    }
    Time minus(Time b) {
        Time result = {this->hour - b.hour, this->min - b.min};
        return result;
    }
    bool equal(Time b) {
        return this->hour == b.hour && this->min == b.min;
    }
};

class Record {
public:
    Time in;
    Time total;
    int car;
    int price;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<Record> rrecord = vector<Record>();
    for (int i = 0; i < records.size(); i++) {
        Time time;
        int car;
        char str[3];
        sscanf(records[i].c_str(), "%2d:%2d %4d %2s", &time.hour, &time.min, &car, str);
        int j;
        for (j = 0; j < rrecord.size(); j++) {
            if (rrecord[j].car == car) {
                if (str[0] == 'I') {
                    rrecord[j].in = time;
                }
                else {
                    rrecord[j].total = rrecord[j].total.plus(time.minus(rrecord[j].in));
                    rrecord[j].in = {-1, -1};
                }
                break;
            }
        }
        if (j == rrecord.size()) {
            if (str[0] == 'I') {
                rrecord.push_back({time, {0, 0}, car});
            }
        }
    }
    for (int j = 0; j < rrecord.size(); j++) {
        if (!rrecord[j].in.equal(Time {-1, -1})) {
                rrecord[j].total = rrecord[j].total.plus(Time {23, 59}.minus(rrecord[j].in));
        }
    }
    for (int j = 0; j < rrecord.size(); j++) {
        rrecord[j].price = fees[1];
        int min = rrecord[j].total.hour * 60 + rrecord[j].total.min;
        min -= fees[0];
        if (min > 0) {
            rrecord[j].price += (min / fees[2] + (min % fees[2] > 0 ? 1 : 0)) * fees[3];
        }
    }
    sort(rrecord.begin(), rrecord.end(), [](Record x, Record y)->bool{return x.car < y.car;});
    vector<int> result = vector<int>(rrecord.size());
    for (int i = 0; i < result.size(); i++) {
        result[i] = rrecord[i].price;
    }
    return result;
}