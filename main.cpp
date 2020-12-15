#include"program.h"

int main()
{
	Program p;
	std::ifstream in("text.txt");
	p.read(in, p.p_list);

	p.p_vector = p.find_(p.p_list, 'O', 1);
	p.print(cout, p.p_vector);
	cout << std::endl;

	size_t temp;
	temp = p.count_larger(p.p_list, "muffin");
	cout << temp << std::endl;


	return 0;
}