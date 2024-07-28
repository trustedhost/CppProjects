#include <iostream>
#include <fstream>

#include "utils.h"

using namespace MyExcel;

int main() {
    MyExcel::TxtTable table(5, 5);
    table.reg_cell(new NumberCell(2, 1, 1, &table), 1, 1);
    table.reg_cell(new NumberCell(3, 1, 2, &table), 1, 2);

    table.reg_cell(new NumberCell(4, 2, 1, &table), 2, 1);
    table.reg_cell(new NumberCell(5, 2, 2, &table), 2, 2);
    table.reg_cell(new ExprCell("B2+B3*(C2+C3-2)", 3, 3, &table), 3, 2);
    table.reg_cell(new StringCell("B2 + B3 * ( C2 + C3 - 2 ) = ", 3, 2, &table), 3, 1);

    std::cout << table;
}
