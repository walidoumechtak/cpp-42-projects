#include "ReplaceFile.hpp"

int main(int ac, char **av)
{
    (void)ac;
    ReplaceFile rep(av[1], av[2], av[3]);
    rep.ft_replace();
    rep.close_files();
}