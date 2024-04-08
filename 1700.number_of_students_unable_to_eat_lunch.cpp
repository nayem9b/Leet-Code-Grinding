class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res = students.size();
        unordered_map<int, int> counter;

        for (int student : students)
            counter[student]++;

        for (int sandwich : sandwiches) {
            if (counter[sandwich] > 0) {
                res--;
                counter[sandwich]--;
            } else {
                return res;
            }
        }

        return res;
    }
};
