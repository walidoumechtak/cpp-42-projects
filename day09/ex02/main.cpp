#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::vector<int>    vector_data;
        std::deque<int>     deque_data;
        clock_t start;
        clock_t end;
        try
        {
            // ================================ The vector case.
            parseTheInput(av, ac);
            fillTheData(vector_data, av, ac);
            std::cout << "before:\t";
            print(vector_data); // print data before sorting.
            start = clock();
            vector_data = run(vector_data);
            end = clock();
            double time = (end - start);
            std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> : " << (time / CLOCKS_PER_SEC) << " s" << std::endl;
            // ================================ Deque case.
            parseTheInput(av, ac);
            fillTheData(deque_data, av, ac);
            std::cout << "before:\t";
            print(deque_data); // print data before sorting.
            start = clock();
            deque_data = run(deque_data);
            end = clock();
            time = (end - start);
            std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int> : " << (time / CLOCKS_PER_SEC) << " s" << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "Check you arguments please!!" << std::endl;
        return 1;
    }
    return 0;
}