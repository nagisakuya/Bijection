#include "Bijection.h"

using namespace std;

namespace nagisakuya {
	namespace Bijection {
		template<class F, class S>
		bijection<F, S>::bijection(initializer_list<pair < F, S >> input) {
			for (auto i : input)
			{
				add(i);
			}
		}
		template<class F, class S>
		void bijection<F, S>::add(pair<F, S> input)
		{
			emplace(input.first, input.second);
		}
		template<class F, class S>
		inline void bijection<F, S>::emplace(F first, S second)
		{
			f[first];
			s[second] = f.find(first);
			f[first] = s.find(second);
		}
		template<class F, class S>
		size_t bijection<F, S>::size()
		{
			return f.size();
		}
		template<class F, class S>
		F bijection<F, S>::find_first(S input)
		{
			return f.find(input).first;
		}
		template<class F, class S>
		S bijection<F, S>::find_second(F input)
		{
			return f.find(input).second;
		}
	}
}