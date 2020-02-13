#pragma once
#include <list>
class ArmorFilter {
public:
	ArmorFilter(int _filter_size = 5)
		: filter_size(_filter_size) {}

    void clear(){
        history.clear();
    }

    bool getResult(bool is_small){
        if (history.size() < filter_size){
            history.push_back(is_small);
        }
        else {
            history.push_back(is_small);
            history.pop_front();
        }

        int vote_cnt[2] = {0};
        for (std::list<bool>::const_iterator it = history.begin(); it != history.end(); ++it){
            *it == 0 ? ++vote_cnt[0] : ++vote_cnt[1];
        }

        if (vote_cnt[0] == vote_cnt[1])
            return is_small;
        return vote_cnt[0] > vote_cnt[1] ? 0 : 1;
    }

private:
	std::list<bool> history;
	int filter_size;
};

class Filter1D {
public:
    Filter1D(int _filter_size = 5){
        filter_size = _filter_size;
    }
    void setRecord(double record){
        if (history.size() < filter_size){
            history.push_back(record);
            return;
        }
        history.push_back(record);
        history.pop_front();
    }

    double getResult(){
        double value = 0.0;
        for (std::list<double>::const_iterator it = history.begin(); it != history.end(); ++it){
            value += *it;
        }
        return value/history.size();
    }
private:
    std::list<double> history;
    int filter_size;
};


class FilterZ {
public:
    FilterZ(double _update_rate, double _max_change_value = 20.0){
        update_rate = _update_rate;
        max_change_value = _max_change_value;
        res = 0.0;
    }
    double getResult(double record) {
        if (res < 10e-5 ){
            res = record;
            last_value = record;
            return res;
        }
        if (record - last_value > max_change_value)
            record = last_value + max_change_value;
        else if (last_value - record> max_change_value)
            record = last_value - max_change_value;

        res = res * (1.0 - update_rate) + update_rate * record;
        last_value = record;
        return res;
    }
    void clear(){
        res = 0.0;
    }
private:
    double max_change_value;
    double update_rate;
    double last_value;
    double res;
};
