class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        int cal= (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
        if(cal==1)
        return "Monday";
        if(cal==2)
        return "Tuesday";
        if(cal==3)
        return "Wednesday";
        if(cal==4)
        return "Thursday";
        if(cal==5)
        return "Friday";
        if(cal==6)
        return "Saturday";
        if(cal==0)
        return "Sunday";
        return "";
        
    }
};