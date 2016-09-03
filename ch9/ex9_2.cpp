#include <vector>

using std::vector;

vector<int>::const_iterator contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value)
{
	for(; first != last; ++first)
	{
		if(*first == value)
		{
			return first;
		}
	}
	return last;
}