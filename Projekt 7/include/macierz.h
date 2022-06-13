#ifndef MACIERZ_H
#define MACIERZ_H

#include <vector>
namespace AiSD{
    /*
        Nie mialem pomyslu jak macierz stawic do funckcji,
        Pana kod mi pomogl pisaniu tego kodu
    */
    using dim_t=size_t;
    using cost_t=size_t;
    using pos_t=size_t;
    using dim_arr =std::vector<dim_t>;
    using cost_arr =std::vector<std::vector<cost_t>>;
    using pos_arr = std::vector<std::vector<pos_t>>;

    cost_t MatrixChainRecursive(const dim_arr& dim,cost_arr& cost, pos_arr& bracket_pos, size_t i,size_t j);
    void MatrixChainResursive1 (const dim_arr& dim,cost_arr& cost, pos_arr& bracket_pos);
    void MatrixChainOrder(const dim_arr& dim, cost_arr& cost, pos_arr& bracket_pos);
    void Print(const pos_arr& bracket_pos,size_t i,size_t j);

    void calculateMatrixMemory();
    void calculateMatrix();
}

#endif // MACIERZ_H
