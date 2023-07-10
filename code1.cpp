#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;
int main()
{
    stack <int> s1;
    stack <int> s2;
    stack <int> s3;
    int test_case;
    int number_of_book;
    int x;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> number_of_book;
        cin >> x;

        for (int i = 0; i < number_of_book; i++)
        {
            int rating;

            cin >> rating;
            s1.push(rating);
        }
        cin.clear();
        for (int i = 0; i < number_of_book; i++)
        {
            int rating;

            cin >> rating;
        
            s2.push(rating);
        }
        cin.clear();
        for (int i = 0; i < number_of_book; i++)
        {
            int rating;

            cin >> rating;
            //cout << "rating " << rating << endl;
            s3.push(rating);
        }

        // -----------------------  end of init data ----------------------------
        int know = 0;
        int flag = 0;
        // cout << "s1 " << s1.top() << endl;
        // cout << "s2 " << s2.top() << endl;
        // cout << "s3 " << s3.top() << endl;
        for (; know < x;)
        {
            cout << "x : " << x << " know " << know << endl;
            //cout << "s1 : " << (know | s1.top()) << endl;
            if ((know | s1.top()) <= x)
            {
                flag = 1;
                know = (know | s1.top());
                //cout << "s1 " << know << endl;
                s1.pop();
            }
            //cout << "s2 : " << (know | s2.top()) << endl;
            if ((know | s2.top()) <= x)
            {
                flag = 1;
                know = (know | s2.top());
                //cout << "s2 " << know << endl;
                s2.pop();
            }
            //cout << "s3 : " << (know | s3.top()) << endl;
            if ((know | s3.top()) <= x)
            {
                flag = 1;
                know = (know | s3.top());
               // cout << "s3 " << know << endl;
                s3.pop();
            }
            if (flag == 0)
                break;
        }
        if (know == x)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return (0);
}