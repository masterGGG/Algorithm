#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目 的宣讲。 
给你每一个项目开始的时间和结束的时间(给你一个数 组，里面 是一个个具体的项目)，你来安排宣讲的日程，
要求会 议室进行 的宣讲的场次最多。返回这个最多的宣讲场次。
*/

class Meeting {
public:
    int id;
    int start;
    int end;
    Meeting(int i, int s, int e) : id(i), start(s), end(e) {}
};

struct earlier {
    bool operator() (Meeting a, Meeting b) {
        return a.end > b.end;
    }
};
/*
void Show(priority_queue<Meeting, vector<Meeting>, earlier> arr) {
    for (auto s : arr) {
        cout << "Id " << s.id << " range " << s.start << "-" << s.end << endl;
    }

    cout << endl;
}
*/
//rm code* && rz && g++ code_06.cpp  -o xxx -std=c++11 -g && ./xxx
int main() {
    vector<int> start = {1, 3, 6, 5, 6, 11, 15, 17, 21};
    vector<int> end = {4, 5, 9, 6, 7, 14, 18, 19, 23};

    priority_queue<Meeting, vector<Meeting>, earlier> arr;

    for (int i = 0; i < start.size(); ++i) {
        arr.emplace(Meeting(i + 1, start[i], end[i]));
    }

    //Show(arr);

    int cur = 0;

    while (!arr.empty()) {
        Meeting tmp = arr.top();
        arr.pop();

        if (tmp.start >= cur) {
            cout << "Arrange Meetting " << tmp.id << " range " << tmp.start << "-" << tmp.end << endl;
            cur = tmp.end;
        } else {
            cout << "Id " << tmp.id << " range " << tmp.start << "-" << tmp.end << endl;
        }
    }

    return 0;
}