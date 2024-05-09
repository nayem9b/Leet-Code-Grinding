#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxGrade(vector<pair<int, int>>& courses, vector<pair<int, int>>& students) {
    int max_final_grade = 0;

    for (auto& student : students) {
        int final_grade = 0;
        for (int i = student.first - 1; i < student.second; ++i) {
            final_grade |= courses[i].second;
        }
        max_final_grade = max(max_final_grade, final_grade);
    }

    return max_final_grade;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> courses(n);
        for (int i = 0; i < n; ++i) {
            cin >> courses[i].first >> courses[i].second;
        }

        int q;
        cin >> q;

        vector<pair<int, int>> students(q);
        for (int i = 0; i < q; ++i) {
            cin >> students[i].first >> students[i].second;
        }

        cout << maxGrade(courses, students) << " ";
    }

    return 0;
}
