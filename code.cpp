#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
int main()
{
    vector <int> ten;
    vector <int> tso;
    int test_case;
    int n_tso,n_ten;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> n_tso;
        cin >> n_ten;

        for (int i = 0; i < n_tso; i++)
        {
            int ability;

            cin >> ability;
            tso.push_back(ability);
        }
        for (int i = 0; i < n_ten; i++)
        {
            int ability;

            cin >> ability;
            ten.push_back(ability);
        }

        int inc;

        if (tso.size() - ten.size() <= 0)
            inc = tso.size();
        else
            inc = ten.size();
        //------------------------------------------------
        for (int j = 0; j < inc ; )
        {
            if (ten.size() == 0 || tso.size() == 0)
                break;
            int diff1 = ten.at(0) - tso.at(0);
            int diff2 = tso.at(0) - ten.at(0);
            
            if (diff1 <= 0)
                ten.erase(ten.begin());
            else
                ten.at(0) = diff1;

            if (diff2 <= 0)
                tso.erase(tso.begin());
            else
                tso.at(0) = diff2;
            
            if (tso.size() - ten.size() <= 0)
                inc = tso.size();
            else
                inc = ten.size();
            j = 0;
        }

        if (ten.size() > tso.size())
            cout << "Tenzing" << endl;
        else if (tso.size() > ten.size())
            cout << "Tsondu" << endl;
        else
            cout << "Draw" << endl;
        tso.clear();
        ten.clear();
    }


    return (0);
}